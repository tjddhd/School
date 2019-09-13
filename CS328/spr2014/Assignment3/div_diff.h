///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  div_diff.h
// Semester:   Spring 2014
///////////////////////////////////////

#ifndef DIV_DIFF_H
#define DIV_DIFF_H

#include "stdlib.h"
#include "newton.h"
#include "array.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
class Div_Diff
{
  public:
  
    //Pre: You are given an allocated 2D Array of Newtons
	//Post: Calculates the divided difference table of the Newton polynomial
	//Desc: Calculates the divided difference table using the newton polynomial
	//      form of the interpolation polynomial. 
	//      Formula is (f(x1) - f(x0))/(x1 - x0) to get f'(x1)
    void operator()(MyArray<MyArray<Newton<T> > >& newton);
};

#include "div_diff.hpp"

#endif