/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/unorderedArrayListType.h

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

#ifndef UnorderedArrayList_TYPE
#define UnorderedArrayList_TYPE
   
#include "arrayListType.h" 

template <class T>
class unorderedArrayListType: public arrayListType<T>
{
   
   public:
      //Constructor
      unorderedArrayListType(int size = 100);
      /* insertAt Function takes in an element and inserts it in the given position in the list.
      It moves an element to the end and replace that element's position with the given element.
         Precondition: enough space for another element
         Postcondition: a list with one more element in it - the given element
      */
      void insertAt(int location, T insertItem);
      /* insertEnd Function appends a given item to the list
         Precondition: enough space to add a new eement
         Postcondition: a list with one more element - the given element
      */
      void insertEnd(T insertItem);

      /* replaceAt Function replaces the element at a given position in the list
      with the string prodvided by the user
         Precondition: a location that is within the current bounds of the list (0 - length-1)
         Postcondition: a list in which one element has been replaced 
      */
      void replaceAt(int location, T repItem);

      /* seqSearch Function performs a standard sequential search on the list, searching fo the provided 
      element, and then overwrites it with the given string
         Precondition: an instantiated list - requires at least one element 
         Postcondition: the given location must be within the range of the list (0 - length-1)
      */
      int seqSearch(T searchItem) const;

}; 
#include "unorderedArrayListType.cpp"
#endif
