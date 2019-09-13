//////////////////////////////////////////
// Name: Thomas Dolan
// Date 3/6/13
// Assignment 3 - Gram-Schmidt Process
// Professor: Clayton Price
// File: driver.cpp
//////////////////////////////////////////
#include "Vector.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	//if(argc != 2)
	{
		//A quick check for file arguments passed
		cerr<<"You did not enter a file input"<<endl; 
	}
	//else
	{
		ifstream my_file("testFile");//argv[1]); //File is opened
		
		if(!my_file.is_open())
		{
			//An error was encountered when opening user's file
			cerr<<"Error opening file. Sorry"<<endl;
		}
		else
		{
			//driver code here
			int vec_size;
			my_file >> vec_size;
			vector<Vector<4> > v;
			
			for(int i=0;i < vec_size; i++)
			{
				float temp=0;
				cout<<"Set size for vector "<<i<<endl;
				for(int j=0;j<vec_size; j++)
				{
					my_file >> temp;
					v[i].components[j];
					cout<<"i: "<<i<<"\t j: "<<j<<endl;
				}
				cout<<v[i].components[i]<<endl;
				
			}
		}
		
		my_file.close();
	}
	
	return 0;
}