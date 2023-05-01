/* 
   Author:
   Date:
   Class: CSC-1720
   Code location:
   
   About: 
*/

#include"empType.h"
// sets name of the employee
void empType::setName(string iname)
{
   name = iname;
}

// sets age of the employee
void empType::setAge(int iage)
{
   age = iage;
}
//sets salary of the employee
void empType::setSalary(double isalary)
{
   salary = isalary;
}
//returns the input value of name
string empType::getName(void) const
{
   return name;
}

//returns the input value of age
int empType::getAge(void) const
{
   return age;
}

//returns the input value of salary
double empType::getSalary(void) const
{
   return salary;
}
//sets the value of the id
void empType::setid(int eid)
{
   id = eid;
}
//returns the input value of id
int empType::getid() const
{
   return id;
}
//Constructor with passed parameters
empType::empType(int eid, string iname, int iage, double isalary)
{
   if (iname == " ")
      cerr << "Error Message";
   iname = name;
   if (iage <= 18)
      cerr << "Error with given input";
   iage = age;
   if (eid < 0)
      cerr << "ID must be a positive value!";
   eid = id;
   if (isalary < 0)
      cerr << "salary must be a positive value!";
   isalary = salary;
}
//Default Constructor 
empType::empType()
{
   id = 0;
   age = 0;
   salary = 0;
   name = " ";
}
   
