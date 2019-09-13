////////////////////
// Thomas Dolan
// Clayton Price
// CS328
// HW6
// matrix.h
////////////////////

#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
class Matrix
{
  public:
    
	//Pre: Adequate Memroy
	//Post: Creates a default Matrix
	//Desc: Default Matrix constructor
    Matrix<T>():rows(0), cols(0), elm(NULL) {}
	
	//Pre: Adequate memory
	//Post: Creates a Matrix of Size size
	//Desc: Square Matrix Constructor
	Matrix(const unsigned int size);
	
	//Pre: Adequate memory
	//Post: Creates a copy of a given Matrix
	//Desc: Copy Matrix Constructor
	Matrix(const Matrix& src);
	
	//Pre: Adequate memory
	//Post: Assigns src Matrix to calling Matrix
	//Desc: Assignment operator
	Matrix<T>& operator=(const Matrix<T>& src);
	
	//Pre: Matrix isn't empty
	//Post: Element at given index
	//Desc: returns the element of the given ondex
	T& operator[](const int r) const;
	
	//Pre: Matrices are of equal sizes
	//Post: Summed Matrix
	//Desc: Adds 2 matrices
	template <class U>
	friend Matrix<U>& operator+(const Matrix<U>& a, const Matrix<U>& b);
	
	//Pre: Matrices are of equal sizes
	//Post: Summed Matrix
	//Desc: Subtracts 2 matrices
	template <class U>
	friend Matrix<U>& operator-(const Matrix<U>& a, const Matrix<U>& b);
	
	//Pre: Matrix isn't empty
	//Post: Negative Matrix
	//Desc: Negates the Matrix
	template <class U>
	friend Matrix<U>& operator-(const Matrix<U>& a);
	
	//Pre: Matrix isn't empty
	//Post: Outputs a Matrix
	//Desc: Outputs a Matrix
	template <class U>
	friend ostream& operator<<(ostream& out, const Matrix<U>& a);
	
  private:
    int rows, cols;
	T** elm;
};

#endif