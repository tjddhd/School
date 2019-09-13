//Teej Dolan
//CS53, SEction 12
//Matt Nuckolls
//dragon.cpp

//include statements
using namespace std;

#include<iostream>
#include<string>
#include"dragon.h"
#include<stdlib.h>
#include<time.h>

//defualt constructor
Dragon::Dragon()
{
  m_vCons =17;
  m_beefArms = 1;
  m_majestyLvl = 2;
  m_name = "Trogdor";
  m_isWingaling = true;
}

//custom constructor
Dragon::Dragon(const int vCons, const int arms, const int maj, const string nameIn, const bool wing)
{
  m_vCons = vCons;
  m_beefArms = arms;
  m_majestyLvl = maj;
  m_name = nameIn;
  m_isWingaling = wing;
}

//copy constructor
Dragon::Dragon(const Dragon& src)
{
  *this = src;
}

//burninate function
void Dragon::burninate(Peasant& victim, const int majLvl)
{
  bool result = false;
  if(majLvl ==1)
  {
    result = ((rand()/100) > 50);
  }
  else if(majLvl ==2)
  {
    result = ((rand()/100) > 30);
  }
  else if(majLvl ==3)
  {
    result = ((rand()/100) > 10);
  }
  victim.setFire(result);
}

//print function
void Dragon::print(const Dragon d)
{
  cout<<d.m_name<<"has "<<d.m_beefArms<<" arms and a majesty of "<<d.m_majestyLvl<<endl;
}

//mutators
void Dragon::setVCons(const int v)
{
  m_vCons = v;
}

void Dragon::setArms(const int arms)
{
  m_beefArms = arms;
}

void Dragon::setMajLvl(const int maj)
{
  m_majestyLvl = maj;
}

void Dragon::setName(const string nameIn)
{
  m_name = nameIn;
}

void Dragon::setWing(const bool hasWings)
{
  m_isWingaling = hasWings;
}




