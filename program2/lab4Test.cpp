/*
 Author: Michael Henson
   Class: csc1720
   Date: 02/02/2021
   Path: ~/mhenson/csc1720/lab4/lab4Test.cpp

   Desc: Main programfile

      to compile: g++ -Wall lab4Test.cpp vectorType.cpp
      ./a.out

*/

#include<iostream>
#include<iomanip>
#include"vectorType.h"
#include<fstream>
#include<cmath>
#define EPSILON 0.0001
using namespace std;

int main()
{
   //two object passed as vectors
   vectorType vector2;
   vectorType vector1(5, 4, 6);
   //Default constuctor printout
   cout << "Testing default Constructor with values of 0"<< endl;   
   cout << "x = " << vector2.getX()<<endl;
   cout << "y = " << vector2.getY()<<endl;
   cout << "z = " << vector2.getZ()<<endl;
   cout << endl;   
   //Parameterized constuctor printout
   cout << "Testing parameterized Constructor with values x = 5, y = 4, z = 6"<< endl;   
   cout << "x = " << vector1.getX()<<endl;
   cout << "y = " << vector1.getY()<<endl;
   cout << "z = " << vector1.getZ()<<endl;
   //setComp printout
   cout << "Testing setComps method with values x = 2, y = 3, z = -4" << endl;
   vector1.setComps(2, 3, -4);
   cout << "Vector components: x = " << vector1.getX() << ", y = " << vector1.getY() << ", z = " << vector1.getZ() << endl; 
   vector1.printVector();
   cout << endl;
   cout << endl;
   cout << "Calculating Magnitude"<<endl;
   cout << vector1.calcMagnitude();
   cout << endl;
   cout << endl;
   cout << "Calculating Scalar" << endl;
   double scal = 2;
   vector1.setScale(scal);
   vector1.scalarMultiply();
   cout << "<" << vector1.getX() << "," << vector1.getY() << "," << vector1.getZ() << ">" << endl;
   cout << endl;
   vectorType P(3, 4, 5);
   vectorType Q(1, 2, 3);
   
   vectorType R;
   vectorType U;

   R = P.addVector(Q);
   cout << endl;
   cout << "Addition";
   P.printVector();
   Q.printVector();
   R.printVector();   
   cout<< endl;
   cout << endl;
   cout << "Subtraction";
   R = P.subVector(Q);
   P.printVector();
   Q.printVector();
   R.printVector();   
   cout << endl;
  /*
    cout << "Unit Vector";
   U = P.unitVector();
   U.printVector();   
   */
   cout << endl;
   cout << "Dot Product";
   cout << endl;
   cout << P.dotProduct(Q)<<endl;
   cout << endl;

   cout << "Cross Product";
   R = P.crossProduct(Q);
   R.printVector();
   cout<<endl;
   cout<<endl;
   cout << "Equal Vectors"<<endl;

   if(P.equalVector(Q))
   cout << "Vectors P and Q are equal" << endl;
   else
   cout << "Vectors P and Q are NOT equal to within " << EPSILON
   << endl;
   cout << endl;
}
   

