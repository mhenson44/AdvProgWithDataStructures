#ifndef uniqueList_TYPE
#define uniqueList_TYPE

#include<iostream>
#include<string>
#include"arrayListType.h"
#include"unorderedArrayListType.h"

class uniqueListType: public unorderedArrayListType
{
   public:
      
      uniqueListType(int size = 100);

      void insertAt(int location, string insertItem);

      void insertEnd(string insertItem);
      
      void replaceAt(int location, string repItem);

};

#endif
