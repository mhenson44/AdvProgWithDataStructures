/*  Name: Michael Henson
   Date:02/21/2021
   Class:Csc1720
   Location:~/csc1720/lab6/hybridType.h

   Desc:implementation file for auto and hybrid

   To compile, use command:
      g++ -Wall autoMain.cpp autoType.cpp hybridType.cpp     
   To execute, use command
      ./a.out
   Implementation file for the derived class autoType:  
   Includes set, get, and simple mutator methods.
*/

#include"hybridType.h"
#include<iomanip>
#include<sstream>

void hybridType::setChargeLevel(double chargeLevel_in)
{
   if (chargeLevel_in > 0.0 && chargeLevel <= 100.0)
      chargeLevel = chargeLevel_in;
   else
      cerr << "Charge level must be > 0% and <= 100%" << endl;
}

double hybridType::getChargeLevel(void)const
{
   return chargeLevel;
}

void hybridType::setChargeEfficiency(double chargeEff_in)
{
   if (chargeEff_in > 1.0)
      chargeEff = chargeEff_in;
   else
      cerr << "Charge efficiency must be > 1.0" << endl;
}

double hybridType::getChargeEfficiency()const
{
   return chargeEff;
}

string hybridType::getAutoSpecs() const
{
   string auto_type_return = autoType::getAutoSpecs();
   ostringstream sout;
   sout << fixed << showpoint << setprecision(2);
   sout << endl << "Charge Level = " << chargeLevel << "%";
   sout << ", Charge Efficency = " << chargeEff;
   return auto_type_return + sout.str();   
}

hybridType::hybridType()
   :autoType()
{
   double chargeLevel_in = 100;
   double chargeEff_in = 1;

   autoType:;
   chargeLevel = 100;
   chargeEff = 1;
   if (chargeLevel_in <= 100 && chargeLevel_in >= 0)
      chargeLevel = chargeLevel_in;
   if (chargeEff_in > 1)
      chargeEff = chargeEff_in;
}

hybridType::hybridType(double od_in, double fc_in, double fl_in, double mpg_in, double chargeLevel_in, double chargeEff_in)
            :autoType(od_in, fc_in, fl_in, mpg_in)
{
   chargeLevel = 100;
   chargeEff = 1;
   if (chargeLevel_in <= 100 && chargeLevel_in >= 0)
      chargeLevel = chargeLevel_in;
   if (chargeEff_in > 1)
      chargeEff = chargeEff_in;
}

void hybridType::drive(double distance)
{
//cannot drive a negative distance
   if (distance < 0)
   {
      cerr << "Cannot drive negative miles." << endl;
      return;
   }
   double max_distance = 0;
   if (chargeLevel - 20 > 0)
   {
      max_distance = chargeEff * (chargeLevel - 20);
      if (distance<=max_distance)
      {
         odometer += distance;
         chargeLevel -= distance / chargeEff;
      }
      else
      {
         cerr << "Hit 20% charge minimum after " << max_distance << " miles of electric driving."<<endl;
         chargeLevel -= max_distance / chargeEff;
         odometer += max_distance;
         if (distance-max_distance< fuelLevel * mpg)
         {
            chargeLevel += (distance - max_distance) / 20;
            if (chargeLevel > 100)
            {
               chargeLevel = 100;
            }
         }
         else
         {
            chargeLevel += (fuelLevel * mpg) / 20;
            if (chargeLevel>100)
            {
               chargeLevel = 100;
            }

         }
         autoType::drive(distance - max_distance);
         
      }
   }
   else
   {
      autoType::drive(distance);
      double gas_dist = fuelLevel * mpg;
      chargeLevel = chargeLevel + gas_dist / 20;
   }
}
         
