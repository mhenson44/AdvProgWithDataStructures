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
#define EPSILON 0.0001
using namespace std;

class vectorType
{
   //private members
   private:
      double X;
      double Y;
      double Z;
   //public members
      double scal;
   public:
      double getX()const;
      double getY()const;
      double getZ()const;
      void setComps(double len, double wid, double hei);       
      vectorType(double len, double wid, double hei);
      vectorType();
      void setScale(double scal_in);
      double getScale(void)const;
      void printVector();
      double calcMagnitude();
      void scalarMultiply();
      vectorType addVector(vectorType R)const;
      vectorType subVector(vectorType R);
      vectorType unitVector();
      double dotProduct(vectorType R)const;
      vectorType crossProduct(vectorType R)const;
      bool equalVector(vectorType R) const;
};
#endif
