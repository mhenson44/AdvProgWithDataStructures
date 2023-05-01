/*
Name:Michael Henson  
Class:csc1720
Date:04/13/2021
Path:~/csc1720/lab13/main.cpp


Desc: program to create two lists of words and merge them together


compile
g++ -Wall main.cpp
*/

#include<iostream>
#include"unorderedLinkedList.h"
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

void load(unorderedLinkedList<string>&);

int main()
{
   //testing unordered list
   unorderedLinkedList<string> test;
   test.insertLast("test 1");
   test.insertLast("test 2");
   test.insertLast("test 3");
   test.insertLast("test 4");
   cout << "Testlist: ";
   cout << endl;
   test.print();
   cout << endl;
   

   unorderedLinkedList<string> A;
   unorderedLinkedList<string> B;

   load(A);
   load(B);

   //testing merge
   cout << "List A: ";
   A.print();
   cout << endl;

   cout << "List B: ";
   B.print();
   cout << endl;

   cout << "Merging two Lists A & B: " << endl;
   A.merge(B);
   //after the merge
   cout << "List A: ";
   A.print();
   cout << endl;

   cout << "List B: ";
   B.print();
   cout << endl;

   //test forwardPrint()
   
   cout << "List A: ";
   A.forwardPrint();
   cout << endl;

   cout << "List B: ";
   B.forwardPrint();
   cout << endl;

   //testing ReversePrint()

   cout << "List A: ";
   A.reversePrint();
   cout << endl;

   cout << "List B: ";
   B.reversePrint();
   cout << endl;

   return 0;
}
  
void load(unorderedLinkedList<string>& linkedList)
{
   string fileName;
   ifstream inFile;
   string word;

   do
   {
      cout << "Enter Filename: ";
      cin >> fileName;
      inFile.open(fileName);
      inFile >> word;
   }
      while(!inFile);

   while(!inFile.eof())
   {
      linkedList.insertLast(word);
      inFile >> word;
      }
   inFile.close();
}
