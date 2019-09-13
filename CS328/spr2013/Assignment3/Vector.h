//////////////////////////////////////////
// Name: Thomas Dolan
// Date 3/6/13
// Assignment 3 - Gram-Schmidt Process
// Professor: Clayton Price
// File: Vector.h
//////////////////////////////////////////
#include <vector>
#include <iostream>
using namespace std;

#ifndef VECTOR_H
#define VECTOR_H

template<unsigned int def>
class Vector
{
	public:
		Vector(){	for(int i =0;i<def;i++)
						components[i] = 0;	};
		Vector(const Vector& src);
		void setComponent(float num, int index);
		
		template <unsigned int fed>
		friend ostream& operator<<(ostream& out, const Vector<fed>& src);
		
		float components[20];
		
};

#endif //VECTOR_H