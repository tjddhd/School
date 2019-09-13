/* File: set.h
 * Author: Lisa Tatro
 * Description: Definition of a templated set class
 *Date: 9/2/2011
 *Class: CS153  1A
 */

#ifndef SET_H
#define SET_H

template <class T>
class Set {
private:
    unsigned int m_size;
    unsigned int m_max_size;
    T m_data[20];
 

public:
    // Purpose: default constructor
    // Postconditions: current size is 0, maximum size is 20 
    Set();

    // Purpose: accessor function for the current size of the Set
    // Returns: current size of the Set 
    unsigned int size() const;

    // Purpose: accessor function for the maximum size of the Set
    // Returns: maximum size of the Set 
    unsigned int max_size() const;

    // Purpose: (effectively) empty the Set
    // Postconditions: current size is 0 
    void clear();
	
	// Purpose: search for the occurrence of x in the set
	// Parameters: x is the value to be searched for
	// Returns: true if x is in the set; otherwise, false
	bool find(const T& x) const;

    // Purpose: put x at the first available position in the set (unless x already
	// exists in the set)
	// Parameters: x is the value to be stored in the set
	// Postconditions: If x already exists in the set, then no changes are
	// made. Otherwise, add x to this set, increasing its current size by 1.
	// Exceptions: if there is not enough room in this set to add x, then
	// throw a length_error exception.
    void insert(const T& x);
	
	// Purpose: produce the union of this set and another set
	// Parameters: s1 is the set to union with this set
	// Returns: a set containing all elements in this set and s1,
	// with no duplicates
	// Exceptions: if there is not enough room to create this set, then
	// throw a length_error exception
	Set<T> set_union(const Set<T>& s1) const;
	
	// Purpose: produce the difference of this set and another set
	// Parameters: s1 is the set to remove from this set
	// Returns: a set containing all elements in this set that are not in s1
	Set<T> set_diff(const Set<T>& s1) const;
    
    // Purpose: return a read-only reference to the element at the specified
    // position
    // Parameters: i is 0-based index into the collection
    // Returns: the element at position i in the Set
    // Exceptions: if i < 0 or i > current size of this Set then throw
    // an out_of_range error
    const T& operator[ ] (unsigned int i) const;

    // Purpose: return a read-and-write reference to the element at the
    // specified position
    // Parameters: i is 0-based index into the collection
    // Returns: the element at position i in the Set
    // Exceptions: if i < 0 or i > current size of this Set then throw
    // an out_of_range error
    T& operator[ ] (unsigned int i);
    
    // Purpose: remove one occurrence of a specified element from the
    // collection; if that element does not exist in the collection, then 
    // do nothing
    // Parameters: x is the element for which one occurrence will 
    // be removed 
    // Postconditions: if x exists in the collection, then one occurrence 
    // of x is removed from this Set, decreasing the current size by 1
    void remove(const T& x);
};

#include "set.hpp"
#endif
