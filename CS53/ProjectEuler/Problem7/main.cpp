//TJ Dolan
//Project Euler, Problem 7

#include<iostream>

using namespace std;

int main()
{
  unsigned long largePrime;
  bool good = true;
  int w = 0;

  while(w < 10000)
  {
  for(int i = 2; i < 10000000; i++)
  {
    for(int j = 2; j < (i/2); j++)
    {
      if((i % j) == 0)
      {
        good = false;
      }
    }
    if(good)
    {
      largePrime = i;
    }
  }
  cout<<largePrime<<endl;
  w++;
  }

  cout<<largePrime<<endl;

  return 0;
}


