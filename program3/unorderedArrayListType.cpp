/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/unorderedArrayListType.cpp

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

using namespace std; 

template <class T>
unorderedArrayListType<T>::unorderedArrayListType(int size)
                      : arrayListType<T>(size)
{
}  //end constructor

template <class T>
void unorderedArrayListType<T>::insertAt(int location, T insertItem) 
{
   if (location < 0 || location >= this->maxSize || location > this->length)
      cout << "The position of the item to be inserted "
           << "is out of range." << endl;
   else if (this->length >= this->maxSize)  //list is full
      cout << "Cannot insert in a full list" << endl;
   else
   {
      for (int i = this->length; i > location; i--)
        this->list[i] = this->list[i - 1];	//move the elements down

       this->list[location] = insertItem; //insert the item at 
                                   //the specified position

     this->length++;	//increment the length
   }
} //end insertAt

template <class T>
void unorderedArrayListType<T>::insertEnd(T insertItem)
{
   if (this->length >= this->maxSize)  //the list is full
      cout << "Cannot insert in a full list." << endl;
   else
   {
     this->list[this->length] = insertItem; //insert the item at the end
      this->length++; //increment the length
   }
} //end insertEnd

template <class T>
void unorderedArrayListType<T>::replaceAt(int location, T repItem)
{
   if (location < 0 || location >= this->length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      this->list[location] = repItem;
} //end replaceAt

template <class T>
int unorderedArrayListType<T>::seqSearch(T searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < this->length && !found)
      if (this->list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)
      return loc;
   else
      return -1;
} //end seqSearch


