///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 2
// File name:  norm.h
// Semester:   Spring 2014
///////////////////////////////////////
#ifndef NORM_H
#define NORM_H

#include <vector>
#include <cmath>
#include "polarNum.h"

template <class T>
class norm
{
	public:
		void operator()(vector<T> vect);
};

#include "norm.hpp"

#endif