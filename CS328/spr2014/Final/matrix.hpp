////////////////////
// Thomas Dolan
// Clayton Price
// CS328
// HW7
// matrix.hpp
////////////////////

#include "matrix.h"

template <class T>
Matrix<T>::Matrix(const int size)
{
  elm = new T*[size];
  for(int i = 0; i <size; i++)
    elm[i] = new T[size];
	
  rows = cols = size;
}

template <class T>
Matrix<T>::Matrix(const Matrix& src)
{
  *this = src;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& src)
{

  if(elm != NULL && rows == 0)
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
  
  rows = src.rows;
  cols = src.cols;
  
  return *this;
}

template <class T>
T& Matrix<T>::operator()(const int r, const int c) const
{
  if (elm != NULL && r > -1 && r <= rows)
    {
      return elm[r][c];
    }
    else
    {
      cerr << "out of range"<< endl;
	  throw;
    }
}

template <class T>
Matrix<T> operator+(Matrix<T>& a, const Matrix<T>& b)
{
  Matrix<T> c(a);
  if(a.rows == b.rows && a.cols == b.cols)
  {
    for(int i = 0; i < a.rows; i++)
	{
	   for(int j = 0; j < a.cols; j++)
	   {
	     c(i,j) += b(i,j);
	   }
	}
  }
  else
  {
    cerr<<"Size mismatch"<<endl;
	throw;
  }

  return c;
}

template <class T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& b)
{
  Matrix c(*this);
  
  return c+b;
}

template <class T>
Matrix<T> operator-(Matrix<T>& a, const Matrix<T>& b)
{
  Matrix<T> c(a), d(b);
  c = (c + (-d));
  return c;
}

template <class T>
Matrix<T> Matrix<T>::operator-()
{
  Matrix<T> a(*this);
  for(int i = 0; i < rows; i++)
	{
	   for(int j = 0; j < cols; j++)
	     a(i,j) = -(a(i,j));
	}
  return a;
}

template <class T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T>& b)
{
  Matrix c(*this);
  
  return c-b;
}

template <class T>
Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b)
{
  if(a.cols == b.rows)
  {
    Matrix<T> soln(a.rows);
	double sum=0;
	
    for(int i = 0; i < a.rows; i++)
	{
	    for(int j = 0; j < a.rows; j++)
		{
		  for(int k = 0; k < a.rows; k++)
		    sum += a(j,i) * b(i,k);
		  soln(i,j) = sum;
		}
	}
	
	 return soln;
  }
  else
  {
    cerr<<"Size mismatch"<<endl;
	throw;
  }
}

template <class T>
Matrix<T> Matrix<T>::operator*=(const Matrix<T>& b)
{
  Matrix c(*this);
  
  return b*c;
}

template <class T>
ostream& operator<<(ostream& out, const Matrix<T>& a)
{
  for(int i =0; i < a.rows; i++)
  {
    out << "[ ";
    for(int j = 0; j < a.cols; j++)
      out << a.elm[i][j] << " ";
	out << "]" << endl;
  }
	
  return out;
}


















