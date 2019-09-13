///////////////////////////////////////////////////////////////////////////////
// Programmer :  Thomas Dolan
// Assignment :  Program 2
//
// Instructor :  Clayton Price
// Course     :  CS328
// Semester   :  Spring 2013
///////////////////////////////////////////////////////////////////////////////

#include "quaternion.h"
#include <stdlib.h>
#include <vector>

#ifndef NORM_H
#define NORM_H
using namespace std;

template<class T>
class Norm
{
	public: 
		void operator()(vector<T> vect);
		
};

#endif //NORM_H