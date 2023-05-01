/*
 Author: Michael Henson
   Class: csc1720
   Date: 02/02/2021
   Path: ~/mhenson/csc1720/lab4/vectorType.cpp

   Desc:implementation file
   
*/

#include"vectorType.h"
#include<cmath>
//returns value of X
double vectorType::getX() const
{
   return X;
}

//returns value of Y
double vectorType::getY() const
{
   return Y;
}
//returns the value of Z
double vectorType::getZ() const
{
   return Z;
}
//set all 3 vectorcomponents at once
void vectorType::setComps(double x, double y, double z)
{
   X = x;
   Y = y;
   Z = z;
}
//paramerized constructor
vectorType::vectorType(double x, double y, double z)
{
   X = x;
   Y = y;
   Z = z;
}
//default constructor
vectorType::vectorType()
{
   X = 0;
   Y = 0;
   Z = 0;   
}
//print function
void vectorType::printVector()
{
   cout << fixed << showpoint << setprecision(4) <<endl;
   cout << " <" << X << "," << Y << "," << Z << ">"; 
}
/*double vectorType::calcMagnitude()
{
   double magnitude;
   magnitude = sqrt(X*X + Y*Y + Z*Z);
   
   return magnitude;
}
double vectorType::scalarMultiply(double S, double P)
{
   P = S*P;

   return S;
}
*/
