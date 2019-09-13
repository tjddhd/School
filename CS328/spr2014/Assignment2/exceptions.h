///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 2
// File name:  exceptions.h
// Semester:   Spring 2014
///////////////////////////////////////
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

template <class T>
class OutOfRangeException
{
  public:
    OutOfRangeException(int i);
};

template <class T>
class DivideByZeroException
{
  public:
    DivideByZeroException();
};

#include "exceptions.hpp"

#endif