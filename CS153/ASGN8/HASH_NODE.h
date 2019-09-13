/*!\file HASH_NODE.h
 * \author Lisa Tatro
 * \brief class definition for a hash node
 */
 
#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <cstdlib>
#define PREV_USED -1
#define NEVER_USED -2
 
template <class KeyType, class DataType>
class HASH_NODE {
public:
  // Member variables
  KeyType m_key;
  DataType m_data;

  HASH_NODE(): m_key(NEVER_USED), m_data(NEVER_USED){}
};

#endif 
