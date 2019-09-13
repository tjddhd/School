/*!\file HASHTABLE.h
 * \author Jennifer Leopold && lisa tatro
 * \brief class definition for a hash table
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H


#include "COLLECTION.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <iostream>

#include "HASH_NODE.h"
#include <cstdlib>
using namespace std;

#define PREV_USED -1
#define NEVER_USED -2
#define DEFAULT_CAPACITY 100

template <class KeyType, class DataType>
class HASHTABLE : public COLLECTION<DataType> {

protected:
  unsigned int m_capacity;
  HASH_NODE<KeyType, DataType> *table_ptr;
  HASH_NODE<KeyType, DataType> *iterator;

public:
  // Purpose: default constructor
  // Postconditions: initializes the hash table to have n "unused" slots
  HASHTABLE(unsigned int n = DEFAULT_CAPACITY);
  
  // Purpose: destructor
  // Postconditions: removes all allocated memory associated with the 
  // data structure (via clear)
  ~HASHTABLE() { clear(); }
  
  // Purpose: clear the hash table
  // Postconditions: deallocates all memory associated with the data structure 
  // and sets size of the collection to 0
  void clear();
  
  // Purpose: determine whether the specified data value exists in 
  // the collection (note: primarily this is here because it's 
  // declared as pure virtual in the superclass)
  // Parameters: x is the data value to be found
  // Returns: true if the data value x exists; otherwise, false
  bool find(const DataType& x) const;  
  
  // Purpose: determine whether the specified key value exists in 
  // the collection  
  // Parameters: key is the value to be found, position will be index
  // position in the hash table where key is found (if found)
  // Returns: true if the key value x exists; otherwise, false
  bool find(const KeyType& key, int& position);
  
  // Purpose: insert specified key and data value into the hash table  
  // Parameters: specified key and data value to be inserted
  // Postconditions: if specified key already exists in hash table, data has
  // been changed; otherwise, specified key and data value have been inserted 
  // into the hash table, and size of collection incremented
  // Exceptions: if insertion cannot be done because hash table is full,
  // throw length_error exception
  void insert(const KeyType& key, const DataType& data);
  
  // Purpose: remove the specified key (and its associated data value) from 
  // the hash table  
  // Parameters: key is the value to be removed
  // Postconditions: if specified key exists in hash table, it (and its
  // associated data value) have been removed and collection size decremented; 
  // otherwise, no changes made
  void remove(const KeyType& key);
  
  // Purpose: map the specified key to an integer (index) position in 
  // the hash table  
  // Parameters: key is the value to be hashed
  // Returns: integer (index) position in the hash table
  int hash(const KeyType& key) {
    std::stringstream ss;
    ss << key;
    std::string s = ss.str();
    int charSum = 0;
    for (int i = 0; i < s.size(); i++)
      charSum = charSum + s[i];
    return(charSum % m_capacity);
  };
  
  // Purpose: return a read-only reference to the data value associated 
  // with a specified key in the hash table  
  // Parameters: key associated with the data value to be returned
  // Returns: read-only reference to the data value associated 
  // with key; if key doesn't exist in the hash table, returns default value
  // for DataType
  const DataType operator[] (const KeyType& key);
  
  // Purpose: reset the internal iterator to reference the first data value
  // in the hash table
  // Postconditions: internal iterator references the first data value in
  // the hash table
  // Exceptions: if hash table is empty, throw out_of_range exception
  void iteratorReset();
  
  // Purpose: set the internal iterator to reference the "next" data value
  // in the hash table, and return the data value that previously was being
  // referenced by the internal iterator
  // Postconditions: internal iterator references the next data value in
  // the hash table; if previous iterator referenced "last" data value
  // in hash table, this should wrap-around to beginning of hash table
  // Exceptions: if hash table is empty, throw out_of_range exception
  const DataType& iteratorGetNext();
};

#include "HASHTABLE.hpp"

#endif // HASHTABLE.h

