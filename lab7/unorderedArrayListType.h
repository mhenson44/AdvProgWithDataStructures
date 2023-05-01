/*
   Name: Michael Henson
   Date: 02/25/2021
   Class: 1720
   Path: ~/csc1720/labv7/unorderArrayListType.h

   Desc: : Understand, work with, and modify the classes in the book for implementing array-based
unordered lists. 
*/

#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 

class unorderedArrayListType: public arrayListType
{
   public:
      //Constructor
      unorderedArrayListType(int size = 100);

      
      /* insertAt Function ...
          Function to insert insertItem in the list at the 
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
       /*insertEnd Function to insert insertItem an item at the end of 
        the list. Note that this is an abstract function.
        Postcondition: list[length] = insertItem; and length++;
                       If the list is full, an appropriate 
                       message is displayed.
      */

      void replaceAt(int location, int repItem);
  
      /* seqSearh Function ...
         Precondition: 
         Postcondition: 
      */
      int seqSearch(int searchItem) const;
      //Fucntion is to search the list for a specific element/value
      //postcondition: searched for element is found and output to the screen
      
      void removeAt(int location);
       /*removeAt Function to remove the item from the list at the 
        position specified by location 
        Postcondition: The list element at list[location] is 
                       removed and length is decremented by 1.
                       If location is out of range, an 
                       appropriate message is displayed.
      */
      
      
      void insertFirst(int insertItem);
      //Function moves the user inputted value to the first slot in the list
      // post condition: input value is outputted with the list in the list[0]
        // spot
      int findMax(double max) const;
      //function finds and returns the maximum value in the list
      //
}; 


#endif
