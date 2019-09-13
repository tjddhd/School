//TTTTJJJJ Dolan
//CS53, Section C++
//Matty Nuckolls
//Project 7: Trogdor.... Again... -_-
//laTarea7.cpp

//include statements
#include"functions.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

//main function
int main()
{
  //random seed
  srandom(time(NULL));
 
  //variable declarations
  bool done = false;
  bool correct;
  int right=0, wrong=0;
 
  //greeting function
  greeting();

  //looop that handles the bulk of the program like difficulty, problem generation, and stat output
  do
  {
    char mathOperator;
    int difficulty = menu();
    Problem problema;
    
    cout<<"Please pick a math operation for the quiz to be focused on. "
        <<"Pick 0 for random generation (+,-,*,%,0): ";
    cin>>mathOperator;

    cout <<"Stuff: " <<  mathOperator << endl;

    while(mathOperator != '+' && mathOperator != '-' && mathOperator != '*'
          && mathOperator != '%' && mathOperator != '0')
    {
      cout<<"Please enter a valid operator: ";
      cin>>mathOperator;
    }

    if(mathOperator == '0')
    {
      mathOperator = operatorDecider(random()%4);
    }

    if(difficulty == 1)
    {
      for(int i =0; i<10;i++)
      {
        int answer;
        problema.m_operand1 = random() % 10;
        problema.m_operand2 = random() % 10;
        problema.m_operator = mathOperator;
        
        if(problema.m_operator == '%' && problema.m_operand2 == 0)
        {
          problema.m_operand2 = 1;
          
          cout<<problema<<"Your answer: ";
          cin>>answer;
          problema.m_answer = answer;
     
          correct = isCorrect(problema);
        }
        else
        {
          cout<<problema<<"Your answer: ";
          cin>>answer;
          problema.m_answer = answer;

          correct = isCorrect(problema);
        }
        
        if(correct)
        {
          right++;
        }
        else
        {
          wrong++;
        }
      }
    }
    else if(difficulty == 2)
    {
      for(int i =0; i<10;i++)
      {
        int answer;
        problema.m_operand1 = random() %100;
        problema.m_operand2 = random() %100;
        problema.m_operator = mathOperator;

	if(problema.m_operator == '%' && problema.m_operand2 == 0)
        {
          problema.m_operand2 = 10;
  
          cout<<problema<<"Your answer: ";
          cin>>answer;
          problema.m_answer = answer;
      
          correct = isCorrect(problema);
        }
        else
        {
          cout<<problema<<"Your answer: ";
          cin>>answer;
          problema.m_answer = answer;

          correct = isCorrect(problema);
        }

        if(correct)
        {
          right++;
        }
        else
        {
          wrong++;
        }
      }
    }
    else if(difficulty == 3)
    {
      for(int i =0; i<10;i++)
      {
        int answer;
        problema.m_operand1 = random() %10000;
        problema.m_operand2 = random() %10000;
        problema.m_operator = mathOperator;
       
        if(problema.m_operator == '%' && problema.m_operand2 == 0)
        {
          problema.m_operand2 = 1000;

          cout<<problema<<"Your answer: ";
          cin>>answer;
          problema.m_answer = answer;

          correct = isCorrect(problema);
        }
        else
        {
          cout<<problema<<"Your answer: ";
          cin>>answer;
          problema.m_answer = answer;
    
          correct = isCorrect(problema);
        }

        if(correct)
        {
          right++;
        }
        else
        {
          wrong++;
        }
      }
    }
  
    cout<<"You got "<<right<<" questions right and "<<wrong<<" questions wrong"
        <<endl;    
 
    char playAgain;
    cout<<"Wanna play again?(Y/y/N/n): ";
    cin>>playAgain;
    while(playAgain != 'Y' && playAgain != 'y' && playAgain != 'N' && 
          playAgain != 'n')
    {
      cout<<"Wanna play again(Y/y/N/n): ";
      cin>>playAgain;
    }
    if(playAgain == 'N' || playAgain == 'n')
    {
      done = true;
    }
    else
    {
      done = false;
    }
  }while(!done);
  
  return 54321;
  //Blastoff at the speed of light, surrender now or prepare to fight!
}

