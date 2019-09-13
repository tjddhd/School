/* File: container.hpp
 * Author Jennifer Leopold (leopoldj@mst.edu)
 * Description: Implementation of a templated Container class
 */

#include <stdexcept>
#include <iostream>
using namespace std;

template <class T>
Container<T>::Container() { 
  m_size = 0; 
  m_max_size = 20; 
  m_data = new T[m_max_size];
  if (!m_data) throw std::bad_alloc();
}

template <class T>
Container<T>::Container(const Container<T>& copyMe) {
  m_size = copyMe.m_size; 
  m_max_size = copyMe.m_max_size; 
  m_data = new T[m_max_size];
  if (!m_data) throw std::bad_alloc();
  for (int i = 0; i < m_size; i++)
    m_data[i] = copyMe.m_data[i];
}

template <class T>
Container<T>::~Container() { 
  if (m_data != NULL) {
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
 if (m_size == m_max_size)
   throw std::length_error("Container is full");
 
  m_data[m_size]=x;
  m_size++;
  
  if (m_size > (0.5 * m_max_size)) {
    TArrayPtr new_m_data;
    int new_max_size = (int) (m_max_size * 1.2);
    new_m_data = new T[new_max_size];
    if (!new_m_data)
      throw std::bad_alloc();
    for (int i = 0; i < m_size; i++)
      new_m_data[i] = m_data[i];
    delete [] m_data;
    m_data = new_m_data;
    m_max_size = new_max_size;
  }
}

template <class T>
void Container<T>::clear() {
  for (int i = m_size-1; i >= 0; i--) {
    try {
         remove(m_data[i]);
    }
    catch (std::bad_alloc& b) {
      //cout << "Memory allocation failed for remove during clear"; 
      throw std::bad_alloc();
    }
  }
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
  int i = 0;
  bool found = false;
  while ((i < m_size) && (! found)) {
    if (m_data[i] == x) 
      found = true; 
    else i++;
  }
  if (found) {
    for (int j = i; j < m_size-1; j++) {
      m_data[j] = m_data[j+1];
    }
    m_size--;
    
    if (m_size < (0.5 * m_max_size)) {
      TArrayPtr new_m_data;
      int new_max_size = (int) (m_max_size * 0.8);
      new_m_data = new T[new_max_size];
      if (!new_m_data)
        throw std::bad_alloc();
      for (int i = 0; i < m_size; i++)
        new_m_data[i] = m_data[i];
      delete [] m_data;
      m_data = new_m_data;
      /*
      cout << "Remove changed max_size from " << m_max_size 
             << " to " << new_max_size << endl;
      */
      m_max_size = new_max_size;
    }
  }
}

template <class T>
const bool Container<T>::find(const T& x) const
{
  bool found = false;
  for (int i=0; i < m_size && !found; i++)
    found = (m_data[i]==x);
  return found;
}

