/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/uniqueListType.cpp

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

#include<iostream>
#include"uniqueListType.h"
using namespace std;

template <class T>
uniqueListType<T>::uniqueListType(int size)
               : unorderedArrayListType<T>(size)
{
}

template <class T>
>>uniqueListType<T>::uniqueListType(const arrayListType<T>& otherList)
  {
     this->maxSize = otherList.maxListSize();
     this->length = 0;
  
     this->list = new T[this->maxSize];  //create the array
  
     for (int j = 0; j < otherList.listSize(); j++)  //copy otherList -- iterates over otherList as you do not know what 
     {                                                              //the size of the list will be
        if(this->seqSearch(otherList.getAt(j)) == -1)
            this->insertEnd(otherList.getAt(j));
     }
  }//end copy constructor

template <class T>
void uniqueListType<T>::insertAt(int location, T insertItem)
{
     if (unorderedArrayListType::seqSearch(insertItem) == -1;)
      unorderedArrayListType::insertAt(location,insertItem);
}

template <class T>
void uniqueListType<T>::insertEnd(T insertItem);
{
     if (unorderedArrayListType::seqSearch(insertItem) == -1;)
      unorderedArrayListType::insertEnd(insertItem);
}
      
template <class T>
void uniqueListType<T>::replaceAt(int location, T repItem);
{
      if(unorderedArrayListType::seqSearch(repItem) == -1;)
      unorderedArrayListType::replaceAt(location, repItem);
}
