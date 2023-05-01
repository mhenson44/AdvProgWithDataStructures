#include<iostream>
#include<string>

using namespace std;
#define INVALID_DAY
class invalidDay
{
   public:
      invalidDay()
      {
         message = "Invalid Date, try again.";
      }
      invalidDay(string str)
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
