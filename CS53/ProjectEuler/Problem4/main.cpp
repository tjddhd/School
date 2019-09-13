//TJ DOlan
//Project Euler Problem 4

#include<iostream>

using namespace std;

int main()
{
  int a = 999, b = 999, abResult, max = 0;
  int answer, c, d, e, f, g, h;

  for(int i = 0; i < a; i++)
  {
    for(int j = 0; j < b; j++)
    {
       abResult = (a - i) * (b - j);
       c = abResult % 10;
       d = (abResult % 100) / 10;
       e = (abResult % 1000) / 100;
       f = (abResult % 10000) / 1000;
       g = (abResult % 100000) / 10000;
       h = (abResult % 1000000) / 100000;
       
       answer = (c*100000) +(d*10000) +(e*1000) + (f*100) + (g*10) + h;
       if((answer == abResult) && (answer > max))
       {
         max = answer;
       }
    }
  }
  cout<<max<<endl;

  return 0;
}

