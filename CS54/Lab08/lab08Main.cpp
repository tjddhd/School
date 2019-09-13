//Thomas Dolan
//CS54, 6pm Tue
//Brian Goldman
//Lab 08: Templated and Overloaded Functions

//Include statements
#include<iostream>
#include<string>
#include"functions.h"

using namespace std;

//main funciton
int main()
{
  //Greeting
  greeting();

  //Coordinates thing
  outputCoords(17, 3);
  outputCoords<string>("-6i", "9+2i");
  outputCoords(2.7, -4.5, 6.2);
  outputCoords<string>("i", "192i", "4");

  //Signoff
  signoff();

  return 0;
}

