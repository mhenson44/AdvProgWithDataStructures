/*
   Author: Michael Henson  
   Class: Csc1720
   Date: 01/29/2021 
   Path: ~/mhenson/csc1720/program1/main.cpp

   Desc: B level program output the total number of
vowels (a, e, i, o, u) and the total number of sentences in the passage. Output the number of characters in the passage. This should include all
alphabetical and numerical characters as well as spaces, line returns and punctuation.

How to compile
   g++ -Wall counterType.cpp main.cpp 

to execute
./a.out

*/

#include<iostream>
#include"counterType.h"
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{

//character strings
   counterType vowels;
   counterType sentences;
   counterType words;
   char cha;
   string file;

      ifstream inFile;
      cout << "Enter Filename: ";
      cin>>file;
      inFile.open(file);
   
      counterType suess;


      //Reading until EOF
      while(inFile.get(cha))
      {
      //code to check passage for vowels
         suess.incrementCounter();
            if(cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u'||
            cha == 'A' || cha == 'E' || cha == 'I' || cha == 'O' || cha == 'U')
               {
                  vowels.incrementCounter();
               }
      // code to check for amount of sentences
            if(cha == '.')
            {
               sentences.incrementCounter();
            }
      }
      inFile.close();
      //Character, vowel, and sentence output to screen
      cout << "Passage from " << file << endl;
      cout << right << setw(10) << "Number of chars: " << suess.getCounter() << endl;
      cout << right << setw(10) << "Number of vowels: " << vowels.getCounter() << endl;
      cout << right << setw(10) << "Number of sentences: " << sentences.getCounter() << endl;

return 0;
}
