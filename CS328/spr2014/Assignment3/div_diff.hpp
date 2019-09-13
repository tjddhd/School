///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  div_diff.h
// Semester:   Spring 2014
///////////////////////////////////////

#include "div_diff.h"
#include "newton.h"
#include "array.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

//Forward declarations
class MyArray<int>;
class Newton<int>;

template <class T>
void Div_Diff<T>::operator()(MyArray<MyArray<Newton<T> > >& newton)
{
  //get boundary of matrix so it doesn't go out of bounds
  int boundary = newton.getSize();
  
  //gets count of columns, the longer side of the matrix
  int count = newton[0].getSize();
  
  //goes across the matrix
  for(int i = 1; i < count; i++)
  {
    //goes down the matrix
    for(int j = 1; j < boundary; j++)
	{
	  //calcutions using (f(x1) - f(x0))/(x1 - x0) to get f'(x1)
	  newton[j][i].setCoef((newton[j][i].getCoef() - newton[j-1][i].getCoef())/(newton[j][i].getX() - newton[j-1][i-1].getX()) );
	  newton[j][i].setX(j);
	}
  }
}