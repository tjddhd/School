//Teej Dolan
//Cs53, Section c
//Matty Nuckolls
//functions.hpp

//Include statements
#include<string>
#include<iostream>
#include<algorithm>
#include"functions.h"

using namespace std;

//Overloads the >> operator
istream& operator>>(istream& ins, Stock& stock)
{
  ins >> stock.m_name >> stock.m_price >> stock.m_peRatio;
  
  return ins;
}

//Overloads the << operator
ostream& operator<<(ostream& outs, Stock& stock)
{
  outs << stock.m_name <<"    "<<stock.m_price<<"    "
       << stock.m_peRatio<<endl;
  return outs;
}

//overloads the < operator
bool operator<( Stock& stock1, Stock& stock2)
{
  return (stock1.m_peRatio < stock2.m_peRatio);
} 

//templated sort funciton
template <class T>
void sorter(T arr[], const int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = i+1; j < size; j++)
    {
      if(arr[i] < arr[j])
      {
        swap(arr[i], arr[j]);
      }
    }
  }
}

//greeting and signoff functions
void greeting()
{
  cout<<"Howdy user!" <<endl;
}

void signoff()
{
  cout<<"See ya later user!"<<endl;
}


