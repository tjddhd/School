#include <stdlib.h>
#include <iostream>

using namespace std;

template<typename T>
changeOpAndEval(int x, T t, int y);

int main()
{
  int num1, num2;
  char op;
  cout<<"input 1:";
  cin >> num1;
  cout<<"input op:";
  cin >> op;
  cout<<"input 2:";
  cin >> num2;
  
  cout<<changeOpAndEval(num1,op,num2)<<endl;

  return 0;
}


template<typename T>
typename T:: changeOpAndEval(int x, T t, int y)
{
  int result;
  
    if(t == '+')
        result = x - y;
        
          return result;
          }
          
