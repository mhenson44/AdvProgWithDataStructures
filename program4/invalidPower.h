/*
Name: Michael Henson
Date: 03/30/21
Class: csc1720
Path: ~/mhenson/csc1720/program4/invalidPower.h

Grade Level: 90%

Desc: Writing a recursive function called Repower that takes as parameters two integer values, j and k, and returns the base j raised
to the power of k, jk.
*/

#include<iostream>
#include<string>

using namespace std;

#define INVALID_POWER

class invalidPower
{
   public:
      invalidPower()
      {
         message = "The base must be positive... Try again :/";
      }
      invalidPower(string str)
      {
         message = str;
      }
      string what()
      {
         return message;
      }
   private:
      string message;
};

