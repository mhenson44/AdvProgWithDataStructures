/*
Name:Michael Henson  
Class:csc1720
Date:04/06/21
Path:~/mhenson/csc1720/lab12/lab12files/ullTest.cpp

how to compile:
g++ -o testUnordered ullTest.cpp

execute:
./testUnordered

Desc:creating a 2 lists and deleting a node in those lists. Finding the average of the unorderedList as well.
*/
//Thisprogram tests various operations of an unordered linked list


#include<iostream>
#include"unorderedLinkedList.h"

using namespace std; 

double findAvg(unorderedLinkedList<int> &list)
{  
   double sum = 0.0;
   int count = 0;
   double avg = 0.0;
   
   linkedListIterator<int> it = list.begin();
   
   while(it != list.end()) {
      count++; //counts the integer
      sum = sum + *it;
      ++it; //goes to the next node
   }
   if(count !=0)
      avg = sum/count;
   return avg;
}

int main()
{
   unorderedLinkedList<int> listA, listB;          
   int num;                                        
   //creating list
   cout << "Creating list with input 22 7 48 93 14 2 " << endl ;
   //inserts items in list
   listA.insertLast(22);                      
   listA.insertLast(7);
   listA.insertLast(48);
   listA.insertLast(93);        
   listA.insertLast(14);
   listA.insertLast(2);
   
   cout << endl;                                   

   cout << "listA: ";                      
   listA.print();                                  
   cout << endl;                                   
   //gives the length of ListA 
   cout << "Length of listA: " << listA.length() << endl;                 

   listB = listA;	   //test the assignment operator 

   cout << endl;
   cout << "listB: ";                     
   listB.print();                                  
   cout << endl;                                   
   //length of listB
   cout << "Length of listB: " << listB.length() << endl;                 
   //deleteNode function
   cout << endl;
   cout << "Enter the number to be " << "deleted: ";                           
   cin >> num;                                     
   cout << endl;
   listB.deleteNode(num);                          
	cout << endl;

   cout << "After deleting " << num << endl;
   cout << "listB: " ;                     
   listB.print();                                  
   cout << endl;                                

   cout << "Length of listB: " << listB.length() << endl;              
   cout << endl;

   cout << "Output listA " << "using an iterator:" << endl;            

   linkedListIterator<int> it;                  

   for (it = listA.begin(); it != listA.end(); ++it)                  
       cout << *it << " ";                        
   cout << endl;
   cout << endl;
   //deleteLargest function
   cout << "Deleting largest node in the list "<<endl;
   cout << endl;
   cout << "After largest node is deleted " <<endl;
   cout << "listB: ";
   listB.deleteLargest();
   listB.print();
   cout << endl;
   //findAvg function
   cout << endl;
   cout << "Finding average of ListA and ListB "<< endl;
   cout << "ListA average:" << findAvg(listA)<< endl;;
   cout << "ListB average:" << findAvg(listB)<< endl;;
   cout << endl;
   
   unorderedLinkedList<char> listC;          
   char x;                                 

   cout << endl << "Creating list with input A K M G ! C " << endl ;

   listC.insertLast('A');                      
   listC.insertLast('K');
   listC.insertLast('M');
   listC.insertLast('G');        
   listC.insertLast('!');
   listC.insertLast('C');
       
   cout << endl;                                   

   cout << "listC: ";                      
   listC.print();                                  
   cout << endl;                                   
   cout << "Length of listC: " << listC.length() << endl;  

   cout<< endl << "Enter the character to be " << "deleted: ";                           
   cin >> x;                                     
   cout << endl;
   listC.deleteNode(x);                          
   cout << endl;

   cout << "After deleting " << x << endl;
   cout << "listC: " ;                     
   listC.print();                                  
   cout << endl;                         
   cout << endl;
   //deleteLargest Function again
   cout << "Deleting largest node in the list "<<endl;
   cout << endl;
   cout << "After largest node is deleted " <<endl;
   cout << "listC: ";
   listC.deleteLargest();
   listC.print();
   cout << endl;

   return 0;					
}



