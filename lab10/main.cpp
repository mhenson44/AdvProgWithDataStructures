#include <string>
#include"invalidDay.h"
#include"invalidMonth.h"

using namespace std;

double checkLeap(int year);

int main()
{

   int month, day, year;

try
{

   cout << "Enter your date of birth in this format   mm-dd-yyyy: ";
   cin >> month >> day >> year;
   cout << endl;

    if (day > 31) 
            throw invalidDay();  

        
        if(month==1)
        cout << "January ";
    else
        if(month==2)
         {
        cout << "February ";
         checkLeap(year);
         }
    else
        if(month==3)
        cout << "March ";
    else
        if(month==4)
        cout << "April ";
    else
        if(month==5)
        cout << "May ";
    else
        if(month==6)
        cout << "June ";
    else
        if(month==7)
        cout << "July ";
    else
        if(month==8)
        cout << "August ";
    else
        if(month==9)
        cout << "September ";
    else
        if(month==10)
        cout << "October ";
    else
        if(month==11)
        cout << "November ";
    else
        if(month==12)
        cout << "December ";
    else 
        if (month > 12)
    throw invalidMonth();

    }

catch(invalidDay obj)
{
   cout << "message: " << obj.what() << endl;
}

catch(invalidMonth obj)
{
   cout << "message: " << obj.what() << endl;
}


cout << month << "-"<< day << "-" << year<<endl;
}

double checkLeap(int year)
  { 
    if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0)
                    cout << year << " is a leap year.";
                else
                    cout << year << " is not a leap year.";
            }
            else
                cout << year << " is a leap year.";
        }
        else
            cout << year << " is not a leap year.";
        
        return 0;
  }
  
    
