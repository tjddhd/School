/* File: container.h
 * Author: Jennifer Leopold (leopoldj@mst.edu)
 * Description: Definition of a templated container class
 */
//
//Edited to set.h
//Editor: Thomas Dolan
//Description: Defintion of a templated set class

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

    // Purpose: accessor function for the current size of the set
    // Returns: current size of the set
    unsigned int size() const;

    // Purpose: accessor function for the maximum size of the set
    // Returns: maximum size of the set
    unsigned int max_size() const;

    // Purpose: (effectively) empty the set
    // Postconditions: current size is 0 
    void clear();

    // Purpose: add an element to the set
    // Parameters: x is the element to be added to the set
    // Postconditions: x is added to the set, and current size is
    // increased by 1
    // Exceptions: if there is not enough room to add x, then throw
    // a length_error
    // Exceptions: if x already exists in the set, throw a length_error
    void insert(const T& x);
    
    // Purpose: return a read-only reference to the element at the specified
    // position
    // Parameters: i is 0-based index into the collection
    // Returns: the element at position i in the set
    // Exceptions: if i < 0 or i > current size of this set then throw
    // an out_of_range error
    const T& operator[ ] (unsigned int i) const;

    // Purpose: return a read-and-write reference to the element at the
    // specified position
    // Parameters: i is 0-based index into the collection
    // Returns: the element at position i in the set
    // Exceptions: if i < 0 or i > current size of this set then throw
    // an out_of_range error
    T& operator[ ] (unsigned int i);
    
    // Purpose: remove one occurrence of a specified element from the
    // collection; if that element does not exist in the collection, then 
    // do nothing
    // Parameters: x is the element for which one occurrence will 
    // be removed 
    // Postconditions: if x exists in the collection, then one occurrence 
    // of x is removed from this set, decreasing the current size by 1
    void remove(const T& x);

    // Purpose: search for the occurence of x in the set
    // Parameters: x is the value to be searched for
    // Returns: true if x is in the set; otherwise false
    bool find(const T& x) const;

    // Purpose: produce the union of this set and another set
    // Parameters: s1 is the set to union with this set
    // Returns: a set containing all elements in the set and s1, with no duplicates
    // Exceptions: if there is not enough room to create this set, then throw a 
    // length_error exception
    Set<T> set_union(const Set<T>& s1) const;

    // Purpose: produce the union of this set and another set
    // Parameters: s1 is the set to union with this set
    // Returns: a set containing all elements an this set that are not in s1
    Set<T> set_diff(const Set<T>& s1) const;
};

#include "set.hpp"
#endif
