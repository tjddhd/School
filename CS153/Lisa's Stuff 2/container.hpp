/* File: container.hpp
 * Author: Thomas Dolan
 * Description: Definition of a templated container class 
 *              that uses dynamic memory allocation
 */

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
Container<T>::Container() { 
  // *** YOU NEED TO WRITE THIS! 
  m_size = 0;
  m_max_size = 20;
  m_data = new T[20];
  if(!m_data)
    throw std::bad_alloc("Not enough space");
}

template <class T>
Container<T>::Container(const Container<T>& copyMe) {
  // *** YOU NEED TO WRITE THIS! 
  m_size = copyMe.m_size
  m_max_size = copyMe.m_max_size
  m_data = new T[m_max_size];
  if(!m_data)
    throw std::bad_alloc("Not enough space");
  for(int i = 0;i < m_size;i++)
    m_data[i] = copyMe.m_data[i];
}

template <class T>
Container<T>::~Container() { 
  // *** YOU NEED TO WRITE THIS!  
  if(m_data != NULL) 
  {
    delete [] m_data;
    m_data = NULL;
  }
  m_size = 0;
}

template <class T>
unsigned int Container<T>::size() const { return m_size; }

template <class T>
unsigned int Container<T>::max_size() const { return m_max_size; }

template <class T>
void Container<T>::insert(const T& x) {
  // *** YOU NEED TO WRITE THIS! 
  if(m_size == m_max_size)
    throw std::length_error("No more room");
  m_data[m_size] = x;
  m_size++;
  if(m_size > (0.5 * m_max_size))
  {
    int new_size = m_max_size * 1.2
    TArrayPtr new_data;
    temp_data = new T[new_size];
    if(!temp_data)
      throw std::bad_alloc("Not enough space");
    for(int i = 0;i < m_size; i++)
      temp_data[i] = m_data[i];
    delete [] m_data;
    m_data = temp_data;
    m_max_size = new_size;
  }
}

template <class T>
void Container<T>::clear() {
  // *** YOU NEED TO WRITE THIS! 
  for(int i = m_size-1; i > 0; i--)
  {
	  try
	  {
		  remove(m_data[i]);
	  }
	  catch(std::bad_alloc e)
	  {
		  cout<<"Not enough memory can be allocated"<<endl;
		  throw e;
	  }
  }
  m_size = 0;
}

template <class T>
T& Container<T>::operator[] (unsigned int i) {
  if (i >= m_size)
    throw std::out_of_range("i<0 or i>=m_size");
  return m_data[i];
}

template <class T>
const T& Container<T>::operator[] (unsigned int i) const {
  if (i >= m_size)
    throw std::out_of_range("i<0 or i>=m_size");
  return m_data[i];
}

template <class T>
void Container<T>::remove(const T& x) {
  // *** YOU NEED TO WRITE THIS! 
  bool found = false;
  for(int i =0; i < m_size && !found; i++)
  {
	  if(m_data[i] == x)
		  found = true;
  }

  if(found)
  {
	  for(int j = i; j <m_size-1; j++)
	  {
		  m_data[j] = m_data[j+1];
	  }
	  m_size--;

	  if (m_size < (0.5 * m_max_size))
	  {
		  int new_size = (m_max_size * 0.8);
		  TArrayPtr new_data;
		  new_data = new T[new_size];
		  if(!new_data)
		     throw std::bad_alloc("Not enough space");
		  for(int k = 0; k < m_size; k++)
			  new_data[k] = m_data[k];
		  delete [] m_data;
		  m_data = new_data;
		  m_max_size = new_size;
	  }
  }
}

template <class T>
const bool Container<T>::find(const T& x) const {
  // *** YOU NEED TO WRITE THIS! 
  bool found = false;
  for(int i = 0; i <m_size && !found; i++)
  {
	  found =(m_data[i]==x);
  }
  return found;
}

