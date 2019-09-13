/* File: set.hpp
 * Author Lisa Tatro
 * Description: Implementation of a templated Set class
 *Date: 9/2/2011
 *Class: CS153  1A
 */

#include <stdexcept>

template <class T>
Set<T>::Set() { m_size = 0; m_max_size = 20; }

template <class T>
unsigned int Set<T>::size() const { return m_size; }

template <class T>
unsigned int Set<T>::max_size() const { return m_max_size; }

template <class T>
void Set<T>::insert(const T& x)
{
  if (m_size == m_max_size)
    throw std::length_error("Set is full");
  if (!find(x))
   {
    m_data[m_size]=x;
    m_size++;
   }
}

template <class T>
void Set<T>::clear()
{
  m_size = 0;
}

template <class T>
T& Set<T>::operator[] (unsigned int i)
{
  //if ((i >= m_size) || (i < 0))
      if (i >= m_size)
    throw std::out_of_range("i<0 or i>=m_size");
  return m_data[i];
}

template<class T>
Set<T> Set<T>::set_union(const Set<T>& s1) const
{
   int i = 0;
   Set <T> temp = *this;
   //if  there are too many elements then insert will throw the length error
   while( i < s1.size() )
   {
      temp.insert( s1[i]);
	  i++;
	}
	return temp;
	
}

template<class T>
Set<T> Set<T>::set_diff(const Set<T>& s1) const
{
   int i = (s1.size() -1);
   Set <T> temp = *this;
   
   while( i >= 0)
   {
      temp.remove( s1[i]);
	  i--;
	}
	return temp;
}

template <class T>
const T& Set<T>::operator[] (unsigned int i) const
{
  //if ((i >= m_size) || (i < 0))
      if (i >= m_size)
          throw std::out_of_range("i<0 or i>=m_size");
  return m_data[i];
}

template <class T>
bool Set<T>::find(const T& x) const
{
  int i = 0;
  bool found = false;
  while ((i < m_size) && (! found)) {
    if (m_data[i] == x) 
      found = true; 
    else i++;
  }
  return found;
}


template <class T>
void Set<T>::remove(const T& x) 
{
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
  }
}

