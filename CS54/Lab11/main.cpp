//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman
//Lab 11: Review
//main.cpp

//include statements
#include<iostream>
#include<string>
#include<fstream>
#include"functions.h"

//main function
int main()
{
  //sizes and arrays declared
  const int int_arr_size = 4;
  const int float_arr_size = 5;
  int intArr[int_arr_size];
  float floatArr[float_arr_size];

  //I/O file variables
  ifstream insFile;
  ofstream outsFile;

  //Files opened
  insFile.open("Lab11input.txt");
  outsFile.open("Lab11output.txt");

  //Reads values into each array
  readArray(insFile, floatArr, float_arr_size);
  cout<<"Please input an integer and press enter each time:" <<endl;
  readArray(cin, intArr, int_arr_size);
  
  //Outputs values of the arrays into appropriate spots
  cout<<endl<<endl;  
  writeArray(cout, floatArr, float_arr_size);
  writeArray(outsFile, intArr, int_arr_size);
  
  //file close
  insFile.close();
  outsFile.close();
  
  return 0;
}










