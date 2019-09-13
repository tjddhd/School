#include "chebyshev.h"

using namespace std;

template <class T>
vector<double> Chebyshev<T>::data_pts(vector<double>& in)
{
  vector<double> pts(in.size());
  
  for(unsigned int i =0; i <in.size(); i++)
  {
    pts[i] = 1/(1 + 12*in[i]*in[i]);
	cout<< pts[i] <<endl;
  }
  
  return pts;
}