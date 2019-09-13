//Thomas Dolan
//CS54, 6pm Tue
//Brian Goldman
//functions.hpp
//Lab 08

//Include statements
#include<iostream>
#include<string>
#include"functions.h"

using namespace std;

//Greeting function
void greeting()
{
  cout<<"Greetings, user! Welcome to the Coordinates Program!"<<endl;
}

//Signoff function
void signoff()
{
  cout<<"See ya later, user!"<<endl;
}

//Templated 2D coordinates function
template<class T>
void outputCoords(const T& xCoord, const T& yCoord)
{
  cout<<"Here's the cooridnates: ("<<xCoord<<", "<<yCoord<<")"<<endl;
}

//Templated 3D coordinates function
template<class T>
void outputCoords(const T& xCoord, const T& yCoord, const T& zCoord)
{
  cout<<"Here's the coordinates: ("<<xCoord<<", "<<yCoord<<", "<<zCoord<<")"<<endl;
}



