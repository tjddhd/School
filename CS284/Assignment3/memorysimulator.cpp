#include "stdlib.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		cout << "Error with command line execution"<< endl;
		cout << "Must be in form of: 	\nprogram name/\n"<<
										"program list/\n"<<
										"program trace file/\n"<<
										"page size/\n"<<
										"page replacement algorithm/\n"<<
										"prepaging/demandpaging" <<endl;
		exit(0);
	}
	
	ifstream programlist (argv[1]);
	int progNo[100], wordSize[100];
	int pagePerProg;
	
	if(programlist.is_open())
	{
		for(int i =0;i<programlist.good();i++)
		{
			programlist >> progNo[i];
			programlist >> wordSize[i];
			pagePerProg = 512/ i;
		}
	}
	
	int progTable[pagePerProg];
	int mainTable[pagePerProg];
	
	ifstream programtrace (argv[2]);
	int progs[10000], relWord[10000], temp;
	
	if(programtrace.is_open())
	{
		for(int i =0;i<trace.good();i++)
		{
			programtrace >> progs[i];
			programtrace >> relWord[i];
			temp = relWord[i]/10;
			progTable[temp] = i;
		}
	}
	
	programlist.close();
	return 0;
}