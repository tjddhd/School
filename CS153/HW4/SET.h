/*!\file SET.h
 * \author Nathan Eloe
 * \brief a set class based on inheritance
 */

#ifndef SET_H
#define SET_H

#include "UNORDERED_COLLECTION.h"

template <class T>
class SET: protected UNORDERED_COLLECTION<T>
{
  public:
    SET(): m_max_size(20), UNORDERED_COLLECTION<T>::UNORDERED_COLLECTION() {}
    bool find(const T& x) const;
    void insert(const T& x);
    bool remove(const T& x);
    void clear() { COLLECTION<T>::m_size=0;}
    unsigned int maxSize() const  {return m_max_size;}
    SET<T> setUnion (const SET<T>& tounion) const;
    SET<T> setDiff (const SET<T>& todiff) const;
    const T& operator [] (const unsigned int index) const;
    T& operator [] (const unsigned int index);
    bool operator == (const SET<T>& rhs) const;
    SET<T>& operator = (const SET<T>& rhs);
	const unsigned int size() const { return COLLECTION<T>::m_size; }
  protected:
    T m_data[20];
    unsigned int m_max_size;
};

#include "SET.hpp"

#endif