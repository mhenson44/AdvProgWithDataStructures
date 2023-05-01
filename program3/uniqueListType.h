/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/uniqueListType.h

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

#ifndef UniqueList_TYPE
#define UniqueList_TYPE

#include"unorderedArrayListType.h"
template <class T>
class uniqueListType: public unorderedArrayListType<T>
{
   public:
      //Default Constructor - defaults to an array size of 100 if none is given
      uniqueListType(int size = 100);

      void insertAt(int location, T insertItem);

      void insertEnd(T insertItem);
      
      void replaceAt(int location, T repItem);
      //Copy constructor - takes in an arrayListType and creates a copy of uniqueListType
      uniqueListType(const arrayListType<T>& otherList);

};

#endif
