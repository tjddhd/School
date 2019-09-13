#ifndef NODE_H
#define NODE_H

template <class dataType>
class NODE {
private:
  // Member variables
  dataType data;
  NODE *next;

public:
  // Purpose: default constructor
  // Postconditions: data is set to default value for dataType, 
  // next is set to NULL
  NODE();
  
  // Purpose: constructor
  // Parameters: initData is value we want data to be set to, 
  // initNext is value we want next to be set to
  // Postconditions: data is set to initData, next is set to initNext
  NODE(const dataType& initData, NODE* initNext);
  
  // Purpose: (copy) constructor
  // Parameters: otherNode is the node that we want to our member variables to be
  // set to
  // Postconditions: data and next are set to those of otherNode
  NODE(const NODE& otherNode);

  // Purpose: accessor function for data
  // Returns: (immutable copy of) data
  const dataType& getData() const;
  
  // Purpose: accessor function for next
  // Returns: (immutable copy of) next
  NODE* getNext();  

  // Purpose: mutator function for data
  // Parameters: x is value we want to set data to be
  // Postconditions: data is set to x
  void setData(const dataType& x);
  
  // Purpose: mutator function for next
  // Parameters: newNext is value we want to set next to be
  // Postconditions: next is set to newNext
  void setNext(NODE* newNext);

  // Purpose: overloaded = operator
  // Parameters: rhs is the node on the right hand side of the = statement
  // Returns: reference to this node
  // Postconditions: if self-assignment no changes; otherwise, data and next 
  // are set to those of rhs
  NODE& operator = (const NODE& rhs);
};

#include "NODE.hpp"

#endif  // NODE_H
