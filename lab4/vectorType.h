/*
   Author: Michael Henson
   Class: csc1720
   Date: 02/02/2021
   Path: ~/mhenson/csc1720/lab4/vectorType.h
   
   Desc: 
*/


#ifndef VECTOR_TYPE
#define VECTOR_TYPE

#include<iostream>
#include<iomanip>

using namespace std;

class vectorType
{
   //private members
   private:
      double X;
      double Y;
      double Z;
   //public members
   public:
      double getX()const;
      double getY()const;
      double getZ()const;
      void setComps(double x, double y, double z);       
      vectorType(double x, double y, double z);
      vectorType();
      void printVector();
      double calcMagnitude();
      double scalarMultiply(double S, double P);
};
#endif
