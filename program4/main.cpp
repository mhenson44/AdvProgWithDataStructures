/*
Name: Michael Henson
Date: 03/30/21
Class: csc1720
Path: ~/mhenson/csc1720/program4/main.cpp

Grade Level: 90%

Desc: Writing a recursive function called Repower that takes as parameters two integer values, j and k, and returns the base j raised
to the power of k, jk.

how to execute:

g++ *.cpp
./a.out

*/

#include<iostream>
#include<string>
#include"invalidPower.h"

using namespace std;

int Repower(int j, int k);
//int reEnter(int j);

int main()
{
//base and power integers
   int j,k;
//try block
try
{ 
   cout << "Enter in base value for j: " << endl;
   //while loop to check make sure user doesn't enter a negative; 
   //if they do they reenter a value
   while(cin >> j && j < 0)
      {
         cout << "The base must be positive, try again: " << endl;
      }
   cout << endl;
   cout << "Enter in power u want j to be raised to (aka k...): " << endl;
   cin >> k;
   cout << endl;

   cout << j << " raised to the power " << k << " is " << Repower(j,k);
   cout << endl; 

//   throw invalidPower();
}
//catch blocks
catch (invalidPower invalidPowerobj)
{
   cout << "message: " << invalidPowerobj.what() << endl;
}
return 0;
}
/*Repower Function
 function: that takes as parameters two integer values, j and k, and returns the base j raised to the power of k, jk.

   pre: sets values for Repower based off of k
   post:says if k = 0, Repower = 1, k = 1, Repower = j, and k > 1, Repower =j times Repower function
*/
int Repower(int j, int k)
{
   {
   if (k == 0)
      return 1;
   else if
       (k == 1)
         return j;
   else if
      (k > 1)
         return (j*Repower(j,k-1));
   }
   return false;
}
/*
didn't use this
int reEnter(int j)
do {
   j = message
   }
   return j;
}
*/
