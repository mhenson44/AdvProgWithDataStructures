/*
Name:Michael Henson  
Class:csc1720
Date:04/06/21
Path:~/mhenson/csc1720/lab12/lab12files/unorderedLinkList.h


Desc:creating a 2 lists and deleting a node in those lists. Finding the average of the unorderedList as well.
*/
#ifndef UNORDEREDLINKEDLIST
#define UNORDEREDLINKEDLIST

#include "linkedList.h"

using namespace std;


//***************** derived unordered linked list type definition **************************
template <class Type>
class unorderedLinkedList:public linkedListType<Type>
{
public:
      bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the 
      //               list, otherwise the value false is 
      //               returned.

      void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //               inserted at the beginning of the list,
      //               last points to the last node in the  
      //               list, and count is incremented by 1.

      void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem 
      //               is inserted at the end of the list,
      //               last points to the last node in the 
      //               list, and count is incremented by 1.

      void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing 
      //               deleteItem is deleted from the list.
      //               first points to the first node, last
      //               points to the last node of the updated 
      //               list, and count is decremented by 1.

      virtual void deleteLargest();
      //Function to delete deleteLargest item from the list.
      //Postcondition: If found, the node containing 
      //               deleteLargest is deleted from the list;
      //               first points to the first node of the 
      //               new list, and count is decremented by 1.
      //               
      //        
};

//***************** unordered linked list type implementation **************************

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
   nodeType<Type> *curPtr = this->first;
   //items in the list are in ascending order.
   //stop when you find it and return true.
   //stop when you know it's not in the list because
   //we have advanced to info larger than the searchItem
   while(curPtr != nullptr) {
      if(curPtr->info == searchItem)
         return true;
      curPtr = curPtr->link;
   }
 //at the end of the list so not present.
   return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type & newItem)
{
   nodeType<Type> *newNode;
   //creates new nodeType
   newNode = new nodeType<Type>;
   //points newNode to item inserted in the list; becoming new "first"
   newNode->info = newItem;
   newNode->link = this->first;
   this->first = newNode;
   this->count++;

   if(this->last==nullptr)
      this->last = newNode;
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type & newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>;i
   //points newNode to item inserted in the list; becoming new "last"
   newNode->info = newItem;
   this->count++;

   if(this->last==nullptr)
      this->first = this->last = newNode;
   else {
      this->last->link = newNode;
      this->last = newNode; 
   }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   bool found = false;
  
   if(this->isEmpty())
      cerr << "List is empty, can't delete from empty list!" << endl;
   else {
      prevPtr = nullptr;
      curPtr = this->first;
      while(curPtr != nullptr && !found) {
         if(curPtr->info != deleteItem) {
            prevPtr = curPtr;
            curPtr = curPtr->link;
         } else {
            found = true;
         }
      }
      if(!found) {
         cerr << deleteItem << " is not in the list" << endl;
      } else {
         if(curPtr == this->first) {
            //found in the first node
            this->first = this->first->link;
         } else {
            //found after the first node 
            prevPtr->link = curPtr->link;
         }
         if(curPtr == this->last) {
            //if curPtr = last pointer then one of two items are true;
            //only one node in the list and deleteItem is in the first node
            //more than one node in the list and deleteItem is the last node
            this->last = prevPtr;
         }
         delete curPtr; 
         this->count--;
      }
   }

}

template <class Type>
void unorderedLinkedList<Type>::deleteLargest()
{
   nodeType<Type> *curPtr;
   nodeType<Type> *prevPtr;
   nodeType<Type> *lrgPtr;
   nodeType<Type> *prevLrgPtr;

   if(this->isEmpty())
     cerr << "List is empty, can delete from empty list!" << endl;
   else if (this->first == this->last){
     //one item in list
     lrgPtr = this->first;
     this->first = this->last = nullptr;
     delete lrgPtr;
     this->count = 0;
   } else {
     //when first item is largest
     prevPtr = this->first;
     curPtr = this->first->link;
     while(curPtr != nullptr) {
        if(curPtr->info > lrgPtr->info) {
           prevLrgPtr = prevPtr;
           lrgPtr = curPtr;
         }
         //next item
         prevPtr = curPtr;
         curPtr = curPtr->link;
      }
      if(prevLrgPtr == nullptr) {
      //deletes first item
      this->first=this->first->link;
      } else {
         prevLrgPtr->link = lrgPtr->link;
         //deletes last item
         if(lrgPtr == this->last)
            this->last = prevLrgPtr;
      }
      delete lrgPtr;
      this->count--;
   }
}


#endif
