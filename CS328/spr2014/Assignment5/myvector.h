///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  array.h
// Semester:   Spring 2014
///////////////////////////////////////

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
class MyVector
{
  public:
  
    //Pre: Defualt constructor for the MyVector object
	//Post: Creates a MyVector object
	//Desc: Creates a MyVector object
    MyVector(): m_size(0),ptr_to_data(NULL) {};
	
	//Pre: Constructor for MyVector object of given size
	//Post: Creates a MyVector object with given size
	//Desc: Creates a MyVector object with given size
	MyVector(const int size): m_size(size) {ptr_to_data = new T[size];};
	
	//Pre: Copy Constructor
	//Post: Creates a copy of the given object
	//Desc Creates a copy of the given object
	MyVector(const MyVector<T>& src) {*this = src;};
	
	//Pre: Deallocates the memory used by the MyVector object
	//Post: Deallocates the memory and deletes the object
	//Desc: Deallocates the memory and deletes the object
	~MyVector() {delete ptr_to_data;}
	
	//Pre: Scopes in to the object to get a certain element
	//Post: Returns a value at the given index
	//Desc: Returns a value at the given index
	T& operator[](const int& i);
	
	//Pre: Requistion for the size varible
	//Post: Returns the value of the size
	//Desc: Accesses and returns the value of the size
	int getSize() const;
	
	//Pre: Sets a new value for the size of MyVector
	//Post: Size has a new value and ptr_to_data has a new memory address
	//Desc: Size has a new value and ptr_to_data has a new memory address
	void setSize(const int& size);
	
	//Pre: Sets the calling object equal to the given MyVector object
	//Post: Sets all values equal to the given object
	//Desc: Sets all values equal to the given object
	MyVector<T>& operator=(const MyVector<T>& src);
	
	//Pre: + must defined for T
	//Post: Returns a vector reference that adds the 2 vectors together
	//Desc: Adds 2 vectors
	template <class U>
	friend MyVector<T> operator+(const MyVector<T>& lhs, const MyVector<T>& rhs);
	
	//Pre: += must defined for T
	//Post: Returns a vector reference that adds the 2 vectors together
	//Desc: Adds 2 vectors
	void operator+=(const MyVector<T>& rhs);
	
	//Pre: Negatives must defined for T
	//Post: The vector has been negated
	//Desc: Negatess a vector
	void operator-();
	
	//Pre: - must defined for T
	//Post: Returns a vector reference that subtracts the 2 vectors together
	//Desc: Subtracts 2 vectors
	template <class U>
	friend MyVector<T> operator-(const MyVector<T>& lhs, const MyVector<T>& rhs);
	
	//Pre: -= must defined for T
	//Post: Returns a vector reference that subtracts the 2 vectors together
	//Desc: Subtracts 2 vectors
	void operator-=(const MyVector<T>& rhs);
	
	//Pre: Given a MyVector object
	//Post: Format and Output the MyVector object
	//Desc: Formats and output the MyVector object
	template <class U>
	friend ostream& operator<<(ostream& out, const MyVector<U>& a);
	
  private:
    int m_size;
	T* ptr_to_data;
	void array_copy(const MyVector<T>& src);
};

#include "myvector.hpp"

#endif