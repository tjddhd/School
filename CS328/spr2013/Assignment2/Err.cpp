///////////////////////////////////////////////////////////////////////////////
// Programmer :  Thomas Dolan
// Assignment :  Program 2
//
// Instructor :  Clayton Price
// Course     :  CS328
// Semester   :  Spring 2013
///////////////////////////////////////////////////////////////////////////////

#include "Err.h"
#include <iostream>
using namespace std;

RangeErr()
{
	cerr<<"Range Error"<<endl;
}

void RangeErr::badSubscr()
{
	cerr<<"Bad subscript"<<endl;
}

SizeErr::SizeErr()
{
	cerr<<"Size Error"<<endl;
}

void SizeErr::badSubscr()
{
	cerr<<"Bad subscript"<<endl;
}