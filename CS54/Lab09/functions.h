//Thomas Dolan
//CS54, 6pm Tue
//Brian Goldman
//functions.h

using namespace std;

//guardy guardy guard
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//include include include
#include<iostream>
#include<string>

//struct stuff
struct Particle
{
  float m_xCoord;
  float m_yCoord;
  float m_mass;
};

//Desc: Gets input from user on particle info
//Pre:  None
//Post: Gives program a filled value particle
Particle coordGet();

//Desc: Finds the center of mass of an array of particles
//Pre:  Array is filled
//Post: Ouputs center of mass
Particle centerOfMass(const Particle coord[], const int num);

//Desc: Formats and outputs the info for a Particle variable
//Pre:  Particle is filled with values
//Post: Lets cout handle the Particle struct output
ostream& operator<<(ostream& out, const Particle& particle);

//Desc: LOLOLOL greeting
//Pre: TROLOLOL none
//Post: FALALALA greeting outputted
void greeting();

//Desc: LOLOLOL signoff
//Pre: TROLOLOL none
//Post: FALALALA signoff outputted
void signoff();

#endif

