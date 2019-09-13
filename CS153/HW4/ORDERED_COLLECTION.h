/*
 * ORDERED_COLLECTION.h
 *
 *  Created on: Oct 14, 2011
 *      Author: THOMAS DOLAN
 */

#ifndef ORDERED_COLLECTION_H_
#define ORDERED_COLLECTION_H_

#include "COLLECTION.h"

template <class T>
class ORDERED_COLLECTION:protected COLLECTION<T>
{
	public:
		ORDERED_COLLECTION(): COLLECTION<T>::COLLECTION() {}
		virtual ~ORDERED_COLLECTION() {}

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

};
#endif /* ORDERED_COLLECTION_H_ */
