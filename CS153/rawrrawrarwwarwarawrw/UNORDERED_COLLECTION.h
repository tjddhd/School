/*
  author: Lisa Tatro
  date: Oct 14, 2011
  file: UNORDERED_COLLECTION.h
*/

#ifndef UNORDERED_COLLECTION_H
#define UNORDERED_COLLECTION_H

#include "COLLECTION.h"
#include <iostream>
using namespace std;

template <class T>
class UNORDERED_COLLECTION: protected COLLECTION<T>
{
  public:
	UNORDERED_COLLECTION(): COLLECTION<T>::COLLECTION() {}
	virtual ~UNORDERED_COLLECTION() {}
	virtual bool find (const T& x) const = 0;
    virtual void clear() = 0;
	virtual void insert (const T& x) = 0;
	virtual bool remove (const T& x) = 0;

};
#endif /* UNORDERED_COLLECTION */
	