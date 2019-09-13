/*!\file LINKED_LIST.hpp
 * \author Nathan Eloe
 * \brief implementation of a doubly linked list class
 */

#include <stdexcept>

template <class T>
void LINKED_LIST<T>::insertAtHead(const T& ins)
{
  NODE<T>* temp = m_head;
  m_head = new NODE<T>(ins,NULL,temp);
  if (temp)
    temp->m_prev=m_head;
  else
    m_tail=m_head;
  COLLECTION<T>::m_size++;
}

template <class T>
void LINKED_LIST<T>::insertAtTail(const T& ins)
{
  NODE<T>* temp = m_tail;
  m_tail = new NODE<T>(ins,temp,NULL);
  if (temp)
    temp->m_next=m_tail;
  else
    m_head=m_tail;
  COLLECTION<T>::m_size++;
}

template <class T>
bool LINKED_LIST<T>::find(const T& x) const
{
  NODE<T>* temp = m_head;
  while (temp)
  {
    if (temp->m_data==x)
      return true;
    temp=temp->m_next;
  }
  return false;
}

template <class T>
bool LINKED_LIST<T>::removeFirstOccurrence(const T& rem)
{
  NODE<T>* temp = m_head;
  while (temp)
  {
    if (temp->m_data==rem)
    {
      if (temp->m_prev)
        temp->m_prev->m_next=temp->m_next;
      if (temp->m_next)
        temp->m_next->m_prev=temp->m_prev;
      if (m_head == temp)
        m_head=temp->m_next;
      if (m_tail == temp)
        m_tail=temp->m_prev;
      delete temp;
      COLLECTION<T>::m_size--;
      return true;
    }
    temp=temp->m_next;
  }
  return false;
}

template <class T>
unsigned int LINKED_LIST<T>::removeAllOccurrences (const T& rem)
{
  unsigned int count=0;
  while (removeFirstOccurrence(rem))
    count++;
  return count;
}

template <class T>
void LINKED_LIST<T>::clear()
{
  while (m_head!=m_tail)
  {
    m_head=m_head->m_next;
    delete m_head->m_prev;
  }
  delete m_head;
  m_head=NULL;
  m_tail=NULL;
  COLLECTION<T>::m_size=0;
}

template <class T>
LINKED_LIST<T>& LINKED_LIST<T>::operator=(const LINKED_LIST<T>& rhs)
{
  if (this==&rhs)
    return *this;
  clear();
  NODE<T>* it = rhs.m_head;
  while (it)
  {
    insertAtTail(it->m_data);
    it=it->m_next;
  }
}

template <class T>
bool LINKED_LIST<T>::operator==(const LINKED_LIST<T>&rhs)const
{
  NODE<T>* it = m_head, *it2=rhs.m_head;
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
void LINKED_LIST<T>::removeAtHead()
{
    if (m_head)
    {
        removeFirstOccurrence(m_head->m_data);
    }
    else
        throw std::length_error("list is empty");
}

template <class T>
void LINKED_LIST<T>::removeAtTail()
{
    if (m_tail)
    {
        if (m_tail->m_prev)
        {
            m_tail=m_tail->m_prev;
            delete m_tail->m_next;
            m_tail->m_next=NULL;
        }
        else
        {
            delete  m_tail;
            m_tail=NULL;
            m_head=NULL;
        }
        COLLECTION<T>::m_size--;
    }
    else
        throw std::length_error("list is empty");
} 
