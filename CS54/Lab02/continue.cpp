///////////////////////////////////////////////////
/// @file continue.cpp
/// @author Brian Goldman
/// @brief This file contains compiler error(s).
///        It is your mission to fix them.
///////////////////////////////////////////////////

#include <iostream>
using namespace std;

int main()
{
  // These are variables, used to store information
  int userInput;
  float myNameIsWrongSomewhere;
  
  cout<<"I demand you type an integer and press enter!"<<endl;
  cout<<"\t"<<"Type number here: ";
  cin>>userInput;
  
  cout<<"Your input of "<<userInput<<" is acceptable."<<endl;
  cout<<"Now type a floating point (decimal) number: ";
  cin>>myNameIsWrongSomewhere;
  
  cout<<"What a cool number "<<myNameIsWrongSomewhere<<" is"<<endl;
  return 0;
}
