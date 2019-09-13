//TJ Dolan
//Project Euler

#include<iostream>

using namespace std;

int main()
{
  int sumSquare = 0, squareSum = 0;

  for(int i = 1; i < 101; i++)
  {
    sumSquare += i;
    squareSum += (i*i);
  }
  sumSquare = sumSquare * sumSquare;
  
  cout<<sumSquare<<endl;
  cout<<squareSum<<endl;

  cout<<sumSquare - squareSum<<endl;

  return 0;
}

