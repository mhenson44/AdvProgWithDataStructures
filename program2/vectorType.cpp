/*
 Author: Michael Henson
   Class: csc1720
   Date: 02/02/2021
   Path: ~/mhenson/csc1720/lab4/vectorType.cpp

   Desc:implementation file
   
*/

#include"vectorType.h"
#include<cmath>
#define EPSILON 0.0001
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
void setScale(double scal);void vectorType::setComps(double len, double wid, double hei)
{
   len = X;
   wid = Y;
   hei = Z;
}
//paramerized constructor
vectorType::vectorType(double len, double wid, double hei)
{
   X = len;
   Y = wid;
   Z = hei;
}
//sets scaler variable
void vectorType::setScale(double scal_in)
{
   scal = scal_in;
}
//returns value of scaler
double vectorType::getScale(void)const
{
   return scal;
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
/* calculates magnigtude of the two vectors
*/
double vectorType::calcMagnitude()
{
  double magnitude;
  magnitude = sqrt(X*X + Y*Y + Z*Z);
   
  return magnitude;

}
//times the scalar by the values
void vectorType::scalarMultiply()
{
   X = scal*X;
   Y = scal*Y;
   Z = scal*Z;
}
/*
   pre:define the addition of two vectors P and Q
   post:sum of the two vectors
*/

vectorType vectorType::addVector(vectorType R)const
{
  vectorType V1(X + R.getX(), Y + R.getY(), Z + R.getZ());
   
   return V1;   

}
/*
   pre: define the subtraction of 2 vectors
   post: difference of the two vectors
*/

vectorType vectorType::subVector(vectorType R)
{
  vectorType V1(X - R.getX(), Y - R.getY(), Z - R.getZ());

   return V1;
}
/*- A unit vector is a vector whose length is 1.
   post: Vector P may be converted to a
unit vector by scaling it by 1 / (its own length
*/
vectorType vectorType::unitVector()
{
   vectorType U;
   double mag = calcMagnitude();
   
   U.setComps(X/mag, Y/mag, Z/mag);

   return U;
}

/*
   pre: The dot product of two vectors P and Q is a scalar number
   post: It is computed
by taking the sum of the component-wise products of the two vectors.
*/
double vectorType::dotProduct(vectorType R)const
{
   return((X * R.getX()) + (Y * R.getY()) + (Z * R.getZ()));
  
}

/*
   pre:The cross product of two vectors P and Q
   post:perpendicular to both P and Q with a magnitude equal to the area of the parallelogram that the vectors span.
*/
vectorType vectorType::crossProduct(vectorType R)const
{
   vectorType V2(((Y * R.getZ()) - (Z * R.getY())), ((Z * getX()) - (X * getZ())), ((X * getY()) - (Y * getX())));

   return R;
}
/*
   pre:- Are two vectors equal?
   post: outputs if they are equal or not
*/
bool vectorType::equalVector(vectorType R) const
{
   if ( !(abs(X - R.getX()) <= EPSILON ) )
      return false;
   if ( !(abs(Y - R.getY()) <= EPSILON ) )
      return false;
   if ( !(abs(Z - R.getZ()) <= EPSILON ) )
      return false;
    
   return true;
}
   

