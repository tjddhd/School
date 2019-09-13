#include "generator.h"

using namespace std;

template <class T>
vector<double> Generator<T>::node_generator(vector<double>& in)
{
  vector<double> nodes(in.size());
  for(unsigned int i =0; i < in.size(); i++)
  {
    nodes[i] = cos((2*in[i] + 1 - 2*i)*(PI/(2*in[i] +2)));
    cout << nodes[i]<< endl;
  }
  return nodes;
}