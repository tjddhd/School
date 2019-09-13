//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman
//functions.h

//guard statements
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//include statements
#include<iostream>

using namespace std;

//Desc: Templated function that reads size number of elements into arr from the open input stream input
//Pre:  none
//Post: arr has been assigned values
template <class T>
void readArray(istream& input, T arr[], const int size);

//Desc: Templated funciton that writes size number of elements from arr to the output stream output
//Pre:  correct variables types have been inputted
//Post: arr values have been written to the output stream
template <class T>
void writeArray(ostream& output, const T arr[], const int size);

//include hpp file
#include"functions.hpp"

#endif



