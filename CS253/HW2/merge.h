//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 2
//merge.h

#ifndef MERGE_H
#define MERGE_H

#include <iostream>

//Purpose: Sorts an array of size r
//Pre: An integer array, arr
//Post: A permutation of arr such that it is now in increasing order
void mergeSort(int arr[], int p, int r);

//Purpose: Merges 2 halves of a subarray arr
//Pre: An integer array, arr and beginning p, midpoint q, and endpoint r
//Post: A merged subarray arr
void merge(int arr[], int p, int q , int r);

#endif
