///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 2
// File name:  polarNum.hpp
// Semester:   Spring 2014
///////////////////////////////////////
#include "polarNum.h"
#include "exceptions.h"
#include <iostream>

template <class T>
PolarNum<T>::PolarNum()
{
  m_modulus = 0;
  m_argument = 0;
}

template <class T>
PolarNum<T>::PolarNum(const PolarNum<T>& src)
{
	*this = src;
}

template <class T>
PolarNum<T>::~PolarNum()
{
  delete [] this;
}

template <class T>
T& PolarNum<T>::getMod()
{
  return m_modulus;
}

template <class T>
T& PolarNum<T>::getArg()
{
  return m_argument;
}

template <class T>
void PolarNum<T>::setMod(const T& newMod)
{
  m_modulus = newMod;
}

template <class T>
void PolarNum<T>::setArg(const T& newArg)
{
  m_argument = newArg;
}

template <class T>
T& PolarNum<T>::operator[](const int i)
{
  try
  {
    if( i != 0 || i != 1)
    {
      cerr<<"boring CS308 is boring"<<endl;
      throw;
    }
  }
  catch(OutOfRangeException<T> e)
  {
  }
  if(i == 0)
  {
    return m_modulus;
  }
  
  return m_argument;
}


//overload the operators dude
template <class T>
void PolarNum<T>::operator=(const PolarNum<T>& src)
{
  m_modulus = src.m_modulus;
  m_argument = src.m_argument;
}

template <class T>
void PolarNum<T>::operator-()
{
  m_modulus = -m_modulus;
}

template <class T>
T& PolarNum<T>::operator~()
{
  return abs(m_argument);
}
template <class T>
void PolarNum<T>::operator!()
{
  m_argument = -m_argument;
}

template <class T>
T operator*(const PolarNum<T>& lhs, const PolarNum<T>& rhs)
{
  PolarNum<T> result(lhs);
  return result *= rhs;
}

template <class T>
T& PolarNum<T>::operator*=(const PolarNum<T>& rhs)
{
  m_modulus *= rhs.m_modulus;
  m_argument += rhs.m_argument;
  return *this;
}

template <class T>
T operator+(const PolarNum<T>& lhs, const PolarNum<T>& rhs)
{
  PolarNum<T> result(lhs);
  return result += rhs;
}

template <class T>
T& PolarNum<T>::operator+=(const PolarNum<T>& rhs)
{
  m_modulus += rhs.m_modulus;
  return *this;
}

template <class T>
T operator-(const PolarNum<T>& lhs, const PolarNum<T>& rhs)
{
  PolarNum<T> result(lhs);
  return result -= rhs;
}

template <class T>
T& PolarNum<T>::operator-=(const PolarNum<T>& rhs)
{
  m_modulus -= rhs.m_modulus;
  return *this;
}

template <class T>
T operator/(const PolarNum<T>& lhs, const PolarNum<T>& rhs)
{
  PolarNum<T> result(lhs);
  return result /= rhs;
}

template <class T>
T& PolarNum<T>::operator/=(const PolarNum<T>& rhs)
{
  if(rhs.modulus == 0)
  {
    DivideByZeroException<T> e;
    throw e;
  }
  m_modulus /= rhs.m_modulus;
  m_argument -= rhs.m_argument;
  return *this;
}

template <class T>
bool PolarNum<T>::operator>(const PolarNum<T>& rhs)
{
  return (~(*this)) > (~rhs);
}

template <class T>
bool PolarNum<T>::operator>=(const PolarNum<T>& rhs)
{
  return (~(*this)) >= (~rhs);
}

template <class T>
bool PolarNum<T>::operator<(const PolarNum<T>& rhs)
{
  return (~(*this)) < (~rhs);
}

template <class T>
bool PolarNum<T>::operator<=(const PolarNum<T>& rhs)
{
  return (~(*this)) <= (~rhs);
}

template <class T>
bool PolarNum<T>::operator==(const PolarNum<T>& rhs)
{
    return (m_modulus == rhs.modulus) && (m_argument == m_argument);
}

template <class T>
bool PolarNum<T>::operator!=(const PolarNum<T>& rhs)
{
  return !(*this == rhs);
}

template <class T>
ostream& operator<<(ostream& out, const PolarNum<T> t)
{
  out<<"( " <<t.m_modulus<< ", "<< t.m_argument<< " )"<<endl;
  return out;
}

template <class T>
istream& operator>>(istream& in, const PolarNum<T> t)
{
  in>>t.m_modulus>>t.m_argument;
  return in;
}