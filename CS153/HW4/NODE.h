/*!\file node.h
 * \author Nathan Eloe
 * \brief A node class for a doubly linked list
 */

#ifndef NODE_H
#define NODE_H

#include <cstdlib>

template <class T>
class NODE
{
  public:
    NODE():m_next(NULL),m_prev(NULL),m_data() {}
    NODE(const T& data, NODE<T>* prev=NULL, NODE<T>* next=NULL):
      m_next(next),m_prev(prev),m_data(data) {}

    NODE<T>* m_next, *m_prev;
    T m_data;
};

#endif
