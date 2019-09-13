//Teej Dolan
//CS53, Section Seafoam Green
//Matt Nuckolls
//Project 6: Project 4, but with functions (cuz we're original)
//laTarea6.cpp

//include statements
#include"functions.h"
#include<iostream>
#include<string>

using namespace std;

//main funciton and shit
int main()
{
  //variable declarations
  bool done = false, firstSelected, secondSelected;
  int studentID, assets = 0, aid = 0;
  greeting();

  //Loop and shit
  do
  {
    int choice = menu();
    
    if(choice != 5)
    {
      evaluator(choice, firstSelected, secondSelected, studentID, assets, aid); 
    }
    else
    {
      done = true;
    }
  }while(!done); 

  //signoff and shit
  signoff();
  
  //I return 4 because that's what all the cool kids are doing
  return 4;

  //Let's SegFault just for the fun of it :P
  //return main;
}


