/*
 * STACK.h
 *
 *  Created on: Oct 14, 2011
 *      Author: Thomas Dolan
 */

#ifndef STACK_H_
#define STACK_H_

#include "NODE.h"
#include "LINKED_LIST.h"

template <class T>
class STACK:protected LINKED_LIST<T>
{
  public:

    STACK(): LINKED_LIST<T>::LINKED_LIST() {}
	
	~STACK() {}

	// Purpose: return a reference to the element currently on top of the stack
	// Exceptions: if the stack is currently empty, throw a length_error
	// exception 
	const T& top() const;

	// Purpose: insert the specified element at the top of the stack
	// Parameters: x is the value to insert at the top of the stack
	// Postconditions: x is now the element at the top of the stack, and
	// current size of the collection has been increased by 1
	void push(const T& x);

	// Purpose: remove the element at the top of the stack
	// Postconditions: the element formerly at the top of the stack has
	// been removed, and current size of the collection has been decreased 
	// by 1
	// Exceptions: if the stack is currently empty, throw a length_error
	// exception 
	void pop();
	
	//Purpose: asserts if this stack and ths stack are equal
	//Parameters: rhs stack
	//Post: returns if this stack and rhs stack are equal or not
	bool operator == (const STACK &rhs) const;
	
	//Purpose: assigns values of rhs to this stack
	//Parameters: rhs stack
	//Post: this and rhs stacks are equivalent
 	STACK& operator = (const STACK &rhs);
	NODE<T>* getHeadPtr() const{return LINKED_LIST<T>::m_head;}
	bool find(const T& x) const;
	virtual const unsigned int size() const { return COLLECTION<T>::m_size; }
	virtual bool isEmpty() const { return (COLLECTION<T>::m_size ==0); }
	
};

#include "STACK.hpp"

#endif /* STACK_H_ */
