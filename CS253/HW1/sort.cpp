//Thomas Dolan
//Project 1: Insertion Sort runtime
//sort.cpp

#include"sort.h"
#include<iostream>

using namespace std;

//Purpose: Sort an array x of size size
//Pre:     A list of size numbers, x
//Post:    A permuation of of x such that it is now in increasing order
void insertSort(int x[], int size)
{
	int key, i=0;
	//Asserts commented out for runtime analysis
	//assert(a[1..j]is in increasing order
	for(int j =1; j < size; j++)
	{
		//assert(a[1..j]is in increasing order && j <size 
		key = x[j];
		i = j-1;
		while(i>=0 && x[i] >key)
		{
			x[i+1] = x[i];
			i--;
		}
		x[i+1] = key;
		//assert(a[1..j]is in increasing order
	}
	//assert(a[1..j]is in increasing order && j >= size	
}
