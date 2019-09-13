/*!\file SET.hpp
 * \author Nathan Eloe
 * \brief implementation of a set class
 */

#include <stdexcept>

template <class T>
bool SET<T>::find(const T& x) const
{
  for (int i=0; i<COLLECTION<T>::m_size; i++)
  {
    if (m_data[i] == x)
      return true;
  }
  return false;
}

template <class T>
void SET<T>::insert(const T& x)
{
  if (!find(x))
  {
    if (COLLECTION<T>::m_size==m_max_size)
    {
      throw std::length_error("set is full");
    }
    m_data[COLLECTION<T>::m_size]=x;
    COLLECTION<T>::m_size++;
  }
}

template <class T>
bool SET<T>::remove(const T& x)
{
  int index=0;
  for (; index < COLLECTION<T>::m_size && 
         m_data[index]!=x; index++);
  if (index < COLLECTION<T>::m_size)
  {
    for (int i=index+1; i < COLLECTION<T>::m_size; i++)
      m_data[i-1]=m_data[i];
    COLLECTION<T>::m_size--;
  }
  return (index < COLLECTION<T>::m_size);
}

template <class T>
SET<T> SET<T>::setUnion (const SET<T>& tounion) const
{
  SET<T> toret=*this;
  for (int i=0; i<tounion.size(); i++)
    toret.insert(tounion.m_data[i]);
  return toret;
}

template <class T>
SET<T> SET<T>::setDiff (const SET<T>& todiff) const
{
  SET<T> toret(*this);
  for (int i=0; i<todiff.size(); i++)
    toret.remove(todiff.m_data[i]);
  return toret;
}

template <class T>
const T& SET<T>::operator [] (const unsigned int index) const
{
  if (index>=COLLECTION<T>::m_size)
    throw std::out_of_range("index out of range");
  return m_data[index];
}

template <class T>
T& SET<T>::operator [] (const unsigned int index)
{
  if (index>=COLLECTION<T>::m_size)
    throw std::out_of_range("index out of range");
  return m_data[index];
}

template <class T>
bool SET<T>::operator == (const SET<T>& rhs) const
{
  if (COLLECTION<T>::m_size!=rhs.size())
    return false;
  for (int i=0; i<rhs.size(); i++)
  {
      if (!find(rhs[i]))
        return false;
  }
  return true;
}

template <class T>
SET<T>& SET<T>::operator = (const SET<T>& rhs)
{
  COLLECTION<T>::m_size=rhs.size();
  for (int i=0; i<rhs.size(); i++)
    m_data[i]=rhs[i];
  return *this;
} 
