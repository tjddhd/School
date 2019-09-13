#include "sumSquares.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(3);
  v.push_back(5);
  cout << sumSquares(v) << endl;
}
