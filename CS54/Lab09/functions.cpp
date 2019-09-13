//Thomas Dolan
//CS54, 6pm Tue
//Brian Goldman
//functions.hpp

//include files
#include"functions.h"
#include<iostream>
#include<string>

using namespace std;

//greeting and signoff..... I think this program was skewed to give me trouble :P
void greeting()
{
  cout<<"HAI DER USER!!!1!!!!!!1!!11!1!" <<endl;
}
 
void signoff()
{
  cout<<"Bye user.... This program has made me a sad panda :("<<endl;
}

//overloaded function..... the falicibot didn't work :P
ostream& operator<< (ostream& out, const Particle& particle)
{
  out<<"("<<particle.m_xCoord<<", "<<particle.m_yCoord<<"), Mass: "
     <<particle.m_mass<<endl;
  
  return out;
}

//Input function.... My spoon is toooooo big
Particle coordGet()
{
  Particle particle;
  int x, y, mass;

  cout<<"Please enter x coordinate: ";
  cin>>x;

  cout<<"Please enter y coordinate: ";
  cin>>y;

  cout<<"Please enter mass: ";
  cin>>mass;
  
  while(mass < 0)
  {
    cout<<"Please enter valid value: ";
    cin>>mass;
  }

  particle.m_xCoord = x;
  particle.m_yCoord = y;
  particle.m_mass = mass;

  return particle;
}

//centerOfMass function.... Nuckolls is a horrible TA
Particle centerOfMass(const Particle part[], const int num)
{
  float xCoord, yCoord, mass;
  Particle temp;

  for(int i = 0; i < num; i++)
  {
    mass = mass + part[i].m_mass;
    xCoord = xCoord + part[i].m_mass * part[i].m_xCoord;
    yCoord = yCoord + part[i].m_mass * part[i].m_yCoord;
  }
  
  temp.m_xCoord = (xCoord/mass);
  temp.m_yCoord = (yCoord/mass);
  temp.m_mass = mass;
 
  return temp;
}












