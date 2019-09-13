/*!\file HEAP.h
 * \author Jennifer Leopold
 * \brief class definition for a HEAP
 *\ derped by Thomas Dolan
 */
#ifndef HEAP_H
#define HEAP_H

#include "BNODE.h"
#include "BINARY_TREE.h"
#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class HEAP : public BINARY_TREE<T> {

// Note: Duplicates handled as separate nodes (i.e., not handling 
// dups with BNODE<T>::m_count -- instead that is being used to
// store # nodes in subtree rooted by that node (including the 
// node itself))

private:
  bool m_isMaxHeap; // true if max heap; otherwise, 
                    // false (min heap)
  
public:
  // *** ADD WHATEVER PUBLIC FUNCTIONS YOU WANT ***
  // *** BUT DO NOT CHANGE THE EXISTING PUBLIC FUNCTIONS ***

  HEAP() : m_isMaxHeap(true) { }
  HEAP(const bool isMaxHeap) : m_isMaxHeap(isMaxHeap) { }

  // Purpose: determine the height of the subtree rooted by
  // rootPtr 
  // Parameters: rootPtr is a pointer to the root of the subtree 
  // for which we want to determine height
  // Returns: height of the subtree rooted by rootPtr 
  unsigned int height(BNODE<T>* rootPtr) const {
    unsigned int h = 0;
    BNODE<T> *temp = rootPtr;
    while (temp != NULL) {
      h++;
      temp = temp->m_left;
    }
    return(h);
  }
  
  // Purpose: determine whether or not the tree rooted by rootPtr
  // is full 
  // Parameters: rootPtr is pointer to the tree to be tested and
   // depth is the rootPtr node's depth in the tree (e.g., m_root 
  // is at depth 0)
  // Returns: true if the tree rooted by rootPtr is full; 
  // otherwise, return false
  bool isFull  //took out HEAP<T>
   (BNODE<T>* rootPtr = BINARY_TREE<T>::getRoot(),
    unsigned int depth = 0)  {
    if (rootPtr == NULL)
      return(false);  // weird case
    else return(((double) rootPtr->m_count) == 
                (pow(2.0, height(BINARY_TREE<T>::getRoot())-depth)
                          -1));
  }
  
  void heapifyUp( BNODE<T>* newestNode);
  
  
  void heapifyDown( BNODE<T>* rootPtr);
  
  // Purpose: insert the specified value into the heap 
  // Parameters: x is the value to be inserted into the heap
  // Postconditions: x has been inserted into the tree into the
  // rightmost available position and then pushed up the tree as 
  // necessary to maintain proper heap order
  void insert(const T& x);  // *** WRITE ME! ***
  
  // Purpose: remove the root node's value from the heap 
  // Postconditions: the root node's value has been removed from
  // the heap and replaced with the value of the rightmost leaf
  // on the lowest level; that value has then been pushed down 
  // the tree as necessary to maintain proper heap order
  bool removeRoot();  // *** WRITE ME! ***
  
  // Purpose: determine whether or not this heap is equivalent to
  // a specified heap 
  // Parameters: rhs is the heap to be compared to this heap
  // Returns: if the heaps are exactly the same in terms of 
  // structure and content, return true; otherwise, return false
  bool operator==(const HEAP<T>& rhs) const {
    return(BINARY_TREE<T>::operator ==(rhs));
  }
  
  // Purpose: construct this heap to be equivalent to the 
  // specified heap
  // Parameters: rhs is heap to copy 
  // Returns: the heap constructed
  // Postconditions: this heap is equivalent in content and 
  // structure to the specified heap
  HEAP<T>& operator=(HEAP<T>& rhs) {
    BINARY_TREE<T>::operator=(rhs);
    m_isMaxHeap = rhs.m_isMaxHeap;
    return *this;
  }
 
private:
  // Purpose: determine whether x is considered "higher priority"
  // than y
  // Parameters: x and y are the values to be compared 
  // Returns: true if x is considered "higher priority" than y; 
  // otherwise, returns false
  bool higherPriority(const T x, const T y) const {
    if (m_isMaxHeap)
      return(x > y);
    else return(x < y);
  }
  
  // Purpose: swap the data values in the 2 specified nodes
  // Parameters: nodePtr1 and nodePtr2 are ptrs to the nodes 
  // whose values are to be swapped
  void swapData(BNODE<T>* nodePtr1, BNODE<T>* nodePtr2) {
    // don't swap m_count b/c that represents the # of node's
    // in that subtree(which presumably we do NOT want to change)
    T data = nodePtr1->m_data;
    nodePtr1->m_data = nodePtr2->m_data;
    nodePtr2->m_data = data;
  }
  
  // *** ADD WHATEVER PRIVATE FUNCTIONS YOU WANT ***
};

#include "HEAP.hpp"

#endif // HEAP.h

