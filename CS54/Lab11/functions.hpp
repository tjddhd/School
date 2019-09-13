//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman
//functions.hpp

//include statements
#include<iostream>
#include<fstream>
#include<string>
#include"functions.h"

//templated readArray funciton to assign values to arr
template <class T>
void readArray(istream& input, T arr[], const int size)
{
  int counter = 0;
  T buffer;
  input >> buffer;
  while(input.good() && counter < size )
  {
    arr[counter] = buffer;
    counter++;
    input >> buffer;
  }
}

//templated function to write arr values to output stream
template <class T>
void writeArray(ostream& output, T arr[], const int size)
{
  for(int i = 0; i<size; i++)
  {
    output << arr[i] <<endl;
  }
}







