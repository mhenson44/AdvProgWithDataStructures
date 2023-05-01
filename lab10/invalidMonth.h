#include<iostream>
#include<string>

using namespace std;
#define INVALID_Month

class invalidMonth
{
   public:
      invalidMonth()
      {
         message = "Invalid Month, try again.";
      }
      invalidMonth(string str)
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
~                       
