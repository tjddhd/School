#include "stdlib.h"
#include <iostream>
#include "chebyshev.h"
#include "compare.h"
#include "eval_poly.h"
#include "generator.h"
#include "int_poly.h"
#include <cmath>
#include <vector>

using namespace std;

int main()
{
  
  vector<double> vect(5), nodes(5), data(5);
  vect[0] = 0.1;
  vect[1] = 0.3;
  vect[2] = 0.5;
  vect[3] = 0.7;
  vect[4] = 0.9;
  
  cout<< "Given points: "<<endl;
  for(int i = 0; i < 5; i++)
  {
    cout<< vect[i]<<endl;
  }
  
  cout<<"Computed Nodes: "<<endl;
  Generator<double> test;
  nodes = test.node_generator(vect);
  
  cout<< "Chebyshev points: "<<endl;
  Chebyshev<double> test2;
  data = test2.data_pts(nodes);
  
  return 0;
}