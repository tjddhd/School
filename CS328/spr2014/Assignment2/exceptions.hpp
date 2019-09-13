///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 2
// File name:  exceptions.hpp
// Semester:   Spring 2014
///////////////////////////////////////
#include "exceptions.h"
#include <iostream>

using namespace std;

template <class T>
OutOfRangeException<T>::OutOfRangeException(int i)
{
  cout<< "You did not give a valid index value" <<endl;
}

template <class T>
DivideByZeroException<T>::DivideByZeroException()
{
  cout<< "You cannot divide by zero" <<endl;
}