#include<iostream>
#include"unorderedArrayListType.h"
#include<string>
#include<fstream>
#include"arrayListType.h"
using namespace std;

#define MAX 100

void load(unorderedArrayListType &names); 

int main()
{
   uniqueListType names(16);
   cout << "Loading in names"<<endl;
   load(names);     
   names.print();

return 0;
}

void load(unorderedArrayListType &names)
{
   string val;
   cin >> val;
   while(!cin.eof()&& !names.isFull()){
      
      names.insertEnd(val);
      cin >> val;
     }
}
