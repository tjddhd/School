//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman
//Lab 10: Shuffling
//main.cpp

//include statements
#include"functions.h"
#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

//main function
int main()
{
  //random seed and greeting
  srandom(time(NULL));
  greeting();
  
  //array declaration
  const int ARRAY_SIZE = 10;
  int numArray[ARRAY_SIZE];
  
  //file i/o declaration
  ifstream ins;
  ofstream outs;
 
  //input file opened
  ins.open("numbers.txt");

  //loop to read in numbers from file
  for(int i = 0; i < ARRAY_SIZE; i++)
  {
    int x;
    ins >> x;
    numArray[i] = x;
  }
  
  //shuffle call
  shuffle(numArray, ARRAY_SIZE);

  //opens output file
  outs.open("Lab10output.txt");

  //outputs to screen and output file
  int j = 0;
  while( j < ARRAY_SIZE)
  {
    cout<<numArray[j]<<endl;
    outs<<numArray[j]<<endl;
    j++;
  }
  
  //files close and signoff
  ins.close();
  outs.close();
  signoff();

  return 0;
}






