/*!\file BINARY_TREE.hpp
 * \author Jennifer Leopold
 * \brief implementation of a BST
 */

template <class T>
bool BINARY_TREE<T>::findStartingAtNode(const T& x, BNODE<T>* rootPtr) const {
  if (rootPtr == NULL)
    return(false);   // x isn't in the tree

  if (x == rootPtr->m_data)
    return(true);

  if (findStartingAtNode(x, rootPtr->m_left))
    return(true);
  
  return(findStartingAtNode(x, rootPtr->m_right));
}

template <class T>
bool BINARY_TREE<T>::operator==(const BINARY_TREE<T>& rhs) const {
  return((toStringPreorder() == rhs.toStringPreorder()) &&
         (toStringPostorder() == rhs.toStringPostorder()));
}

template <class T>
void BINARY_TREE<T>::toStringInorderStartingAtNode
 (std::string& s, BNODE<T>* nodePtr) const {
  if (nodePtr != NULL) {
    toStringInorderStartingAtNode(s, nodePtr->m_left);
    if (s.length() > 0) s = s + ", ";
    s = s + nodePtr->toString();
    toStringInorderStartingAtNode(s, nodePtr->m_right);
  }
}

template <class T>
void BINARY_TREE<T>::toStringPreorderStartingAtNode
 (std::string& s, BNODE<T>* nodePtr) const {
  if (nodePtr != NULL) {
    if (s.length() > 0) s = s + ", ";
    s = s + nodePtr->toString(); 
    toStringPreorderStartingAtNode(s, nodePtr->m_left);
    toStringPreorderStartingAtNode(s, nodePtr->m_right);
  }
}

template <class T>
void BINARY_TREE<T>::toStringPostorderStartingAtNode
  (std::string& s, BNODE<T>* nodePtr) const {
  if (nodePtr != NULL) {
    toStringPostorderStartingAtNode(s, nodePtr->m_left);
    toStringPostorderStartingAtNode(s, nodePtr->m_right);
    if (s.length() > 0) s = s + ", ";
    s = s + nodePtr->toString();
  }
}

template <class T>
BINARY_TREE<T>& BINARY_TREE<T>::operator=(BINARY_TREE<T>& rhs) {
  if (this==&rhs)
    return *this;
  clear();
  m_root = copyStartingAtNode(rhs.BINARY_TREE<T>::getRoot(),
                              NULL);
  return(*this);

}

template <class T>
BNODE<T>* BINARY_TREE<T>::copyStartingAtNode
  (BNODE<T>*& nodePtr, BNODE<T>* parentPtr = NULL) {
  if (nodePtr == NULL)
    return(NULL);
  COLLECTION<T>::m_size++;
  try {
       return(new BNODE<T>
               (nodePtr->m_data, 
                copyStartingAtNode(nodePtr->m_left, nodePtr), 
                copyStartingAtNode(nodePtr->m_right, nodePtr),
                parentPtr,
                nodePtr->m_count));
  } catch (...) { throw std::bad_alloc(); }
}

template <class T>
void BINARY_TREE<T>::clearStartingAtNode(BNODE<T>*& rootPtr) {
  if (rootPtr != NULL) {
    clearStartingAtNode(rootPtr->m_left);   // clear L subtree
    clearStartingAtNode(rootPtr->m_right);  // clear R subtree
    delete rootPtr;                         // delete root
    rootPtr = NULL;                
    COLLECTION<T>::m_size--;
  }
}
