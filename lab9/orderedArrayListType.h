/*
   Name: Michael Henson
   Date: 03/17/2021
   Class: 1720
   Path: ~/csc1720/lab9/orderedArrayListType.h

   Desc: : Understand, work with, and modify the classes in the book for implementing array-based
ordered lists. 
*/

#ifndef orderedArrayList_TYPE
#define orderedArrayList_TYPE
   
#include "arrayListType.h" 

using namespace std;

class orderedArrayListType: public arrayListType
{
   public:
      //Constructor
      orderedArrayListType(int size = 100);

       /*insertAt Function to insert insertItem in the list at the 
        position specified by location. 
        Note that this is an abstract function.
        Postcondition: Starting at location, the elements of 
                       the list are shifted down, 
                       list[location] = insertItem; length++;    
                       If the list is full or location is
                       out of range, an appropriate message 
                       is displayed.
      */

      void insertAt(int location, int insertItem);
  
      /*insertEnd Function to insert insertItem an item at the end of 
        the list. Note that this is an abstract function.
        Postcondition: list[length] = insertItem; and length++;
                       If the list is full, an appropriate 
                       message is displayed.
      */

      void insertEnd(int insertItem);

      /* replaceAt Function ...
         Precondition: 
         Postcondition: 
      */
      void replaceAt(int location, int repItem);
  
       /*seqSearch Function to search the list for searchItem.
        Note that this is an abstract function.
        Postcondition: If the item is found, returns the 
                       location in the array where the item   
                       is found; otherwise, returns -1.
      */
      //Fucntion is to search the list for a specific element/value
      //postcondition: searched for element is found and output to the screen
      int seqSearch(int searchItem) const;

     /*
      insert function
      precondition: function inserts value in the list, extending by one everytime 
      postcondition: inserts value into the list           
      */
      void insert(int insertItem);

      /*
      precondition: function to set the equal operator
      postcondition: makes it able to set both objects equal to each other
      */
      const orderedArrayListType& operator=(const orderedArrayListType&);

      
//      friend ostream &operator<<(ostream&, const orderedArrayListType&)
}; 

#endif
