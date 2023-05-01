/*
 Author: Michael Henson
   Class: csc1720
   Date: 02/02/2021
   Path: ~/mhenson/csc1720/lab4/lab4Test.cpp

   Desc: Main programfile

      to compile: g++ -Wall lab4Test.cpp vectoreType.cpp -o TestProg

*/

#include<iostream>
#include<iomanip>
#include"vectorType.h"
#include<fstream>

using namespace std;

int main()
{
   //two object passed as vectors
   vectorType vector2;
   vectorType vector1(5, 4, 6);
 //  vectorType V1(3, 4, 5);
  // vectorType V2(3);
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
//   V1.calcMagnitude(X,Y,Z);
//   V2.scalarMultiply(V1,V2);
//   vector1.printVector();
//   cout << endl;
//tried to get it to work but had too many errors
   
   
}
   

