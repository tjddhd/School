///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  array.hpp
// Semester:   Spring 2014
///////////////////////////////////////

#include "array.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
T& MyArray<T>::operator[](const int& i)
{
  return ptr_to_data[i];
}

template <class T>
int MyArray<T>::getSize() const
{
  return m_size;
}

template <class T>
void MyArray<T>::setSize(const int& size)
{
  if(size != m_size)
  {
    delete [] ptr_to_data;;
	m_size = size;
	ptr_to_data = new T[size];
  }
}
	
template <class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& src) 
{
  if(ptr_to_data != src.ptr_to_data)
  {
    setSize(src.m_size);
	array_copy(src);
  }
  
  return (*this);
}

template <class T>
void MyArray<T>::array_copy(const MyArray<T>& src)
{
  T* p = ptr_to_data + m_size;
  T* q = src.ptr_to_data + m_size;
  
  while(p > ptr_to_data)
  {
    for(int i = 0; i < m_size; ++i)
	{
	  ptr_to_data[i] = src.ptr_to_data[i];
	}
  }
}

template <class T>
ostream& operator<<(ostream& out, const MyArray<T>& a)
{
  for(int i =0; i < a.getSize(); i++)
    out << "[ " << a.ptr_to_data[i] << " ]" <<endl;
	
  return out;
}
