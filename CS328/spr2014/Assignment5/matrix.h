#ifndef MATRIX_H
#define MATRIX_H

#include "myvector.h"

using namespace std;

template <class T>
class Matrix
{
  public:
    //Pre: Defualt constructor for the Matrix object
	//Post: Creates a Matrix object
	//Desc: Creates a Matrix object
    Matrix();
	         
	
	//Pre: Given a MyVector object
	//Post: Format and Output the MyVector object
	//Desc: Formats and output the MyVector object
	template <class U>
	friend ostream& operator<<(ostream& out, const Matrix<U>& a);
	
  private:
    MyVector<MyVector<T> > mat;
};

#include "matrix.hpp"

#endif