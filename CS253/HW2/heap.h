//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 2
//heap.h

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <cstdlib>

//Purpose: find the parent of a node
//Pre: An index i
//Post: An index that is the parent of i
int parent(int i);

//Purpose: Returns the index of the left child of a node
//Pre: An index i
//Post: An index that is the left child of i, if it exists
int left(int i);

//Purpose: Returns the index of the right child of a node
//Pre: An index i
//Post: An index that is the right child of i, if it exists
int right(int i);

//Purpose: Takes a heap/subheap and transforms it into a max heap
//Pre: A heap a[] and its index, i, and the heap size hSize
//Post: A max heap has been made for a[]
void heapify(int a[], int i, int hSize);

//Purpose: Builds a max heap for a[]
//Pre: A heap a[] and heap size hSize
//Post: A max heap a[]
void BuildMaxHeap(int a[], int hSize);

//Purpose: Sorts a heap a[]
//Pre: A heap a[] and heap size hSize
//Post: A sorted heap a[]
void HeapSort(int a[], int hSize);

#endif //HEAP_H
