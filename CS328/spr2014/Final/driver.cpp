#include "bounds.h"
#include "matrix.h"
#include "my_vector.h"
#include <iostream>
#include "stdlib.h"

using namespace std;

int main()
{
  Bounds<double, upperXFunction> a;
  double x = 1, y = 0;
  int n = 100;
  
  cout << "This is calculated with x = 1 and y = 0 with 10000 partitions" <<endl;
  cout << "Area under the Upper X Function curve: " <<  a.integrate(y, x, n) <<endl;
  
  Bounds<double, lowerXFunction> b;
  x = 1; y = 0;
  
  cout << "This is calculated with x = 1 and y = 0" <<endl;
  cout << "Area under the Lower X Function curve: " <<  b.integrate(y, x, n) <<endl;
  
  Bounds<double, upperYFunction> c;
  x = 1; y = 0;
  
  cout << "This is calculated with x = 1 and y = 0" <<endl;
  cout << "Area under the Upper Y Function curve: " <<  c.integrate(y, x, n) <<endl;
  
  Bounds<double, lowerYFunction> d;
  x = 0; y = 0;
  
  cout << "This is calculated with x = 0 and y = 0" <<endl;
  cout << "Area under the Lower Y Function curve: " <<  d.integrate(y, x, n) <<endl;
  
  Matrix<double> test(1);
  
  cout << "A test matrix, 1x1 with value 3" << endl;
  test(0,0) = 3;
  cout << test << endl;
  
  cout << "A test matrix, 1x1 with value 4, utilizing the copy constructor and indexing" << endl;
  Matrix<double> test2(1);
  test2(0,0) = 4;
  cout << test2 << endl;

  cout << "A test matrix, 1x1 which is given the value of test1 + test2" << endl;
  Matrix<double> test3 = test + test2;
  cout << test3 << endl;

  cout << "A test matrix, 1x1 which is given the value test2 - test1" <<endl;
  Matrix<double> test4 = test2 - test;
  cout << test4 << endl;
  
  cout << "A test matrix, 1x1 which is given the value of test1 * test2" <<endl;
  Matrix<double> test5 = test * test2;
  cout <<test5<<endl;
  
  return 0;
}