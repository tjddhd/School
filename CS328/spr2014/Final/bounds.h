#ifndef BOUNDS_H
#define BOUNDS_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T, T T_function (T)>
class Bounds
{
  public:
    
	T getUpperX();
	T getUpperY();
	T getLowerX();
	T getLowerY();
	void setUpperX(const T& a);
	void setUpperY(const T& a);
	void setLowerX(const T& a);
	void setLowerY(const T& a);
	
	double integrate(double a, double b, int numPts);
	
  private:
    T upperX, lowerX, upperY, lowerY;
};


double upperXFunction(double x)
{
  return 0;
}

double upperYFunction(double x)
{
  return 0;
}

double lowerXFunction(double x)
{
  return 1 - 4*((x-.5)*(x-.5));
}

double lowerYFunction(double x)
{ 
  return 0;
}

#include "bounds.hpp"

#endif