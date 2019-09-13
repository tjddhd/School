///////////////////////////////////////////////////////////////////////////////
// Programmer :  Thomas Dolan
// Assignment :  Program 2
//
// Instructor :  Clayton Price
// Course     :  CS328
// Semester   :  Spring 2013
///////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <iostream>
#include "Err.h"
using namespace std;

#ifndef QUATERNION_H
#define QUATERNION_H

template<class T>
class Quaternion
{
	public:
		T a, b, c, d;
	
		Quaternion(): a(0),b(0),c(0),d(0) {};
		Quaternion(const T& the_a, const T& the_b, const T& the_c, const T& the_d): a(the_a),b(the_b),c(the_c),d(the_d){};
		Quaternion(const Quaternion<T>& src){*this=src;};
		friend void operator-(const Quaternion<T>& src);
		friend void operator!(const Quaternion<T>& src);
		friend double operator~(const Quaternion<T>& src);
		bool operator==(const Quaternion& rhs);
		bool operator!=(const Quaternion& rhs);
		friend Quaternion operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		friend Quaternion<T>& operator+=(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		friend Quaternion operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		friend Quaternion<T>& operator-=(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		friend Quaternion operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		friend Quaternion<T>& operator*=(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		friend Quaternion operator/(const Quaternion<T>& lhs, const Quaternion<T>& rhs);
		Quaternion<T> inv(const Quaternion<T>& rhs);
		double mag(const Quaternion<T>& src);
		void operator=(const Quaternion<T>& rhs);
		T operator[](const int i);
		friend ostream& operator<<(ostream& out, const Quaternion<T>& src);
};

#endif //QUATERNION_H