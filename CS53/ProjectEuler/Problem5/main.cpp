//TJ Dolan
//Project Euler Problem 5

#include<iostream>

using namespace std;

int main()
{

  
  for(int i = 1; i < 999999999; i++)
  {
    for(int divisor = 1; divisor < 21; divisor++)
    {
      if(i % divisor != 0)
      {
        break;
      }
      if(divisor == 20)
      {
        cout<< i<<endl;
        i = 999999999;
        break;
      }
    }
  }
  
  
  return 0;
}


