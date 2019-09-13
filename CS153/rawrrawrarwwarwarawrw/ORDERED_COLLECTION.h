/*
  author: Lisa Tatro
  date: Oct 14, 2011
  file: ORDERED_COLLECTION.h
*/

#ifndef ORDERED_COLLECTION_H
#define ORDERED_COLLECTION_H

#include "COLLECTION.h"
#include <iostream>
using namespace std;

template <class T>
class ORDERED_COLLECTION: protected COLLECTION<T>
{
  public:
	ORDERED_COLLECTION(): COLLECTION<T>::COLLECTION() {}
	virtual ~ORDERED_COLLECTION() {}
	virtual bool find (const T& x) const = 0;
    virtual void clear() = 0;

};
#endif /* UNORDERED_COLLECTION */
	