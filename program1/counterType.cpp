/*
   Name:Michael Henson  
   Class:Csc1720
   Date:01/26/20201
   Path:~/mhenson/csc1720/program1/counterType.cpp

   Desciption:implementation file with public and private variables for the header and main program
*/

#include "counterType.h"
#include<iostream>

using namespace std;
// initializes counter as starting point of 0
void counterType::initializeCounter()
{
   counter = 0;
}
// sets counter value and makes it so counter can't have a number under 0 such as a negative
void counterType::setCounter(int x)
{
   counter = x;
   if(counter <0)
      initializeCounter();
}
// returns value of counter
int counterType::getCounter() const
{
   return counter;
}
//increments counter by 1
void counterType::incrementCounter()
{
   counter ++;
}
//decrements counter by 1
void counterType::decrementCounter()
{
   counter--;
   if (counter < 0)
      initializeCounter();
}
//displays the output on the screen
void counterType::displayCounter() const
{
   cout << counter;
}
//same as setCounter
counterType:: counterType(int x)
{
   setCounter(x);
}
//default constructor
 counterType::counterType()
{
   initializeCounter();
}
