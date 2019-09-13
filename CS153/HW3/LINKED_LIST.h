/*!\file LINKED_LIST.h
 * \author Jennifer Leopold
 * \brief Definition of a singly linked list class
 */
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "NODE.h"

template <class dataType>
class LINKED_LIST {
private:
  // Member variables
  NODE<dataType> *headPtr;
  NODE<dataType> *tailPtr;
  int numUsed;

public:
  // Purpose: default constructor
  // Postconditions: headPtr and tailPtr are set to NULL, numUsed is set to 0
  LINKED_LIST() : headPtr(NULL), tailPtr(NULL), numUsed(0) { }
  
  // Purpose: (copy) constructor
  // Parameters: otherList is the linked list that we want to be exactly like
  // Postconditions: sequence of nodes from headPtr to tailPtr is exactly like
  // that of otherList
  // Exceptions: if can't allocate memory, throw bad_alloc exception
  LINKED_LIST(const LINKED_LIST& otherList);

  // Purpose: destructor
  // Postconditions: tailPtr and headPtr are NULL, numUsed is 0, all memory used 
  // for nodes in this list has been deallocated
  ~LINKED_LIST();

  // Purpose: accessor function for headPtr
  // Returns: (immutable copy of) headPtr
  NODE<dataType>* getHeadPtr() const { return(headPtr); }
  // Purpose: accessor function for tailPtr
  // Returns: (immutable copy of) tailPtr
  NODE<dataType>* getTailPtr() const {return(tailPtr); }
  // Purpose: accessor function for numUsed
  // Returns: numUsed
  const int getNumUsed() const { return(numUsed); }

  // Purpose: effectively clears contents of the list
  // Postconditions: tailPtr and headPtr are NULL, numUsed is 0, all memory used 
  // for nodes in this list has been deallocated
  void clear();
  
  // Purpose: insert into the head of the list a node whose data value 
  // is equal to that of newData 
  // Parameters: newData is the data value of the node to be inserted
  // Postconditions: a new node with value equal to that of newData has been 
  // added to the front of the list (as pointed to by headPtr, and possibly 
  // tailPtr if there is only one element in the list), and numUsed has been 
  // incremented by 1
  // Exceptions: if can't allocate memory, throw bad_alloc exception
  void insertAtHead(const dataType& newData);
  
  // Purpose: insert into the tail of the list a node whose data value 
  // is equal to that of newData 
  // Parameters: newData is the data value of the node to be inserted
  // Postconditions: a new node with value equal to that of newData has been 
  // added to the end of the list (as pointed to by tailPtr, and possibly 
  // headPtr if there is only one element in the list), and numUsed has been 
  // incremented by 1
  // Exceptions: if can't allocate memory, throw bad_alloc exception
  void insertAtTail(const dataType& newData);
  
  // Purpose: remove the first occurrence of a node with data value equal to x 
  // from the list 
  // Parameters: x is the data value of the node to be removed
  // Postconditions: if the value x was in the list, the first occurrence of 
  // it has been removed and numUsed has been decremented by 1
  // Returns: true if one occurrence of x was removed; otherwise, false
  bool removeFirstOccurrence(const dataType& x);
  
  // Purpose: remove all occurrences of nodes with data value equal to x 
  // from the list 
  // Parameters: x is the data value to be removed
  // Postconditions: all occurrences of x have been removed from the list, and
  // the value of numUsed adjusted accordingly
  // Returns: the number of occurrences of x that were removed (0, if none)
  int removeAllOccurrences(const dataType& x);
  
  // Purpose: determine whether the list is empty
  // Returns: true if numUsed is 0; otherwise, false
  const bool isEmpty() const { return(numUsed == 0); }
  
  // Purpose: overloaded = operator
  // Parameters: rhs is the list on the right hand side of the = statement
  // Returns: reference to this linked list
  // Postconditions: if self-assignment no changes; otherwise, list now
  // contains sequence of nodes identical to that of rhs
  const LINKED_LIST& operator = (const LINKED_LIST &rhs);
  
  // Purpose: overloaded == operator
  // Parameters: rhs is the list on the right hand side of the == statement
  // Returns: true is this sequence of nodes is identical to that of rhs;
  // otherwise, returns false
  bool operator == (const LINKED_LIST &rhs);
};

#include "LINKED_LIST.hpp"

#endif  // LINKED_LIST_H
