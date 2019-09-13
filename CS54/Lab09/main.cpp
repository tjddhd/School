//Thomas Dolan
//CS54, 6pm Tue
//Brian Goldman
//Lab 09: Structs and stuff
//main.cpp

#include<iostream>
#include<string>
#include"functions.h"

using namespace std;

//main function..... bleagh
int main()
{
  //Self-explanatory
  greeting();
  
  //Particle varibles
  Particle coord[3];
  Particle temp;

  //for loop for stuff for you for my grade
  for(int i = 0; i < 3; i++)
  {
    temp = coordGet();
    coord[i].m_xCoord = temp.m_xCoord;
    coord[i].m_yCoord = temp.m_yCoord;
    coord[i].m_mass = temp.m_mass;
  }

  //overload call
  Particle centerMass = centerOfMass(coord, 3);

  //formatted output
  cout<<centerMass<<endl;
  
  signoff();

  return 3210;
}

