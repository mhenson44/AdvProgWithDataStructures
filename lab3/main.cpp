/* Author:
   Date: 
   Class: CSC-1720
   Code location:
   
   About: 
   This program will process a file containing the information about
   the employees. MAX will indicate the maximum number that can be
   processed.  Sample data file named "employeeDB":

   Sam 24 12345.62892
   Mary 19 103234.35345
   Mickey 52 203402
   Alice 43 10203.27003

   The output should be formated as follows with the salary 
   rounded to two decimal places.

   Name        Age       Salary
   Sam          24     12345.63
   Mary         19    103234.35
   Mickey       52    203402.00
   Alice        43     10203.27

   To compile:
      g++ -Wall main.cpp empType.cpp -o processEmployee 

   Create a data file named "employeeDB" containing the sample data 
   from above with some additions.

   NOTE: the load functions opens/closes the file employeeDB for processing.
         the dump function outputs to the screen (stdout).

   To execute:
      ./processEmployee

*/

#include<iostream>
#include<fstream>
#include<iomanip>
#include"empType.h"

using namespace std;

#define MAX 100

//prototypes
void load(empType E[], int &n);
void dump(empType E[], int n);
void shellSort(empType E[], int n);
bool shellPass(empType E[], int n, int gap);
void exchange(empType &a, empType &b);


int main()
{
   empType employeeDB[MAX];
   int n;  

   load(employeeDB, n);
   cout << "Unsorted EmployeeDB"<< endl;
   dump(employeeDB, n);
   shellSort(employeeDB, n);
   cout << endl;
   cout << "Sorted EmployeeDB"<< endl;
   dump(employeeDB, n);

   return 0;
}

/*
   load - read in data about all employes, name, age, and salary.
   Store the data in an array to be later processed.  The data
   will be loaded into positions 0 through (num employees - 1)
   We are reading from the keyboard so I/O redirection is recommended.
   pre-condition: The empType array references an array that can
                  be loaded with the employee data.  cnt will 
                  initialy be set to 0 but will reflect the total
                  number of employees in the end.
   post-condition: The empType array will be loaded with all 
                   data found in the file or upto MAX 
   Assumption: If the employee's name can be read, we'll assume
               that their age and salary, id follow.

*/
void load(empType E[], int &cnt)
{
   ifstream inFile;

   inFile.open("employeeDB_withID");
   if(inFile.fail()) {
      cerr << "Error: Could not open the file" << endl;
      exit(1);
   }
   cnt = 0;
   string name;
   int age;
   double salary;
   int id;
   inFile >> id >> name >> age >> salary;   
   while(!inFile.eof() && cnt < MAX) {
      E[cnt].setid(id);
      E[cnt].setName(name);
      E[cnt].setAge(age);
      E[cnt].setSalary(salary);
      cnt++;
      inFile >> id >> name >> age >> salary;   
   }    
   inFile.close();
}

/*
   dump - output the contents of an empType array containing n elements
          to stdout.  Consider using I/O redirection.
   pre-condition: Array E is loaded with employee data for n employees.
   post-condition: No changes will be made to the array.
*/
void dump(empType E[], int n)
{
   cout << fixed << showpoint;
   cout << left << setw(10) << "ID";
   cout << left << setw(10) << "Name";
   cout << right << setw(5) << "Age";
   cout << right << setw(13) << "Salary" << endl;
   
   for(int i=0;i<n;i++) {
      cout << left << setw(10) << E[i].getid();
      cout << left << setw(10) << E[i].getName();
      cout << right << setw(5) << E[i].getAge();
      cout << right << setw(13) << setprecision(2) << E[i].getSalary();
      cout << endl;
   }
}
/*
shellSort - Initializes gap to sort through all elements in the array, comparingelements.
pre-condition: array E loads in a gap, which is divided by 2 to find out which 
how many elements are compared
post-condition: elements are arranged in ascending order using gap to compare 
them.
*/
void shellSort(empType E[], int n)
{
   int gap = n/2;
   while (gap!=0)
      if (shellPass(E, n, gap))
         gap/=2;
}
/*
shellPass - Make pass through all elements in the array comparing
elements to find the smallest using gap. This function is dependent on being
repeatedly called from shellSort.
pre-condition: Some elements at the top of the array may be in the correct
ascending order position.
post-condition: One element will move into correct position for an ascending
ordering.
*/
bool shellPass(empType E[], int n, int gap)
{
   bool same = true;
   for(int j=0; j<n-gap; j++)
      if(E[j].getid() > E[j+gap].getid())
      {
         exchange(E[j], E[j+gap]);
         same = false;
      }
   return same;
}
/*
exchange - Swap the instances of a and b
pre-condition: a and b contain references to empType.
post-condition: the value of the empTypes of a is placed into b and b into a.
*/
void exchange(empType &a, empType &b)
{
   empType temp;
   temp = a;
   a = b;
   b = temp;
}

         
