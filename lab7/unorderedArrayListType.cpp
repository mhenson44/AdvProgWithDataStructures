/*
   Name: Michael Henson
   Date: 02/25/2021
   Class: 1720
   Path: ~/csc1720/labv7/unorderArrayListType.cpp

   Desc: : Understand, work with, and modify the classes in the book for implementing array-based
unordered lists. 
*/
#include <iostream>
#include "unorderedArrayListType.h" 

using namespace std; 

unorderedArrayListType::unorderedArrayListType(int size)
                      : arrayListType(size)
{
}  //end constructor

void unorderedArrayListType::insertAt(int location, int insertItem) 
{
   if (location < 0 || location >= maxSize || location > length)
      cout << "The position of the item to be inserted "
           << "is out of range." << endl;
   else if (length >= maxSize)  //list is full
      cout << "Cannot insert in a full list" << endl;
   else
   {
      for (int i = length; i > location; i--)
         list[i] = list[i - 1];	//move the elements down

      list[location] = insertItem; //insert the item at 
                                   //the specified position

      length++;	//increment the length
   }
} //end insertAt

void unorderedArrayListType::insertEnd(int insertItem)
{
   if (length >= maxSize)  //the list is full
      cout << "Cannot insert in a full list." << endl;
   else
   {
      list[length] = insertItem; //insert the item at the end
      length++; //increment the length
   }
} //end insertEnd

void unorderedArrayListType::replaceAt(int location, int repItem)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      list[location] = repItem;
} //end replaceAt

int unorderedArrayListType::seqSearch(int searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < length && !found)
      if (list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)
      return loc;
   else
      return -1;
} //end seqSearch

void unorderedArrayListType::removeAt(int location)
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

void unorderedArrayListType::insertFirst(int insertItem)
{
   if(length >= maxSize)
      cout << "Cannot insert in a full list." << endl;
   else
   {
      insertAt(0,insertItem);
   }
}

int unorderedArrayListType::findMax(double max) const
{
   max = list[0];
   for(int i = 0;i<length;i++)
      if (list[i] > max)
            max = list[i];
      return max;
}
