/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/arrayListType.cpp

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

#include <iostream> 
#include "arrayListType.h"
using namespace std;

template <class T>
arrayListType<T>::arrayListType(int size)
{
   if (size <= 0)
   {
      cout << "The array size must be positive. Creating "
           << "an array of the size 100." << endl;

      maxSize = 100;
   }
   else
      maxSize = size;

   length = 0;

   list = new T[maxSize];
} //end constructor
template <class T>
arrayListType<T>::~arrayListType()
{
   delete [] list;
} //end destructor
template <class T>
arrayListType<T>::arrayListType(const arrayListType<T>& otherList)
{
   maxSize = otherList.maxSize;
   length = otherList.length;

   list = new T[maxSize]; 	//create the array

   for (int j = 0; j < length; j++)  //copy otherList
      list [j] = otherList.list[j];
}//end copy constructor
template <class T>
bool arrayListType<T>::isEmpty() const
{
   return (length == 0);
} //end isEmpty

template <class T>
bool arrayListType<T>::isFull() const  
{
   return (length == maxSize);
} //end isFull

template <class T>
int arrayListType<T>::listSize() const
{
   return length;
} //end listSize

template <class T>
int arrayListType<T>::maxListSize() const
{
   return maxSize;
} //end maxListSize

template <class T>
void arrayListType<T>::print() const
{
   for (int i = 0; i < length; i++)
      cout << list[i] << " ";
   cout << endl;
} //end print

template <class T>
void arrayListType<T>::removeAt(int location)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be removed "
           << "is out of range." << endl;
   else
   {
      for (int i = location; i < length - 1; i++)
         list[i] = list[i+1];

      length--;
   }
} //end removeAt

template <class T>
void arrayListType<T>::clearList()
{
   length = 0;
} //end clearList

template <class T>
   T arrayListType<T>::getAt(int location) const
{
   if (location < 0 || location >= length)
   {
      cerr << "Location of the item is out of range, therefore returns NULL." << endl;
   }
   else
      return list[location];
}
//end of getAt/printAt 
