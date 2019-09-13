///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  newton.hpp
// Semester:   Spring 2014
///////////////////////////////////////

#include "newton.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
float Newton<T>::getX() const
{
  return x_pos;
}

template <class T>
T Newton<T>::getCoef() const
{
  return coefficient;
}

template <class T>
void Newton<T>::setX(const float& new_x)
{
  x_pos = new_x;
}

template <class T>
void Newton<T>::setCoef(const T& new_coef)
{
  coefficient = new_coef;
}