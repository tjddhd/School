/*
  author: Lisa Tatro
  date: Oct 14, 2011
  file: COLLECTION.h
*/

#ifndef COLLECTION_H
#define COLLECTION_H
#include <iostream>
using namespace std;

template <class T>
class COLLECTION
{
  public:
    unsigned int m_size;
	
    COLLECTION(): m_size(0) {}
	virtual ~COLLECTION() {}
    virtual bool find (const T& x) const = 0;
    virtual void clear() = 0;
	
	// Purpose:  To identify if the collection is empty
    // Parameters: no parameters
    // Postconditions: bool returned true if empty
    virtual bool isEmpty() const { return (m_size ==0); }
	
	//Purpose:To get the size of the collection
	//Parameters: no parameters
	//Postconditions: returns the size of collection
    virtual const unsigned int size() const { return m_size; }

};
#endif /* COLLECTION_H*/
