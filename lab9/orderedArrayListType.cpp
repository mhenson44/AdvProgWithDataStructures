/*
   Name: Michael Henson
   Date: 03/17/2021
   Class: 1720
   Path: ~/csc1720/labv7/orderedArrayListType.cpp

   Desc: : Understand, work with, and modify the classes in the book for implementing array-based
ordered lists. 
*/
#include <iostream>
#include "orderedArrayListType.h" 

using namespace std; 

orderedArrayListType::orderedArrayListType(int size)
                      : arrayListType(size)
{
}  //end constructor

void orderedArrayListType::insertAt(int location, int insertItem) 
{
   insert(insertItem);
}
 //end insertAt

void orderedArrayListType::insertEnd(int insertItem)
{
    insert(insertItem);
} //end insertEnd

void orderedArrayListType::replaceAt(int location, int repItem)
{
   if (location < 0 || location >= length)
      cout << "The location of the item to be "
           << "replaced is out of range." << endl;
   else
      list[location] = repItem;
} //end replaceAt

int orderedArrayListType::seqSearch(int searchItem) const
{
   int loc;
   bool found = false;

   loc = 0;

   while (loc < length && !found && list[loc] <= searchItem)
      if (list[loc] == searchItem)
         found = true;
      else
         loc++;

   if (found)      
      return loc;
   else
      return -1;
} //end seqSearch

void orderedArrayListType::insert(int insertItem)
{
 //list empty?
   if (length == 0)
      list[length++] = insertItem;
   else if (length == maxSize)
      cout << "Cannot insert in a full list." << endl;
   else {
 //Find the location in the list where to insert
 //insertItem. Keep in items are in ascending order.
   int loc=0;
   bool found = false;
      while (!found && loc < length) {
         if (list[loc] >= insertItem)
            found = true;
      else
         loc++;
   }
 //Now, move elements down to make space for insertItem
   for (int i = length; i > loc; i--)
      list[i] = list[i - 1];
 //loc is the location in the array for insertItem
      list[loc] = insertItem;
      length++;
   }
} //end insert

   //
const orderedArrayListType& orderedArrayListType::operator=(const orderedArrayListType& rightObject)
{
  if (this != &rightObject) 
   {
      //local declaration, if any
      delete [] list;
      maxSize = rightObject.maxSize;
      length = rightObject.length;
      list = new int [maxSize];

         for(int i = 0; i < length; i++)
            list[i] = rightObject.list[i];
      }
   //Return the object assigned.
   return *this;
}

//ostream &operator<<(ostream& A, const orderedArrayListType& B)
//{


//return B;
//}
