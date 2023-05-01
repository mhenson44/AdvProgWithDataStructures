#ifdef AUTO_HYBRID
#define AUTO_HYBRID

#include<iostream>
#include"autoType.h"

using namespace std;

class hybridType: public autoType
{
   private:
      double chargeLevel;
      double chargeEff;
      bool engineMode;
   public:
      static const bool GAS = true;
      static const bool ELECTRIC = false;

      void setChargeLevel(int charge_in);
      double getChargeLevel();
      void setChargeEfficency(int chargeEff_in);
      double getChargeEfficency();
}
#endif
