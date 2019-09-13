////////////////////
// Thomas Dolan
// Clayton Price
// CS328
// HW6
// matrix.cpp
////////////////////

#include "matrix.h"

template <class T>
Matrix<T>::Matrix(const unsigned int size)
{
  elm = new T*[size];
  for(int i = 0; i <size; i++)
    elm[i] = new T[size];
}

template <class T>
Matrix<T>::Matrix(const Matrix& src)
{
  *this = src;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& src)
{
  rows = src.rows;
  cols = src.cols;
  if(elm != NULL)
  {
    for(int i = 0; i < rows; i++)
	  delete elm[i];
	delete elm;
  }
  
  elm = new T*[src.cols];
  for(int i = 0; i < src.cols; i++)
  {
    elm[i] = new T[cols];
    for(int j = 0; j < src.rows; j++)
	  elm[i][j] = src.elm[i][j];
  }
  
  return *this;
}

template <class T>
T& Matrix<T>::operator[](const int r) const
{
  if (elm != NULL && r > 0 && r <= rows)
    {
      return elm[r];
    }
    else
    {
      cerr << "out of range"<< endl;
    }
}

template <class T>
Matrix<T>& operator+(const Matrix<T>& a, const Matrix<T>& b)
{
  if(a.rows == b.rows && a.cols == b.cols)
  {
    for(int i = 0; i < a.rows; i++)
	{
	   for(int j = 0; j < a.cols; j++)
	     a[i][j] += b[i][j];
	}
  }
  else
  {
    cerr<<"Size mismatch"<<endl;
  }
}

template <class T>
Matrix<T>& operator-(const Matrix<T>& a, const Matrix<T>& b)
{
  return a + (-b);
}

template <class T>
Matrix<T>& operator-(const Matrix<T>& a)
{
  for(int i = 0; i < a.rows; i++)
	{
	   for(int j = 0; j < a.cols; j++)
	     a[i][j] = -a[i][j];
	}
}

template <class T>
ostream& operator<<(ostream& out, const Matrix<T>& a)
{
  for(int i =0; i < a.rows; i++)
  {
    out << "[ ";
    for(int j = 0; j < a.cols; j++)
      out << a.elm[i][j];
	out << " ]";
  }
	
  return out;
}


















