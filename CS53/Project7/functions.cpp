//Teej Dolan
//CS53, Section C#
//Matt Nuckolls
//functions.cpp

//include statements
#include"functions.h"
#include<iostream>
#include<string>

using namespace std;

//greeting function
void greeting()
{
  cout<<"Howdy there user! Why are you not enjoying the sunshine outside?"
      <<"\nWelcome to the Quiz-a-ma-bob Thing Generator!"<<endl;
}

//menu function
int menu()
{
  int choice;
  cout<<"1. Easy\n"
      <<"2. Moderate\n"
      <<"3. Advanced\n"
      <<"Please select difficulty level: ";
  cin>>choice;
  
  while(choice<1&&choice>3) 
  {
    cout<<"Stupid user, that's not allowed. Gimme a good value: ";
    cin>>choice;
  }
  
  return choice;
}

//function to randomly determine the operator used in main problem
char operatorDecider(int rand)
{
  char randChoice;
  switch(rand)
  {
    case(0):
    {
      randChoice = '+';
    }
    break;
    case(1):
    {
      randChoice = '-';
    }
    break;
    case(2):
    {
      randChoice = '*';
    }
    break;
    case(3):
    {
      randChoice = '%';
    }
    break;
    default:
    {
      randChoice = '+';
    }
    break;
  }
  return randChoice;
}

//overloads << operaotr for display purposes
ostream& operator<<(ostream& out, const Problem& problem)
{
  out<<problem.m_operand1<<" "<<problem.m_operator<<" "
     <<problem.m_operand2<<" = ?"<<endl;
  
  return out;
}

//checks if user's answer is correct
bool isCorrect(Problem problema)
{
  bool correcto;
  switch(problema.m_operator)
  {
    case('+'):
    {
      if(problema.m_operand1 + problema.m_operand2 == problema.m_answer)
      {
        correcto = true;
      }
      else
      {
        correcto = false;
      }
    }
    break;
    case('-'):
    {
      if(problema.m_operand1 - problema.m_operand2 == problema.m_answer)
      {
        correcto = true;
      }
      else
      {
        correcto = false;
      }
    }
    break;
    case('*'):
    {
      if(problema.m_operand1 * problema.m_operand2 == problema.m_answer)
      {
        correcto = true;
      }
      else
      {
        correcto = false;
      }
    }
    break;
    case('%'):
    {
      if(problema.m_operand1 % problema.m_operand2 == problema.m_answer)
      {
        correcto = true;
      }
      else
      {
        correcto = false;
      }
     }
     break;
  }
  return correcto;
}



