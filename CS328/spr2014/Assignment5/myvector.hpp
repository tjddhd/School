///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  array.hpp
// Semester:   Spring 2014
///////////////////////////////////////

#include "myvector.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
T& MyVector<T>::operator[](const int& i)
{
  return ptr_to_data[i];
}

template <class T>
int MyVector<T>::getSize() const
{
  return m_size;
}

template <class T>
void MyVector<T>::setSize(const int& size)
{
  if(size != m_size)
  {
    //delete [] ptr_to_data;
	//commented out because double free errors
	m_size = size;
	ptr_to_data = new T[size];
  }
}
	
template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& src) 
{
  if(ptr_to_data != src.ptr_to_data)
  {
    setSize(src.m_size);
	array_copy(src);
  }
  
  return (*this);
}

template <class T>
void MyVector<T>::operator+=(const MyVector<T>& rhs)
{
  if(getSize() != rhs.getSize())
  {
    cout<<"Size mismatch"<<endl;
	return;
  }
  
  for(int i = 0; i < rhs.getSize(); i++)
  {
    ptr_to_data[i]+= rhs.ptr_to_data[i];
  }
}

template <class T>
MyVector<T> operator+(const MyVector<T>& lhs, const MyVector<T>& rhs)
{
  MyVector<T> temp(lhs);
  temp += rhs;
  return temp;
}

template <class T>
void MyVector<T>::operator-()
{
  for(int i = 0; i < getSize(); i++)
  {
    ptr_to_data[i] = -ptr_to_data[i];
  }
}

template <class T>
MyVector<T> operator-(const MyVector<T>& lhs, const MyVector<T>& rhs)
{
  MyVector<T> temp(lhs);
  temp -= rhs;
  return temp;
}

template <class T>
void MyVector<T>::operator-=(const MyVector<T>& rhs)
{
  -rhs;
  *this += rhs;
}

template <class T>
void MyVector<T>::array_copy(const MyVector<T>& src)
{
  T* p = ptr_to_data + m_size;
  T* q = src.ptr_to_data + m_size;
  
  while(p > ptr_to_data)
  {
    *--p=*--q;
  }
}

template <class T>
ostream& operator<<(ostream& out, const MyVector<T>& a)
{
  for(int i =0; i < a.getSize(); i++)
    out << "[ " << a.ptr_to_data[i] << " ]";
	
  return out;
}
