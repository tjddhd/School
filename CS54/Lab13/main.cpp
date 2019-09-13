//Thomas Dolan
//CS54, 6pm Tues
//Goldan Briman
//Lab 13: Vectors.....
//main.cpp

//include statements
using namespace std;

#include<iostream>
#include"functions.h"

//main function
int main()
{
  //vector variables
  Vector3d vec1, vec2;

  //examples of class operations
  vec1.setXcoord(1.2);
  vec1.setYcoord(3.14);
  vec1.setZcoord(4.12);
  vec2.setXcoord(2);
  vec2.setYcoord(4);
  vec2.setZcoord(6);

  cout<<vec1 + vec2<<endl;

  vec1.setXcoord(2.0);
  vec1.setYcoord(2.1);
  vec1.setZcoord(2.2);
  vec2.setXcoord(0.2);
  vec2.setYcoord(1.2);
  vec2.setZcoord(2.2);

  cout<<vec1*vec2<<endl;

  vec1.setXcoord(0.5);
  vec1.setYcoord(0.8);
  vec1.setZcoord(0.9);
  vec2.setXcoord(3);
  vec2.setYcoord(4);
  vec2.setZcoord(5);

  cout<<((2*vec1) * vec2)<<endl;
  
  return 0;
}

