//Thomas Dolan
//CS54, Tues. 6pm
//Brian Goldman
//Functions.cpp

//include statements
#include<iostream>
#include"functions.h"

using namespace std;

//greeting function
void greetings()
{
  cout<<"Howdy user!"<<endl;
}

//inputs sides
int getSides()
{
  int sides;
  cout<<"Please input an even positive integer: ";
  cin>>sides;

  while(sides <= 0)
  {
    cout<<"INPUT A POSITIVE NUMBER KENNY: ";
    cin>>sides;

    while(sides%2 == 1)
    {
      cout<<"INPUT AN EVEN NUMBER KENNY: ";
      cin>>sides;
    }
  }
  
  return sides;
}

//inputs rolls
int getRolls()
{
  int rolls;
  cout<<"Please input a positive numbe of rolls: ";
  cin>>rolls;

  while(rolls <= 0)
  {
    cout<<"INPUT A POSITIVE NUMBER KENNY: ";
    cin>>rolls;
  }
  
  return rolls;
}

//calculates dice rolls
int rollDice(const int sides)
{
  int rollValue = rand()%sides + 1;
  return rollValue;
}

//checks the faiirness of a certain roll
void checkFairness(const int sides, const int rolls, int& low, int& high)
{
  for(int i = 0; i < rolls; i++)
  {
    int value = rollDice(sides);
    if(value <= sides/2)
    {
      low++;
    }
    else
    {
      high++;
    }
  }
}

//goodbye message
void signoff()
{
  cout<<"Goodnight user and remember... courage."<<endl;
}

