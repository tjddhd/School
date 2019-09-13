/*
 * STACK.hpp
 *
 *  Created on: Oct 14, 2011
 *      Author: Thomas Dolan
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stdexcept>

template <class T>
const T& STACK<T>::top() const
{
  try 
  {  
    if(LINKED_LIST<T>::getHeadPtr() == NULL)
	  throw std::length_error("");
  }
  catch(std::length_error &e)
  {
    throw e;
  }
  return (LINKED_LIST<T>::getHeadPtr() -> m_data);
	
}

template <class T>
void STACK<T>::push(const T& x)
{
  LINKED_LIST<T>::insertAtHead(x);
}

template <class T>
void STACK<T>::pop()
{
  LINKED_LIST<T>::removeAtHead();
}

template <class T>
STACK<T>& STACK<T>::operator=(const STACK<T>& rhs)
{
  if (this==&rhs)
    return *this;
  LINKED_LIST<T>::clear();
  NODE<T>* it = rhs.LINKED_LIST<T>::getHeadPtr();
  while (it)
  {
    LINKED_LIST<T>::insertAtTail(it->m_data);
    it=it->m_next;
  }
}

template <class T>
bool STACK<T>::operator== (const STACK<T>& rhs) const
{
  NODE<T>* it = LINKED_LIST<T>::getHeadPtr(), 
       *it2=rhs.LINKED_LIST<T>::getHeadPtr();
  while (it && it2)
  {
    if (it->m_data!=it2->m_data)
      return false;
    it=it->m_next;
    it2=it2->m_next;
  }
  //If they're both NULL, then they are equal.  
  // Otherwise, they're not
  return (!it && !it2);
} 

template <class T>
bool STACK<T>::find(const T& x) const
{
  NODE<T>* temp = LINKED_LIST<T>::m_head;
  while (temp)
  {
    if (temp->m_data==x)
      return true;
    temp=temp->m_next;
  }
  return false;
}

#endif /* STACK_HPP_*/