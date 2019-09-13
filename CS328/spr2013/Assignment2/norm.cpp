///////////////////////////////////////////////////////////////////////////////
// Programmer :  Thomas Dolan
// Assignment :  Program 2
//
// Instructor :  Clayton Price
// Course     :  CS328
// Semester   :  Spring 2013
///////////////////////////////////////////////////////////////////////////////

#include "norm.h"
#include "quaternion.h"
#include <stdlib.h>
#include <vector>
using namespace std;

	template<class T>
	void Norm<T>::operator()(vector<T> vect)
	{
		double total = 0;
		for(int i = 0; i < vect.size(); i++)
		{
			total += mag(vect[i]);
		}
	}