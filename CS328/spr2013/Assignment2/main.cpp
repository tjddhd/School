///////////////////////////////////////////////////////////////////////////////
// Programmer :  Thomas Dolan
// Assignment :  Program 2
//
// Instructor :  Clayton Price
// Course     :  CS328
// Semester   :  Spring 2013
///////////////////////////////////////////////////////////////////////////////

#include "norm.h"
#include "quaternion.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{	
	ifstream myfile;
	myfile.open("data.txt");
	ofstream resultfile;
	resultfile.open("results.txt");

	vector<Quaternion<double> > vect;
	
	
	int size;
	myfile >> size;
	
	while(myfile.good())
	{
		for(int i = 0; i <size; i++)
		{
			myfile >> vect[i].a;
			myfile >> vect[i].b;
			myfile >> vect[i].c;
			myfile >> vect[i].d;
		}
	}
	
	resultfile << vect[0];
	resultfile << vect[1];
	resultfile << vect[0] += vect[1];
	resultfile << -vect[0];
	resultfile << vect[0]*vect[2];
	resultfile << !vect[3];
	resultfile << inv(vect[4]);

	myfile.close();
	resultfile.close();
}
