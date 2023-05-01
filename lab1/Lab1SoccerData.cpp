/*
   Name:Michael Henson
   Date:01/12/2021
   Class:Csc1720
   Code location:~/mhenson/csc1720/lab1/Lab1SoccerData.cpp

   About:A program that defines a playerType struct to store data about a soccer player (player's first
name, position, total number of games played, total number of goals, number of shots taken, and total number of minutes
played)
*/
#include<iostream>
#include<iomanip>

using namespace std;
//main struct
struct playerType {
      string name;
      string position;
      int games;
      int goals;
      int mins;
      int shots;
      double percent;
   };

//prototypes
void loadData(playerType P[], int &n);
void printData(playerType P[], int n);
//main fuction
int main()
{
   playerType playerDB[30];
   int n;

   loadData(playerDB, n);
   printData(playerDB, n);

   return 0;
}
/* Load Function */

void loadData(playerType P[], int &cnt)
{
   cnt = 0;
   string name;
   string position;
   int games;
   int goals;
   int mins;
   int shots;

   cin >> name >> position >> games >> goals >> mins >> shots;
   cout << endl;
   while(!cin.eof() && cnt < 30) {
      P[cnt].name = name;
      P[cnt].position = position;
      P[cnt].games = games;
      P[cnt].goals = goals;
      P[cnt].mins = mins;
      P[cnt].shots = shots;
      cnt++;
      cin >> name >> position >> games >> goals >> mins >> shots;
   }
}

/* print Function */

void printData(playerType P[], int n)
{
   cout << fixed << showpoint;
   cout << "HPU Women's Soccer Stats"<< endl;
   cout << left << setw(10) << "Name";
   cout << right << setw(5) << "Position";
   cout << right << setw(15) << "GP";
   cout << right << setw(15) << "G";
   cout << right << setw(15) << "SH";
   cout << right << setw(15) << "Mins";
   cout << right << setw(25) << "Shot%"<< endl;
   //op to print out the different players data
   for(int i = 0; i<=n; i++) {
      cout<< left << setw(10) << P[i].name;
      cout<< right << setw(5) << P[i].position;
      cout<< right << setw(17) << P[i].games;
      cout<< right << setw(16) << P[i].goals;
      cout<< right << setw(20) << P[i].mins;
      cout<< right << setw(20) << P[i].shots;
     // cout<< right << setw(40) << setprecision(2) << percent;
     double percent = ((double)goals/(double)shots)*100;
     // cout << right << setw(40) << percent << endl;   
   }
}

