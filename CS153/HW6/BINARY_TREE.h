/*!\file BINARY_TREE.h
 * \author Jennifer Leopold
 * \brief a virtual class for a binary tree
 */
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "BNODE.h"
#include "COLLECTION.h"

template <class T>
class BINARY_TREE : public COLLECTION<T> {
protected:
  BNODE<T> *m_root;       // root of tree

public:
  // Purpose: default constructor
  // Postconditions: root is set to NULL and size is set to 0
  BINARY_TREE( ) : m_root(NULL) { }
  
  // Purpose: destructor
  // Postconditions: root is set to NULL, size is set to 0, 
  // and memory used for nodes in this tree is deallocated 
  // (all done via clear)
  ~BINARY_TREE( ) { clear(); }
  
  // Purpose: accessor function for the root of this tree 
  // Returns: root of this tree
  BNODE<T>*& getRoot() { return m_root; }
  
  // Purpose: determine whether or not a specified value is in
  // this tree 
  // Parameters: x is specified value to be found
  // Returns: true if x is in this tree; otherwise, returns false
  bool find(const T& x) const {
    return(findStartingAtNode(x, m_root));  // default behavior
                                            // is to search
                                            // entire tree
  }
  
  // Purpose: clear this tree
  // Postconditions: tree's root is set to NULL, size is set to
  // 0, and memory used for nodes in this tree is deallocated 
  //(done via clearStartingAtNode)
  void clear( ) { 
    clearStartingAtNode(BINARY_TREE<T>::m_root); 
    BINARY_TREE<T>::m_root = NULL; 
  }
  
  // Purpose: insert the specified value into this tree 
  // Parameters: x is value to be inserted
  // Postconditions: another occurrence of x has been added to
  // this tree, and m_size is incremented
  // Exceptions: if can't allocate memory, throw bad_alloc 
  // exception
  virtual void insert(const T& x) = 0;
  
  // Purpose: determine whether or not this tree is equivalent
  // to a specified tree 
  // Parameters: rhs is the tree to be compared to this tree
  // Returns: if the trees are exactly the same in terms of 
  // structure and content, return true; otherwise, return false
  bool operator==(const BINARY_TREE<T>& rhs) const;
  
  // Purpose: construct a string that specifies each node's value
  // and count, as the nodes would be encountered in an inorder
  // traversal of this tree starting from the root
  // Returns: a string that specifies each node's value and
  // count,as the nodes would be encountered in an inorder 
  // traversal of this tree
  std::string toStringInorder() const {
    std::string s = "";
    toStringInorderStartingAtNode(s, BINARY_TREE<T>::m_root);
    return(s);
  } 
  
  // Purpose: construct a string that specifies each node's value
  // and count, as the nodes would be encountered in a preorder
  // traversal of this tree starting from the root
  // Returns: a string that specifies each node's value and
  // count,as the nodes would be encountered in a preorder 
  // traversal of this tree
  std::string toStringPreorder() const {
    std::string s = "";
    toStringPreorderStartingAtNode(s, BINARY_TREE<T>::m_root);
    return(s);
  }
  
  // Purpose: construct a string that specifies each node's value
  // and count, as the nodes would be encountered in a postorder
  // traversal of this tree starting from the root
  // Returns: a string that specifies each node's value and
  // count,as the nodes would be encountered in a postorder 
  // traversal of this tree
  std::string toStringPostorder() const {
    std::string s = "";
    toStringPostorderStartingAtNode(s, BINARY_TREE<T>::m_root);
    return(s);
  }
     
  // Purpose: construct this binary tree to be equivalent to
  // the specified binary tree
  // Parameters: rhs is binary tree to copy 
  // Returns: the binary tree constructed
  // Postconditions: this binary tree is equivalent to the
  // specified binary tree
  BINARY_TREE<T>& operator=(BINARY_TREE<T>& rhs);
  
protected: 
  // Purpose: determine whether or not a specified value is in
  // the subtree rooted by the specified node ptr
  // Parameters: x is specified value to be found and rootPtr 
  // is ptr to the root node of the subtree to be searched
  // Returns: true if x is in the specified subtree; otherwise, 
  //returns false
  bool findStartingAtNode(const T& x, BNODE<T>* rootPtr) const;
  
  // Purpose: construct a string that specifies the value and 
  // count of each node in this tree, in the order that the nodes 
  // would be encountered in an inorder traversal starting from
  // the specified node
  // Parameters: string to be constructed (passed-by-reference)
  // and ptr to the node from which to start the traversal
  // Returns: a string that specifies each node's value and
  // count, as the nodes would be encountered in an inorder 
  // traversal of this tree starting from the specified node
  void toStringInorderStartingAtNode(std::string& s, 
                                     BNODE<T>* nodePtr) const;
  
  // Purpose: construct a string that specifies the value and 
  // count of each node in this tree, in the order that the nodes 
  // would be encountered in a preorder traversal starting from
  // the specified node
  // Parameters: string to be constructed (passed-by-reference)
  // and ptr to the node from which to start the traversal
  // Returns: a string that specifies each node's value and
  // count, as the nodes would be encountered in a preorder
  // traversal of this tree starting from the specified node
  void toStringPreorderStartingAtNode(std::string& s, 
                                      BNODE<T>* nodePtr) const; 
  
  // Purpose: construct a string that specifies the value and 
  // count of each node in this tree, in the order that the nodes 
  // would be encountered in a postorder traversal starting from
  // the specified node
  // Parameters: string to be constructed (passed-by-reference)
  // and ptr to the node from which to start the traversal
  // Returns: a string that specifies each node's value and
  // count, as the nodes would be encountered in a postorder
  // traversal of this tree starting from the specified node
  void toStringPostorderStartingAtNode(std::string& s, 
                                       BNODE<T>* nodePtr) const;
  
  // Purpose: make a copy of the binary tree rooted by nodePtr
  // Parameters: nodePtr is ptr to root node of binary tree to
  // copy, parentPtr is ptr to the node the was nodePtr's parent
  // Returns: ptr to root node of binary tree constructed 
  BNODE<T>* copyStartingAtNode(BNODE<T>*& nodePtr, 
                               BNODE<T>* parentPtr);
  
  // Purpose: clear the subtree rooted by the specified node ptr
  // Parameters: rootPtr is ptr to the root node of the subtree
  // to be cleared
  // Postconditions: memory used for nodes in the tree rooted by
  // rootPtr is deallocated and tree's size is decremented by 1
  // for each node removed
  void clearStartingAtNode(BNODE<T>*& rootPtr);
};

#include "BINARY_TREE.hpp"

#endif // BINARY_TREE.h

