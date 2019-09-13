#ifndef CHEBYSHEV_H
#define CHEBYSHEV_H

#include <cmath>
#include <vector>

using namespace std;

template <class T>
class Chebyshev
{
  private:
  public:
  
  //Pre: Sufficient memory space
  //Post: Creates an empty Chebyshev object
  //Desc: Default Constructor for Chebyshev
  Chebyshev() {}
  
  //Pre: A predefined double vector
  //Post: A double vector
  //Desc: Creates a double vector of Chebyshev points given a vector of nodes
  vector<double> data_pts(vector<double>& in);
};

#include "chebyshev.hpp"
#endif