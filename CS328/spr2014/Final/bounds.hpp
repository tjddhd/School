#include "bounds.h"

template <class T, T T_function(T)>
T Bounds<T,T_function>::getUpperX()
{
  if(upperX == NULL)
  {
    cout << "Nothing in Upper X bound"<< endl;
  }
  return upperX;
}

template <class T, T T_function(T)>
T Bounds<T,T_function>::getUpperY()
{
  if(upperY == NULL)
  {
    cout << "Nothing in Upper Y bound"<< endl;
  }
  return upperY;
}

template <class T, T T_function(T)>
T Bounds<T,T_function>::getLowerX()
{
  if(lowerX == NULL)
  {
    cout << "Nothing in Lower X bound"<< endl;
  }
  return lowerX;
}

template <class T, T T_function(T)>
T Bounds<T,T_function>::getLowerY()
{
  if(lowerY == NULL)
  {
    cout << "Nothing in Lower Y bound"<< endl;
  }
  return lowerY;
}

template <class T, T T_function(T)>
void Bounds<T,T_function>::setUpperX(const T& a)
{
  upperX = a;
}

template <class T, T T_function(T)>
void Bounds<T,T_function>::setUpperY(const T& a)
{
  upperY = a;
}

template <class T, T T_function(T)>
void Bounds<T,T_function>::setLowerX(const T& a)
{
  lowerX = a;
}

template <class T, T T_function(T)>
void Bounds<T,T_function>::setLowerY(const T& a)
{
  lowerY = a;
}


template <class T, T T_function(T)>
double Bounds<T,T_function>::integrate(double a, double b, int numPts)
{
  double delta = (b-a)/(numPts-1), sum =0;
  for(int i = 0; i < numPts; i++)
    sum += T_function(a + i*delta);
  return sum*(b-a)/numPts;
}

