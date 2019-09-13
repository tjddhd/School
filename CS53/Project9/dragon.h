//Teej Dolan
//CS53, Section 12
//Matt Nuckolls
//dragon.h

#ifndef DRAGON_H
#define DRAGON_H

//test tomorrow, too lazy for commenting
using namespace std;

#include<string>
#include<iostream>
#include"peasant.h"

class Dragon
{
  public:
    Dragon();
 
    Dragon(const int vCons, const int arms, const int maj, const string name, const bool wing);

    Dragon(const Dragon& src);

    void burninate(Peasant& victim, const int majLvl);

    void print(const Dragon d);

    void setVCons(const int v);
    void setArms(const int arms);
    void setMajLvl(const int maj);
    void setName(const string name);
    void setWing(const bool hasWings);
   

  private:
    int m_vCons, m_beefArms, m_majestyLvl;
    string m_name;
    bool m_isWingaling;
};

#endif



