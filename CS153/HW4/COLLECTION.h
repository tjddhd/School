/*
 * COLLECTION.h
 *
 *  Created on: Oct 14, 2011
 *      Author: Owner
 */

#ifndef COLLECTION_H_
#define COLLECTION_H_

template <class T>
class COLLECTION
{
  public:
	COLLECTION(): m_size(0) {}
	virtual ~COLLECTION() {}

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
	virtual bool isEmpty()const {return (m_size == 0);};
	
	//Purpose: returns current size of collection
	//Parameters: none
	//Post: returns current size of collection
	virtual const unsigned int size() const {return m_size;};
	
	unsigned int m_size;
};

#endif /* COLLECTION_H_ */
