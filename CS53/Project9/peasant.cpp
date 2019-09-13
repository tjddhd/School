//Teej Dolan
//CS53, SEction 12
//Matt Nuckolls
//peasant.cpp

//include statements
using namespace std;

#include<iostream>
#include"peasant.h"
#include<string>
#include<stdlib.h>
#include<time.h>

//default
Peasant::Peasant()
{
  m_name = "default";
  m_weight = rand()/100;
  m_onFire = false;
  m_isAlive = true;
}

//custom constructor
Peasant::Peasant(const string nameIn, const double fat, const bool fyre, const bool dead)
{
  m_name = nameIn;
  m_weight = fat;
  m_onFire = fyre;
  m_isAlive = dead;
}

//copy constructor
Peasant::Peasant(const Peasant& src)
{
  *this = src;
}

//increments weight
void Peasant::eat(Peasant& bob)
{
  bob.m_weight = bob.m_weight + 1;
}

//decrements weight
void Peasant::starve(Peasant& bob)
{
  bob.m_weight = bob.m_weight - 1;
}

//prints a peasant
void Peasant::print(const Peasant p)
{
  cout<<p.m_name<<"has a weight of "<<p.m_weight<<endl;
}

//assesors
string Peasant::getName() const
{
  return m_name;
}

float Peasant::getWeight() const
{
  return m_weight;
}

bool Peasant::getFire() const
{
  return m_onFire;
}

bool Peasant::getLife() const
{
  return m_isAlive;
}

//mutators
void Peasant::setName(const string nameIn)
{
  m_name = nameIn;
}

void Peasant::setWeight(const double weightIn)
{
  m_weight = weightIn;
}

void Peasant::setFire(const bool fyre)
{
  m_onFire = fyre;
}

void Peasant::setAlive(const bool living)
{
  m_isAlive = living;
}


