/*!\file BNODE.h
 * \author Jennifer Leopold
 * \brief A node class for a binary tree
 */

#ifndef BNODE_H
#define BNODE_H

#include <cstdlib>
#include <string>
#include <sstream>

template <class T>
class BNODE {
public:
  T m_data;                    // data value
  unsigned int m_count;        // # occurrences of m_data 
  BNODE<T> *m_left, *m_right;  // left and right child ptrs
  BNODE<T> *m_parent;          // parent ptr

public:
  // Purpose: default constructor
  // Postconditions: left and right child ptrs set to NULL,
  // data set to default value for type T, and count set to 1
  BNODE() : m_left(NULL), m_right(NULL), m_parent(NULL),
            m_data(), m_count(1) { }
  
  // Purpose: parameterized constructor
  // Parameters: specified values for data, left and right child
  // ptrs, and count (respectively)
  // Postconditions: data, left and right child ptrs, and count
  // are set to the specified (or default) values
  BNODE(const T& data, BNODE<T>* leftLink=NULL, 
        BNODE<T>* rightLink=NULL, BNODE<T>* parentLink=NULL,
        const unsigned int num = 1) :
      m_left(leftLink), m_right(rightLink), m_parent(parentLink),
      m_data(data), m_count(num) { }
  
  // Purpose: determine whether or not this node is a leaf
  // Returns: true if this node is a leaf; otherwise, returns
  // false
  bool isLeaf( ) const { 
    return((m_left == NULL) && (m_right == NULL)); 
  }
  
  // Purpose: construct a string containing this node's data
  // value and count
  // Returns: a string consisting of this node's data value and
  // its count; e.g., if this node's value is the int 42 and its
  // count is 3, the returned string will be "42 (3)"
  std::string toString() const {
    std::stringstream ss;
    ss << m_data << " (" << m_count << ")";
    return(ss.str());
  }
};

#endif
