/*
Name:Michael Henson  
Class:csc1720
Date:04/06/21
Path:~/mhenson/csc1720/lab12/lab12files/ollTest.cpp

how to compile:
g++ -o testOrdered ollTest.cpp

execute:
./testOrdered

Desc:creating a 2 lists and deleting a node in those lists. Finding the average of the unorderedList as well.
*/
//Program to test the various operations on an ordered linked list
  
#include <iostream>
#include "orderedLinkedList.h"
 
using namespace std;
 
int main()
{
   orderedLinkedList<int> list1, list2;        
   int num;                                    

   cout << "Creating list with input 77 11 44 99 33 55" << endl ;
   //creates list
   list1.insertLast(77);                      
   list1.insertLast(11);
   list1.insertLast(44);
   list1.insertLast(99);        
   list1.insertLast(33);
   list1.insertLast(55);

   cout << endl;                               

   cout << "list1: ";                  
   list1.print();                             
   cout << endl;                               

   list2 = list1; //test the assignment operator 

   cout << "list2: ";                 
   list2.print();                              
   cout << endl;                              
   //deleteNode function
   cout << "Enter the number to be " << "deleted: ";                        
   cin >> num;                               
   cout << endl;                               

   list2.deleteNode(num);                     

   cout << "After deleting " << num << endl;
   cout << "list2: " ;         
   list2.print();                              
   cout<<endl;  

   cout << endl << "Output list1 " << "using an iterator:" << endl;            

   linkedListIterator<int> it;                  

   for (it = list1.begin(); it != list1.end(); ++it)                  
       cout << *it << " ";                        
   cout << endl;          
   cout <<endl;
   //delete Largest Function
   cout << "Deleting largest node in the list "<<endl;
   cout << endl;
   cout << "After largest node is deleted " <<endl;
   cout << "list2: ";
   list2.deleteLargest();
   list2.print();
   cout << endl;
   
   return 0;					
}



