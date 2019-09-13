//Thomas Dolan
//Project Euler Problem 2

#include<iostream>

using namespace std;

int main()
{
  int sum = 0, fibStart = 1, fibEnd = 1, fibTemp = 0;

  while(fibStart < 4000000)
  {
    if((fibStart % 2) == 0)
    {
      sum += fibStart;
      cout<<sum<<endl;
    }
    fibTemp = fibStart;
    fibStart = fibEnd;
    fibEnd = fibEnd + fibTemp;
  }
  cout<<sum<<endl;

  return 0;
}


