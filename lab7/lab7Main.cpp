/*
   Name: Michael Henson
   Date: 02/25/2021
   Class: 1720
   Path: ~/csc1720/labv7/lab7Main.cpp

   Desc: : Understand, work with, and modify the classes in the book for implementing array-based
unordered lists. 
*/

#include<iostream>
#include"unorderedArrayListType.h"
#include"arrayListType.h"

using namespace std;

int main()
{
   unorderedArrayListType listA(100);
   int num;
   //testing function to make the list of numbers
   cout<< "Enter 10 intergers: ";
      for(int i=0;i<10;i++)
         {
            cin >> num;
            listA.insertEnd(num);
         }
   //testing print fuction
   cout << "ListA Unordered List" << endl;
   listA.print();
   //testing print function
   unorderedArrayListType listB(listA);
   cout << "ListB Unordered List" << endl;
   listB.print();
   //testing removeAt
   cout << "Enter which position you want to remove from the list: ";
   cin >> num;
   listA.removeAt(num);
   
   cout << "ListA after number is Removed"<<endl;
   listA.print();
     
   cout << "Insert first element in the list: ";
   cin >> num;
   listA.insertFirst(num);
   cout << endl;
   listA.print();
  


   cout << "Largest number in ListA is: " << listA.findMax(num)<< endl;
   
   
 return 0;
}   
