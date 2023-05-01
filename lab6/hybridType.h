/* Name: Michael Henson
   Date:02/21/2021
   Class:Csc1720
   Location:~/csc1720/lab6/hybridType.h

   Desc:implementation file for auto and hybrid

   To compile, use command:
      g++ -Wall autoMain.cpp autoType.cpp hybridType.cpp     
   To execute, use command
      ./a.out

   this is the header file for the derived autoType class: hybridType
   hybridType is a type of autoType, in which it has two more 
   private instance variable,
                 the amount of charge in its batteries --> chargeLevel
                 and the battery/charge efficiency --> chargeEff
*/
#include<iostream>
#include "autoType.h"
using namespace std;

#ifndef HYBRID_TYPE
#define HYBRID_TYPE

class hybridType: public autoType
{
   private:
      double chargeLevel;
      double chargeEff;
   public:
     /*
      setChargeLevel - use to update the private instance variable
                       chargeLevel of a hybridType.  
                       Max change level is 100%.
      pre-conditions: parameter must be a double in percent form
      post-conditions: chargeLevel = chargeLevel_in
      */
      void setChargeLevel(double chargeLevel_in);

     /*
      getChargeLevel - use to "get" the value of chargeLevel 
                       when it is not directly available
                       ((when outside the class))
      post-conditions: returns chargeLevel in percent form
      */
      double getChargeLevel(void)const;

     /*
      setChargeEfficiency - use to update the private instance variable
                            chargeEff of a hybridType
      pre-conditions: parameter must be a double
      post-conditions: chargeEff = chargeEff_in
      */
      void setChargeEfficiency(double chargeEff_in);

     /*
      getChargeEfficiency - use to "get" the value of chargeEff
                            when it is not directly available 
                            ((outside the class))
      post-conditions: returns chargeEff
      */
      double getChargeEfficiency()const;

      string getAutoSpecs(void)const;

      hybridType();

      hybridType(double od_in, double fc_in, double fl_in, double mpg_in, double chargeLevel_in, double chargeEff_in);

      void drive(double distance);
};

#endif
