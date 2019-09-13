/*
 * UNORDERED_COLLECTION.h
 *
 *  Created on: Oct 14, 2011
 *      Author: THOMAS DOLAN
 */

#ifndef UNORDERED_COLLECTION_H_
#define UNORDERED_COLLECTION_H_

#include "COLLECTION.h"
#include <iostream>
using namespace std;

template <class T>
class UNORDERED_COLLECTION:protected COLLECTION<T>
{
  public:
	UNORDERED_COLLECTION(): COLLECTION<T>::COLLECTION() {}
	virtual ~UNORDERED_COLLECTION() {}

	//Purpose: searches the collection for x
	//Parameters: T reference variable x
	//Post: returns true if found in collection
	virtual bool find (const T& x) const = 0;
	
	//Purpose: clears the collection
	//Parameters: none
	//Post: collection has been cleared
	virtual void clear() = 0;
	
	//Purpose: checks if collection is empty
	//Parameters: none
	//Post: returns whether the collection is empty or not
	virtual bool isEmpty()const {return (COLLECTION<T>::m_size == 0);};
	
	//Purpose: returns current size of collection
	//Parameters: none
	//Post: returns current size of collection
	virtual const unsigned int size() const {return COLLECTION<T>::m_size;};
	
	//Purpose: inserts x into collection
	//Parameters: T reference variable x
	//Post: x is now in collection, size has been incremented
	virtual void insert (const T& x) = 0;
	
	//Purpose: removes x from the collection
	//Parameters: T reference variable x
	//Post: x is not in collection, size has been decremented
	virtual bool remove (const T& x) = 0;
};

#endif /* UNORDERED_COLLECTION_H_ */
