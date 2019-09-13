///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 2
// File name:  driver.cpp
// Semester:   Spring 2014
///////////////////////////////////////

#include "norm.h"
#include "polarNum.h"
#include "exceptions.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    cout << "It didn't work right"<< endl;
  }
  else
  {
    ifstream file;
	file.open(argv[1]);
  
    if( !file.good())
    {
      cout<<"Looks like there was a problem with your file\n"<<endl;
    }
    else
    {	
      cout << "includes & file structures worked and shit" << endl;
	  int numLines;
	  file >> numLines;
	  cout<<numLines<<endl;
      vector<PolarNum<int> > vect;	
    }
    file.close();
  }
  return(0);
}
