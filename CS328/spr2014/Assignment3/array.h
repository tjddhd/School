///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  array.h
// Semester:   Spring 2014
///////////////////////////////////////

#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
class MyArray
{
  public:
  
    //Pre: Defualt constructor for the MyArray object
	//Post: Creates a MyArray object
	//Desc: Creates a MyArray object
    MyArray(): m_size(0),ptr_to_data(NULL) {};
	
	//Pre: Constructor for MyArray object of given size
	//Post: Creates a MyArray object with given size
	//Desc: Creates a MyArray object with given size
	MyArray(const int size): m_size(size) {ptr_to_data = new T[size];};
	
	//Pre: Copy Constructor
	//Post: Creates a copy of the given object
	//Desc Creates a copy of the given object
	MyArray(const MyArray<T>& src) {*this = src;};
	
	//Pre: Deallocates the memory used by the MyArray object
	//Post: Deallocates the memory and deletes the object
	//Desc: Deallocates the memory and deletes the object
	~MyArray() {delete ptr_to_data;}
	
	//Pre: Scopes in to the object to get a certain element
	//Post: Returns a value at the given index
	//Desc: Returns a value at the given index
	T& operator[](const int& i);
	
	//Pre: Requistion for the size varible
	//Post: Returns the value of the size
	//Desc: Accesses and returns the value of the size
	int getSize() const;
	
	//Pre: Sets a new value for the size of MyArray
	//Post: Size has a new value and ptr_to_data has a new memory address
	//Desc: Size has a new value and ptr_to_data has a new memory address
	void setSize(const int& size);
	
	//Pre: Sets the calling object equal to the given MyArray object
	//Post: Sets all values equal to the given object
	//Desc: Sets all values equal to the given object
	MyArray<T>& operator=(const MyArray<T>& src);
	
	//Pre: Given a MyArray object
	//Post: Format and Output the MyArray object
	//Desc: Formats and output the MyArray object
	template <class U>
	friend ostream& operator<<(ostream& out, const MyArray<U>& a);
	
  private:
    int m_size;
	T* ptr_to_data;
	void array_copy(const MyArray<T>& src);
};

#include "array.hpp"

#endif