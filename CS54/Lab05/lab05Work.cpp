//Thomas Dolan
//CS54, 6-8pm T
//Brian Goldman
//Lab 5: Fortune Teller

#include<iostream>
#include<string>

using namespace std;

int main()
{
  int counter, steps, fortuneNum = 0;
  
  cout<<"Hola user! Welcome to the Fortune Teller Program!"<< endl
      <<"Please pick a positive number: ";
  cin>>steps;
 
  while(steps < 0)
  {
    cout<<"ERROR mortal! Please enter a POSITIVE number: ";
    cin>>steps;
  }
   
  for(counter = 0; counter < steps; counter++)
  {
    switch(fortuneNum)
    {
      case(0):
      {
        fortuneNum = 4;
      }
      break;
      case(1):
      {
        fortuneNum = 5;
      }
      break;
      case(2):
      {
        fortuneNum = 0;
      }
      break;
      case(3):
      {
        fortuneNum = 6;
      }
      break;
      case(4):
      {
        fortuneNum = 3;
      }
      break;
      case(5):
      {
        fortuneNum = 2;
      }
      break;
      case(6):
      {
        fortuneNum = 7;
      }
      break;
      case(7):
      {
        fortuneNum = 1;
      }
      break;
    }
  }

  cout<<"You have chosen Fortune Number "<< fortuneNum<< endl;

  switch(fortuneNum)
  {
    case(0):
    {
      cout<<"Treasure the sleep you get since you won't get much tonight"<< endl;
    }
    break;
    case(1):
    {
      cout<<"You will study till 3AM later this month"<< endl;
    }
    break;
    case(2):
    {
      cout<<"Ramen shall become a part of your diet, "
          <<"if not the only thing you eat"<< endl;
    }
    break;
    case(3):
    {
      cout<<"Good fortune will follow you when you don't want it"<< endl;
    }
    break;
    case(4):
    {
      cout<<"CS FOREVA LOLZ!!"<< endl;
    }
    break;
    case(5):
    {
      cout<<"You will slip on some ice tomorrow"<< endl;
    }
    break;
    case(6):
    {
      cout<<"DUCK!!!"<< endl;
    }
    break;
    case(7):
    {
      cout<<"You true love will go to the football game"<< endl;
    }
    break;
  }
  
  return 0;
}
