/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/arrayListType.h

Desc: Your student club is selling raffle tickets to raise funds for a local charitable organization.
Individuals can buy as many tickets as they desire but can win at most one of the following
prizes:
Dinner for Two at Blue Water Grille
Set of 4 passes to Wet N Wild
$100 Amazon Gift Card
Set of 4 movie passes at the Palladium Regal Theater
In addition to those 4 prizes, you will also draw one winner for the grand prize of a PlayStation 5
gaming system. While individuals may enter the first drawing multiple times, they will only be
entered ONCE into the drawing for the grand prize. The grand prize will be drawn first and no
one can win more than one prize.
Your club is also interested in knowing the total profit from the fundraiser, calculated from the
revenue minus the costs. Some but not all of the prizes were donated, so these costs as well as
other expenses eat into the fundraiser’s profits. 
*/

#ifndef ArrayList_TYPE
#define ArrayList_TYPE 

#include <string>

template <class T> 
class arrayListType 
{
   protected:
      T *list;    //array to hold the list elements
      int length;   //variable to store the length of the list
      int maxSize;  //variable to store the maximum 
                  //size of the list
   public:
      /*Constructor
        Creates an array of the size specified by the 
        parameter size. The default array size is 100.
        Postcondition: The list points to the array, 
                       length = 0, and maxSize = size;
      */
      arrayListType(int size = 100);

      //Copy constructor
      arrayListType (const arrayListType<T> &otherList);

      //Destructor
      //Deallocate the memory occupied by the array.
      virtual ~arrayListType();

      /*isEmpty Function to determine whether the list is empty
        Postcondition: Returns true if the list is empty;
                       otherwise, returns false.
      */
      bool isEmpty() const;

      /*isFull Function to determine whether the list is full
        Postcondition: Returns true if the list is full; 
                       otherwise, returns false.
      */
      bool isFull() const;

      /*listSize Function to determine the number of elements in 
        the list.
        Postcondition: Returns the value of length.
      */
      int listSize() const;

      /*maxListSize Function to determine the maximum size of the list
        Postcondition: Returns the value of maxSize.
      */
      int maxListSize() const;

      /*print Function to output the elements of the list
        Postcondition: Elements of the list are output on the 
                       standard output device.
      */
      void print() const;

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
      virtual void insertAt(int location, T insertItem) = 0;

      /*insertEnd Function to insert insertItem an item at the end of 
        the list. Note that this is an abstract function.
        Postcondition: list[length] = insertItem; and length++;
                       If the list is full, an appropriate 
                       message is displayed.
      */
      virtual void insertEnd(T insertItem) = 0;

      /*removeAt Function to remove the item from the list at the 
        position specified by location 
        Postcondition: The list element at list[location] is 
                       removed and length is decremented by 1.
                       If location is out of range, an 
                       appropriate message is displayed.
      */
      void removeAt(int location);

      /*clearList Function to remove all the elements from the list 
        After this operation, the size of the list is zero.
        Postcondition: length = 0;
      */
      void clearList();

      /*seqSearch Function to search the list for searchItem.
        Note that this is an abstract function.
        Postcondition: If the item is found, returns the 
                       location in the array where the item   
                       is found; otherwise, returns -1.
      */
      virtual int seqSearch(T searchItem) const = 0;

      T getAt(int location) const;
};
#include "arrayListType.cpp"
#endif
