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

      void deleteLargest();
      /*
      Function 'deleteLargest' removes the largest value from the linkedList by
               first iterating over the list and finding the largest value, and 
               then calling method 'deleteNode' on that value. Only removes single 
               instances.

      Pre-condition: None
      Post-condition: None
      */

      unorderedLinkedList<Type> merge(unorderedLinkedList<Type>&);
      /*
      Function 'merge' places the contents of another list and moves it into *this list.
                This is done by evaluating the states of each linked list (seeing whether
                they are empty or not) and then reassigning the values of the pointers 
                appropriately such that no costly copying has to be done. 
      
      Pre-condition: An unorderedLinkedList<Type> object [passed by reference]

      Post-condition: This method returns *this and supports chain assignment/method calling. After being called, 
                      the contents of the other list will belong to *this linked list - this means 
                      that the other list will be empty.
                                    
      */
      
      void forwardPrint();
      /*
      Function: 'forwardPrint' is similar to print in the sense that it iterates over the nodes
                in the linked list, printing them out as it goes, but the catch here is that 
                'forwardPrint' does so recursively ('forwardPrint()' is also exclusive to the
                unorderedLinkedList<Type> class).

      Pre-condition: This function has no parameters, but requires a single unorderedLinkedList<Type>
                     object to be called on. The object can be empty.

      Post-condition: No return value. This method does not support chain assignment/method calling.

      Note: this function is recursive
      */

      void reversePrint();
      /*
      Function: 'reversePrint' is similar to print in the sense that it iterates over the nodes
                in the linked list, printing them out as it goes, but the catch here is that 
                'reversePrint' does so recursively ('reversePrint()' is also exclusive to the
                unorderedLinkedList<Type> class). What differentiates 'reversePrint()' from 
                'forwardPrint()' is that 'reversePrint' prints the values in reverse order
                by calling the next function BEFORE printing out the current value.

      Pre-condition: This function has no parameters, but requires a single unorderedLinkedList<Type>
                     object to be called on. The object can be empty.

      Post-condition: No return value. This method does not support chain assignment/method calling.

      Note: this function is recursive
      */

    //Private Functions!
private:
      void forwardPrint(nodeType<Type>*);
      /*
      Function 'forwardPrint(nodeType<Type>*' prints the value of the current node and then calls
                this same function on the next node in the list (provided that the pointer is not nullptr)
                This method is private and serves as the recursive function call from 'forwardPrint'
      
      Pre-condition: This function takes a pointer a nodeType<Type> node, which it will print the value of

      Post-condition: No return value. This function will print the value of the current node
      */

      void reversePrint(nodeType<Type>*);
      /*
      Function 'reversePrint(nodeType<Type>*' calls this same function on the next node in the list 
                (provided that the pointer is not nullptr) and then prints the value of the current node.
                The effect of this method is that it prints the all the values of the linked list in reverse.
                This method is private and serves as the recursive function call from 'reversePrint'
      
      Pre-condition: This function takes a pointer a nodeType<Type> node, which it will print the value of

      Post-condition: No return value. This function will print the value of the current node AFTER calling itself
      */
};

//***************** unordered linked list type implementation **************************

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
   nodeType<Type> *curPtr = this->first;

   while(curPtr != nullptr) {
      if(curPtr->info == searchItem)
         return true;
      curPtr = curPtr->link;
   }

   return false;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type & newItem)
{
   nodeType<Type> *newNode;
   newNode = new nodeType<Type>;
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
   newNode = new nodeType<Type>;
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
    //Declare two pointers (two needed because one will be deleted)
    nodeType<Type> *curPtr = this->first;
    nodeType<Type> *prevPtr;
    Type largestInfo;
    
    if (this->first != nullptr)   
    {
        //Find the largest value
        largestInfo = this->first->info;            //set the 'largest' value to the first value

        while(curPtr != nullptr)                  
        {                                             
            if(curPtr->info > largestInfo)
            {
                largestInfo = curPtr->info;
            }
            curPtr = curPtr->link;
        }

        //Delete the largest item
        this->deleteNode(largestInfo);       
    }
    else
    {
        clog << "Cannot delete from empty list!" << endl;      //logging error
    }
}

//merge()
template <class Type>
unorderedLinkedList<Type> unorderedLinkedList<Type>::merge(unorderedLinkedList<Type>& other)
{
    
    if(this != &other)          
    {
        if(other.first == nullptr)   //If the other list is empty
        {
        }
        else if(this->first == nullptr)  
        {
            //Copy the contents of list B
            this->first = other.first;
            this->last  = other.last;
            this->count = other.count;

            
            other.first = nullptr;
            other.last  = nullptr;
            other.count = 0;
        }
        else if(this->first != nullptr && other.first != nullptr)    //if both lists have things
        {

            //Last value of list A must point to first value of list B
            this->last->link = other.first;

            //'Last' pointer of list A equalst 'Last' of list B
            this->last = other.last;

            //Add the count of list B to list A
            this->count += other.count;

            
            other.first = nullptr;
            other.last  = nullptr;
            other.count = 0;
        }
    }

    return *this;
}
     
//forwardPrint()
template <class Type>
void unorderedLinkedList<Type>::forwardPrint() 
{
    nodeType<Type>* curptr = this->first;     //set the pointer to the beginning of the list

    if(curptr != nullptr)  //If the list is not blank, print it.
    {
        cout << curptr->info << " ";
        forwardPrint(curptr->link);
    }
}

//forwardPrint(*ptr)
template <class Type>
void unorderedLinkedList<Type>::forwardPrint(nodeType<Type>* givenPtr) 
{

    if(givenPtr != nullptr)   //If you have not reached the end of the list
    {
        cout << givenPtr->info << " ";   //print the current info
        forwardPrint(givenPtr->link);        //move to the next node
    }
}

//reversePrint() 
template <class Type>
void unorderedLinkedList<Type>::reversePrint() 
{
    nodeType<Type>* curptr = this->first;   //set the pointer to the beginning of the linked list

    if(curptr != nullptr)  //If the list is not blank, print it.
    {
        reversePrint(curptr->link);           
        cout << curptr->info << " ";          
    }
}

//reversePrint(*ptr) 
template <class Type>
void unorderedLinkedList<Type>::reversePrint(nodeType<Type>* givenPtr) 
{

    if(givenPtr != nullptr)   //If you have no reached the end of the list
    {
        reversePrint(givenPtr->link);        //move to the next node
        cout << givenPtr->info << " ";   //print the current info
    }
}

#endif  

