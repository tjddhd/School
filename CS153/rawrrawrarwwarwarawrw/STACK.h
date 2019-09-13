/*
  author: Lisa Tatro
  date: Oct 14, 2011
  file: STACK.h
*/

#ifndef STACK_H
#define STACK_H

#include "LINKED_LIST.h"

template <class T>
class STACK: protected LINKED_LIST<T>
{
  public:
  
    STACK(): LINKED_LIST<T>::LINKED_LIST() {}
	~STACK() {}
	STACK<T>& operator=(const STACK<T>& rhs);
    bool operator== (const STACK<T>& rhs) const;
	NODE<T>* getHeadPtr() const{return LINKED_LIST<T>::m_head;}
	bool find(const T& x) const;
	
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
	bool isEmpty() const { return (COLLECTION<T>::m_size ==0); }
	const unsigned int size() const { return COLLECTION<T>::m_size; }
	
	//This inherits a headPtr which will be considered the top and 
	//the tailPtr is considered to be the bottom

};

#include "STACK.hpp"
#endif 
