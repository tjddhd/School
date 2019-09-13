////////////////////
// Thomas Dolan
// Clayton Price
// CS328
// HW6
// driveer.cpp
////////////////////

#include <stdlib.h>
#include <iostream>
#include "matrix.h"
#include "banded.h"
#include "diagonal.h"
#include "symmetric.h"

using namespace std;

int main(int argc, char* argv[])
{
  if(argc != 2)
    cout << "Ya dun goofed"<< endl;
  else
  {
    cout << "Worked great" << endl;
  }
  
  Matrix<int> mat;
  Banded<int> band;
  Diagonal<double> diag;
  Symmetric<float> sym;
  
  return 0;
}