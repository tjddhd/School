#ifndef GENERATOR_H
#define GENERATOR_H

#define PI 3.14159

#include <cmath>
#include <vector>

using namespace std;

template <class T>
class Generator
{
  private:
  public:
  //Pre: Sufficient memory space
  //Post: Creates an empty Geenrator object
  //Desc: Default Constructor for Geenrator
  Generator() {}
  
  //Pre: A predefined double vector
  //Post: A double vector
  //Desc: Creates a double vector of nodes given a vector of intital points
  vector<double> node_generator(vector<double>& in);
};

#include "generator.hpp"

#endif