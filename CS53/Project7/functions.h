//Teej Dolan
//CS53, Section Cobol
//Matthew Nurckools
//functions.h

//Guard statements and include statements
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<string>

using namespace std;

//Problem struct that allows for quiz to output stats
struct Problem
{
  int m_operand1;
  int m_operand2;
  int m_answer;
  char m_operator;
};

//Desc: greethe user
//Pre:  none
//Post: user greeted
void greeting();

//Desc: displays menu for user to select difficulty
//Pre:  none
//Post: menu has been displayed
int menu();

//Desc: determines the operator used when the random choice is selected
//Pre:  user has selected the random option
//Post: operator has been randomly chosen and reassigned
char operatorDecider(int a);

//Desc: checks if user's answer is correct
//Pre:  user answers with correct types 
//Post: bool is returned detemining if user is correct
bool isCorrect(Problem a);

//Desc: overloads the << operator so a problem can be displayed
//Pre:  none
//Post: << operator has been overloaded to allow display of problem
ostream& operator<<(ostream& out, const Problem& problem);

#endif


