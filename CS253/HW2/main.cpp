//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 2
//main.cpp

#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include "heap.h"
#include "merge.h"
using namespace std;

int main() {
	srandom(time(NULL));
	//time_t rawtime;

	const int SIZE = 10000;

	int b1[SIZE]/*,b1[SIZE],a1[SIZE]*/;
	int b2[SIZE]/*, b2[SIZE],a2[SIZE]*/;

	int i =0;
	while(i<SIZE)
	{
		//a1[i] = random()%1000;
		//a2[i] = random()%1000;
		b1[i] = i;
		b2[i] = i;
		//c1[i] = SIZE - i;
		//c2[i] = SIZE - i;
		i++;
	}

	cout<<"HEAP: ";
	clock_t t1=clock(),t2;
	HeapSort(b1, SIZE);
	t2=clock();
	cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;


	cout<<"MERGE: ";
	t1=clock();
	mergeSort(b2, 1, SIZE);
	t2=clock();
	cout<<(t2-t1)/(double)CLOCKS_PER_SEC<<endl;

  return 0;
}
