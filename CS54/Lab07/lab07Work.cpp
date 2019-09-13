//Thomas Dolan
//CS54, Tues. 6pm
//Brian Goldman
//Lab 07: Dice Rolling

//inlcude statements
#include<iostream>
#include<string>
#include"functions.h"
#include<stdlib.h>
#include<time.h>

using namespace std;

//Main function
int main()
{
  //random seed
  srand(time(NULL));
  
  //greeting, variable declaration and function call
  greetings();
  
  int low =0, high = 0;

  int diceSides = getSides();
 
  int diceRolls = getRolls();
  
  checkFairness(diceSides, diceRolls, low, high);

  //Stats and goodbye message
  cout<<"Number of highs: "<<high<<endl;
  cout<<"Number of lows: "<<low<<endl;
  cout<<"Number of lows more than number of highs: "<<low-high<<endl;

  signoff();
    
  return 0;  
}

