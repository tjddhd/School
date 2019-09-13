///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 2
// File name:  polarNum.h
// Semester:   Spring 2014
///////////////////////////////////////
#ifndef POLARNUM_H
#define POLARNUM_H

#include <iostream>

using namespace std;

template <class T>
class PolarNum
{
  private:
   T m_modulus, m_argument;
  public:
	PolarNum();
	PolarNum(const PolarNum<T>& src);
	~PolarNum();
	T& getMod();
	T& getArg();
	void setMod(const T& newMod);
	void setArg(const T& newArg);
	T& operator[](const int i);
	void operator=(const PolarNum<T>& src);
	void operator-();
	T& operator~();
	void operator!();
			
			
	friend T operator*(const PolarNum<T>& lhs, const PolarNum<T>& rhs);
	T& operator*=(const PolarNum<T>& rhs);
	friend T operator+(const PolarNum<T>& lhs, const PolarNum<T>& rhs);
	T& operator+=(const PolarNum<T>& rhs);
	friend T operator-(const PolarNum<T>& lhs, const PolarNum<T>& rhs);
	T& operator-=(const PolarNum<T>& rhs);
	friend T operator/(const PolarNum<T>& lhs, const PolarNum<T>& rhs);
	T& operator/=(const PolarNum<T>& rhs);
	
	
	bool operator>(const PolarNum<T>& rhs);
	bool operator>=(const PolarNum<T>& rhs);
	bool operator<(const PolarNum<T>& rhs);
	bool operator<=(const PolarNum<T>& rhs);
	bool operator==(const PolarNum<T>& rhs);
	bool operator!=(const PolarNum<T>& rhs);
	
	friend ostream& operator<<(ostream& out, const PolarNum<T> t);
	friend ostream& operator>>(ostream& out, const PolarNum<T> t);
};

#include "polarNum.hpp"

#endif