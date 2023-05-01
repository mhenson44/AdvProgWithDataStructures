/*
Name: Michael Henson
Date: 3/21/21
Class: csc1720
Code Location: ~/mhenson/csc1720/program3/raffMain.cpp

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

how to compile:
   g++ -Wall raffMain.cpp

   ./a.out
*/

#include <iostream>     
#include <string>                 
#include <fstream>    
#include <stdlib.h>
//#include "arrayListType.h"
//#include "unorderedArrayListType.h"
#include "uniqueListType.h"

using namespace std;

//prototypes

void loadNames(unorderedArrayListType<string>& Array);      

void removePerson(unorderedArrayListType<string>& ticketList, const string name);               

int randPerson(const unorderedArrayListType<string>& ticketList);               

string Dinner(const unorderedArrayListType<string>& ticketList);

string WetNWild(const unorderedArrayListType<string>& ticketList);      

string GiftCard(const unorderedArrayListType<string>& ticketList);      

string MoviePasses(const unorderedArrayListType<string>& ticketList); 

string GrandPrize(const uniqueListType<string>& ticketList);          

void calcProfits(const int ticketsBought); 
//profits



int main()
{
  srand(time(NULL));    
  int ticketsBought;
  string name;         

  //Create array of names from file
  unorderedArrayListType<string> NameList(100); 
  loadNames(NameList);
  
  uniqueListType<string> uniqueNamesList(NameList);
  ticketsBought = NameList.listSize() - 1; 
  cout << "Amount of tickets bought: " << ticketsBought << endl;

   //code for the four winners, 
  name = Dinner (NameList);
  removePerson(NameList, name);
  removePerson(uniqueNamesList, name);

  name = WetNWild(NameList);
  removePerson(NameList, name);
  removePerson(uniqueNamesList, name);

  name = GiftCard(NameList);
  removePerson(NameList, name);
  removePerson(uniqueNamesList, name);

  name = MoviePasses(NameList);
  removePerson(NameList, name);
  removePerson(uniqueNamesList, name);

  //code for grand prize winner
  name = GrandPrize(uniqueNamesList);
  removePerson(NameList, name);
  removePerson(uniqueNamesList, name);

  calcProfits(ticketsBought);   

  return 0;
}


//load function 
void loadNames(unorderedArrayListType<string>& Array)  
{
  ifstream file;          
  string filename;      
  string fname;   
  string lname;    
  string fullName;   

  cout << "Enter file name";
  cin >> filename;
  cout << endl;         

  file.open(filename);  

  if(file)       
  {
    file >> fname;
    file >> lname;

    fullName = fname + " " + lname; 
    Array.insertEnd(fullName);
  }

  if (!Array.isEmpty())
  {
    while(!file.eof())
    {
      file >> fname;
      file >> lname;

      fullName = fname + " " + lname; 
      Array.insertEnd(fullName);     
    }
  }
  else 
  {  
    cerr << "Error: file does not exist." << endl;
    exit(1);
  }

  file.close();      
}


//removePerson function 
void removePerson(unorderedArrayListType<string>& ticketList, const string name)                
{
  while(ticketList.seqSearch(name) != -1)   
  {
    ticketList.removeAt(ticketList.seqSearch(name));
  }

}
//randPerson function 
int randPerson(const unorderedArrayListType<string>& ticketList)  
{
 return (rand() % ticketList.listSize());     
}

//Winner of Dinner function
string Dinner(const unorderedArrayListType<string>& ticketList)    
{ 
  string name = ticketList.getAt(randPerson(ticketList));
  cout << "The winner for two at Blue Water Grille is " << name << endl;
  return name;
}

//WetNWild
string WetNWild(const unorderedArrayListType<string>& ticketList)  
{
  string name = ticketList.getAt(randPerson(ticketList));
  cout << "The winner of 4 passes to Wet 'N' Wild is " << name << endl;
  return name;
}

//Amazon GiftCard
string GiftCard(const unorderedArrayListType<string>& ticketList)   
{
  string name = ticketList.getAt(randPerson(ticketList));
  cout << "The $100 Amazon gift card goes to " << name << endl;
  return name;
}

//Movie Passes
string MoviePasses(const unorderedArrayListType<string>& ticketList)  
{
  string name = ticketList.getAt(randPerson(ticketList));
  cout << name << "wins 4 movie passes to Palladium Regal Theater" << endl;
  return name;
}

//Grand Prize
string genGrandPrizeWinner(const uniqueListType<string>& ticketList)
{

  string name = ticketList.getAt(randPerson(ticketList));
  cout << "Finally, The Grand Price winner is " << ticketList.getAt(randPerson(ticketList)) << endl;
  return name;
}

//calcProfits function 
void calcProfits(const int ticketsBought) 
{
  double costPerTicket, total, profit;                                      
  
  cout << "Enter the cost per ticket: $";                              
  cin >> costPerTicket;
  cout << endl;

  cout << "Please enter the total cost: $";      
  cin >> total;
  cout << endl;

  //profit for the overall event
  profit = (costPerTicket * ticketsBought) - total;

  cout << "The fundraiser raised: $" << profit << endl;   
}

