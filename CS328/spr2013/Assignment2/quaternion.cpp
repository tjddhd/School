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
#include <math.h>
#include <iostream>
using namespace std;

	template<class T>
	void operator-(const Quaternion<T>& src)
	{
		src.a = -src.a;
		src.b = -src.b;
		src.c = -src.c;
		src.d = -src.d;
	}
	
	template<class T>
	void operator!(const Quaternion<T>& src)
	{
		src.b = -src.b;
		src.c = -src.c;
		src.d = -src.d;
	}
	
	template<class T>
	double operator~(const Quaternion<T>& src)
	{
		return sqrt(src.a*src.a + src.b*src.b + src.c*src.c + src.d*src.d);
	}
	
	template<class T>
	bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		return (lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d);
	}
	
	template<class T>
	bool operator!=(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		return !(lhs == rhs);
	}
	
	template<class T>
	Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		Quaternion<T> result(lhs);
		return result += rhs;
	}
	
	template<class T>
	Quaternion<T>& operator+=(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		lhs.a += rhs.a;
		lhs.b += rhs.b;
		lhs.c += rhs.c;
		lhs.d += rhs.d;
		return lhs;
	}
	
	template<class T>
	Quaternion<T> operator-(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		Quaternion<T> result(lhs);
		return result + (-rhs);
	}
	
	template<class T>
	Quaternion<T>& operator-=(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		lhs.a -= rhs.a;
		lhs.b -= rhs.b;
		lhs.c -= rhs.c;
		lhs.d -= rhs.d;
		return lhs;
	}
	
	template<class T>
	Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		Quaternion<T> result(lhs);
		return result *= rhs;
	}
	
	template<class T>
	Quaternion<T>& operator*=(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		T temp_a = lhs.a, temp_b = lhs.b, temp_c = lhs.c, temp_d = lhs.d;
		lhs.a = temp_a*rhs.a - temp_b*rhs.b - temp_c*rhs.c - temp_d*rhs.d;
		lhs.b = temp_a*rhs.b + temp_b*rhs.a + temp_c*rhs.d - temp_d*rhs.c;
		lhs.c = temp_a*rhs.c - temp_b*rhs.d + temp_c*rhs.a + temp_d*rhs.b;
		lhs.d = temp_a*rhs.d + temp_b*rhs.c - temp_c*rhs.b + temp_d*rhs.a;
		return lhs;
	}
	
	template<class T>
	Quaternion<T> operator/(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		Quaternion<T> result(lhs);
		return result * inv(rhs);
	}
	
	template<class T>
	Quaternion<T> inv(const Quaternion<T>& rhs)
	{
		Quaternion<T> result(rhs);
		result.a = 1/rhs.a;
		result.b = 1/rhs.b;
		result.c = 1/rhs.c;
		result.d = 1/rhs.d;
		return result;
	}
	
	template<class T>
	double mag(const Quaternion<T>& src)
	{
		return ~src;
	}
	
	template<class T>
	void Quaternion<T>::operator=(const Quaternion<T>& rhs)
	{
		(*this).a = rhs.a;
		(*this).b = rhs.b;
		(*this).c = rhs.c;
		(*this).d = rhs.d;
	}
	
	template<class T>
	T Quaternion<T>::operator[](const int i)
	{
		T index;
		switch(i)
		{
			case(0):
			{	
				index = a;
				break;
			}
			case(1):
			{
				index = b;
				break;
			}
			case(2):
			{
				index = c;
				break;
			}
			case(3):
			{
				index = d;
				break;
			}
			default:
			{
				throw RangeErr e;
				break;
			}
		}
		return index;
	}
	
	template<class T>
	ostream& operator<<(ostream& out, const Quaternion<T>& src)
	{
		out<<src.a<<" + "<<src.b<< "i + "<<src.c<<"j + "<<"k"<<endl;
		return out;
	}