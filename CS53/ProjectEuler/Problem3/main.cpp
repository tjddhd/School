//TJ Dolan
//Project Euler Problem 3

#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int main()
{
  int largePrime;
  unsigned long comp = 123456789012;
  bool good = true;

  for(int i = 2; i < comp; i++)
  {
    if((comp % i) == 0)
    {
      for(int j = 2; j < i; j++)
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
  }

  cout<<largePrime<<endl;

  return 0;
}


