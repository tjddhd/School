#include "myvector.h"
#include "matrix.h"

using namespace std;

template <class T>
Matrix<T>::Matrix()
{
  mat = new MyVector<MyVector<T> >(5);
  for(int i = 0; i < 5; i++)
  {
    mat[i] = new MyVector<T>(5);
  }
}

template <class T>
ostream& operator<<(ostream& out, const Matrix<T>& a)
{
  for(int i = 0; i < 5; i++)
  {
    out<<a[i]<<endl;
  }
  return out;
}