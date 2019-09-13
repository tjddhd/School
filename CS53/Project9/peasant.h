//TJ Dolan
//CS53, Section 12
//Matt Nuckolls
//peasant.h

//still got a test tomrrow
#ifndef PEASANT_H
#define PEASANT_H

using namespace std;

#include<iostream>
#include<string>

class Peasant
{
  public:
    Peasant();

    Peasant(const string nameIn, const double fat, const bool fyre, const bool dead);

    Peasant(const Peasant& src);

    void eat(Peasant& bob);
  
    void starve(Peasant& bob);
 
    void print(const Peasant p);

    string getName() const;
    float getWeight() const;
    bool getFire() const;
    bool getLife() const;

    void setName(const string nameIn);
    void setWeight(const double weightIn);
    void setFire(const bool fyre);
    void setAlive(const bool living);

  private:
    string m_name;
    double m_weight;
    bool m_onFire, m_isAlive;
};

#endif

