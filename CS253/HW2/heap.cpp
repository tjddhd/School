//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 2
//heap.cpp


#include <iostream>
#include <cstdlib>
#include "heap.h"
using namespace std;

//Purpose: find the parent of a node
//Pre: An index i
//Post: An index that is the parent of i
int parent(int i) {
	if(i==1)
		return 0;

	if(i%2==0)
		return ( (i / 2)-1);
	else
		return ( (i / 2));
}

//Purpose: Returns the index of the left child of a node
//Pre: An index i
//Post: An index that is the left child of i, if it exists
int left(int i) {
	return (2 * i) + 1;
}

//Purpose: Returns the index of the right child of a node
//Pre: An index i
//Post: An index that is the right child of i, if it exists
int right(int i) {
	return (2 * i) + 2;
}

//Purpose: Takes a heap/subheap and transforms it into a max heap
//Pre: A heap a[] and its index, i, and the heap size hSize
//Post: A max heap has been made for a[]
void heapify(int a[], int i, int hSize) {
	int l = left(i), good, r = right(i);
	if ( (a[l] > a[i]) && (l < hSize)) {
		good = l;
	}
	else {
		good = i;
	}
	if ( (a[r] > a[good]) && (r < hSize)) {
		good = r;
	}
	if (good != i) {
		int temp = a[i];
		a[i] = a[good];
		a[good] = temp;
		heapify(a, good, hSize);
  }
}

//Purpose: Builds a max heap for a[]
//Pre: A heap a[] and heap size hSize
//Post: A max heap a[]
void BuildMaxHeap(int a[], int hSize) {
	for (int i = (hSize - 1) / 2; i >= 0; i--) {
		heapify(a, i, hSize);
	}
}

//Purpose: Sorts a heap a[]
//Pre: A heap a[] and heap size hSize
//Post: A sorted heap a[]
void HeapSort(int a[], int hSize) {
	BuildMaxHeap(a, hSize);
	int temp2 = hSize;
	//Assert that each i=1,2,..n is a max heap
	for (int i = temp2; i > 0; i--) {
		//Assert that each i=1,2,..n is a max heap && i>0
		int temp = a[0];
		a[0] = a[temp2 - 1];
		a[temp2 - 1] = temp;
		temp2--;
		heapify(a, 0, temp2);
		//Assert that each i=1,2,..n is a max heap
	}
	//Assert that each i=1,2,..n is a max heap && i<=0
}
