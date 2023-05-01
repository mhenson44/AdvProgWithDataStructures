/* Name:
   Date:
   Class:
   Location:

   Add your own purpose of this file
   how to compile g++ autoType.cpp autoMain.cpp
*/

#include"autoType.h"
#include<iomanip>
#include<sstream>

autoType::autoType(double od_in, double fl_in, double mpg_in, double cap_in)
{
   odometer=fuelLevel=mpg=0;
   fuelCap = 20;
   setAutoSpecs(od_in, fl_in, mpg_in);
}


void autoType::setAutoSpecs(double od_in, double fl_in, double mpg_in)
{
   bool invalid = false;   
      {
      od_in >= odometer;
      fl_in <= fuelCap;
      mpg_in >= 1;
      fl_in > 0;
      }
}


string autoType::getAutoSpecs(void)const
{
   ostringstream sout;

   sout << fixed << showpoint << setprecision(2);
   sout << "Miles = " << odometer;
   sout << ", Fuel Capacity = " << fuelCap;
   sout << ", Fuel Level = " << fuelLevel;
   sout << ", Efficiency = " << mpg;

   return sout.str();
}

      
void autoType::drive(double distance)
{
   //Determine the max dist you can travel 
   //based on the current fuelLevel.
   //Compare the requested distance to maxDistance
   //to see if that is possible and act accordingly.
   double maxDistance = fuelLevel*mpg; 
   if(distance <= maxDistance) {
      odometer += distance;
      fuelLevel -= distance/mpg;
   } else {
      cerr << "Out of gas after " << maxDistance << " miles." << endl;
      odometer += maxDistance;
      fuelLevel = 0;
   }
}

void autoType::fuelCap(double cap)
{
   cap = fuelCap
   if(cap > 0)
      cap = cap;
}

void autoType::addFuel()
{
  double tank;
   tank += fuelLevel;
} 
