/* File: container.h
 * Author: Jennifer Leopold (leopoldj@mst.edu)
 * Description: Definition of a templated container class 
 * that uses dynamic memory allocation
 */

#ifndef CONTAINER_H
#define CONTAINER_H

template <class T>
class Container {
public:
    typedef T* TArrayPtr;
    
private:   
    unsigned int m_size;
    unsigned int m_max_size;
    TArrayPtr m_data;
 
public:   
    // Purpose: default constructor
    // Postconditions: current size is 0, maximum size is 20,  
    // memory is allocated for m_data to be of size 20 
    // Exceptions: if there is not enough room to allocate memory 
    // for m_data, throw a bad_alloc exception
    Container();
    
    // Purpose: copy constructor 
    // Exceptions: if there is not enough room to allocate memory 
    // for m_data, throw a bad_alloc exception
    Container(const Container<T>& copyMe);
    
    // Purpose: destructor
    // Postconditions: memory for m_data is deallocated, 
    // current size is 0
    ~Container();

    // Purpose: accessor function for the current size of the
    // container
    // Returns: current size of the container 
    unsigned int size() const;

    // Purpose: accessor function for the maximum size of the
    // container
    // Returns: maximum size of the container 
    unsigned int max_size() const;

    // Purpose: empty the container
    // Postconditions: current size is 0, all data values in
    // m_data are removed, max_size is possibly modified via
    // remove function
    // Exceptions: if remove throws an exception (because there
    // is not enough room to allocate memory for m_data), then
    // throw a bad_alloc exception
    void clear();

    // Purpose: add an element to the container (duplicates are
    // allowed!)
    // Parameters: x is the element to be added to the container
    // Postconditions: x is added to the container, and current
    // size is increased by 1; if the resulting current size is >
    // 50% of max_size, then size of m_data is increased by 20%
    // (i.e., new size is 1.2 * max_size)
    // Exceptions: if m_size == m_max_size, then throw a
    // length_error; if there is not enough room to allocate more
    // memory for m_data, throw a bad_alloc exception
    void insert(const T& x);
    
    // Purpose: return a read-only reference to the element at
    // the specified position
    // Parameters: i is 0-based index into the collection
    // Returns: the element at position i in the container
    // Exceptions: if i < 0 or i > current size of this container
    // then throw an out_of_range error
    const T& operator[ ] (unsigned int i) const;

    // Purpose: return a read-and-write reference to the element
    // at the specified position
    // Parameters: i is 0-based index into the collection
    // Returns: the element at position i in the container
    // Exceptions: if i < 0 or i > current size of this container
    // then throw an out_of_range error
    T& operator[ ] (unsigned int i);
    
    // Purpose: remove one occurrence of a specified element from
    // the collection; if that element does not exist in the
    // collection, then do nothing
    // Parameters: x is the element for which one occurrence will 
    // be removed 
    // Postconditions: if x exists in the collection, then one
    // occurrence of x is removed from this container, decreasing
    // the current size by 1; if the resulting current size is <
    // 50% of max_size, the size of m_data is decreased by 20%
    void remove(const T& x);
    
    // Purpose: determine whether a particular element is in the
    // collection
    // Parameters: x is element we're trying to find
    // Returns: returns true if x is in collection; otherwise,
    // returns false
    const bool find(const T& x) const;
};

#include "container.hpp"
#endif
