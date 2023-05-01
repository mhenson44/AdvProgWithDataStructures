#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
   vectorType X(3, 4, 5);
   vectorType Y(1, 2, 3);
   vectorType Z;
   
   Z = X.addVector(Y);

   cout << X.printVector() << endl;
   cout << Y.printVector() << endl;
   cout << Z.printVector() << endl;
