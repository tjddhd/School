///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  driver.cpp
// Semester:   Spring 2014
///////////////////////////////////////

#include "array.h"
#include "newton.h"
#include "div_diff.h"
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

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    cout << "It didn't work right"<< endl;
  }
  else
  {
    ifstream file(argv[1]);
	
	int count = 0;
	float in1 = 0;
	double in2 = 0;
	file >> count;

	MyArray<MyArray<Newton<double> > > test;
	test.setSize(count);
	
	//padding
	for( int i = 0; i < count + 2; i++)
	  test[i].setSize(count+2);
	
	for( int i = 0; i < count; i++)
	{
	  file >> in1 >> in2;
	  test[0][i].setX(in1);
	  test[0][i].setCoef(in2);
	}
	
	Div_Diff<double> calc;
	calc(test);
	
	
	file.close();
  }
  return 0;
}