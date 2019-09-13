/*!\file LINKED_LIST.h
 * \author Nathan Eloe
 * \brief a doubly linked list class
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ORDERED_COLLECTION.h"
#include "NODE.h"

template <class T>
class LINKED_LIST: protected ORDERED_COLLECTION<T>
{
  public:
    LINKED_LIST(): m_head(NULL),m_tail(NULL), ORDERED_COLLECTION<T>::ORDERED_COLLECTION(){}
    LINKED_LIST(const LINKED_LIST<T>& cpy): 
        m_head(NULL),m_tail(NULL) {*this = cpy;}
    virtual ~LINKED_LIST() { clear(); }
    void insertAtHead(const T& ins);
    void insertAtTail(const T& ins);
    void removeAtHead();
    void removeAtTail();
    virtual bool find(const T& x) const;
    bool removeFirstOccurrence(const T& rem);
    unsigned int removeAllOccurrences(const T& rem);
    void clear();
	virtual bool isEmpty() const { return (COLLECTION<T>::m_size ==0); }
	virtual const unsigned int size() const { return COLLECTION<T>::m_size; }
    LINKED_LIST<T>& operator=(const LINKED_LIST<T>& rhs);
    bool operator== (const LINKED_LIST<T>& rhs) const;
    virtual NODE<T>* getHeadPtr() const{return m_head;}
    virtual NODE<T>* getTailPtr() const{return m_tail;}
  protected:
    NODE<T>* m_head, *m_tail;
};

#include "LINKED_LIST.hpp"

#endif 
