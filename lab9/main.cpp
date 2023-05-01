/*
   Name: Michael Henson
   Date: 03/17/2021
   Class: 1720
   Path: ~/csc1720/lab9/main.cpp

   Desc: : Understand, work with, and modify the classes in the book for implementing array-based
ordered lists. 

   how to compile: g++ -Wall *.cpp 
         ./a.out
*/
#include<iostream>
#include"orderedArrayListType.h"
#include"arrayListType.h"

using namespace std;

int main()
{
   orderedArrayListType listA(100);
   int num;
   //testing function to make the list of numbers
   cout<< "Enter 10 intergers: ";
      for(int i=0;i<10;i++)
         {
            cin >> num;
            listA.insertEnd(num);
         }
   //testing print fuction
   cout << "ListA Ordered List" << endl;
   listA.print();
   cout << "Testing Copy constructor" << endl;
   cout << endl;
   orderedArrayListType listB(listA);
   cout << "ListB Ordered List" << endl;
   listB.print();
   cout << endl;
   //Testing insertAt
   listA.insert(80); 
   listA.insert(30);
   listB.insert(25);
   listB.insert(105);
   listA.insertAt(2,85);
   listB.insertAt(4,24);
   listA.insertEnd(10000);
   listB.insertEnd(536);
   cout << "New ListA"<< endl;
   listA.print();
   cout << endl;
   cout << "New ListB" << endl;
   listB.print();
   cout << endl; 
   cout << "Enter the number you want to find in listA: ";
   cin >> num;
   cout << "Number is located at position " << listA.seqSearch(num) << endl;
   cout << endl;
   cout << "Enter the number you want to find in listB: ";
   cin >> num;
   cout << "Number is located at position " << listB.seqSearch(num) << endl;
   cout << endl;
   cout << "Testing operator= function "<<endl;
   listA = listB;
   cout << "List A" << endl;
   listA.print();
   cout << endl;
   cout << "List B" << endl;
   listB.print();
   cout << endl;
   listA.insert(7);
   listB.insert(106);
   cout << "New ListA"<< endl;
   listA.print();
   cout << endl;
   cout << "New ListB" << endl;
   listB.print();
   cout << endl; 
   
   
   
return 0;
}

