//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//knapGreed.cpp


#include <iostream>
#include <cstdlib>
#include "heap.h"
#include "knapGreed.h"
using namespace std;

//Purpose:Find a maximum profit given weight constraints
//Pre: A valid price and weight arrays, the capacity of the knapsack and the current index
//Post: The optimum profit according to the algorithm
int knapGreedy(int price[], int weight[], int capacity, int size)
{
	int temp[1000000], total = 0;
	for(int i = 0; i < size; i++)
	{
		temp[i] = price[i];
	}
	//Function call to the heap sort from the previous project
	HeapSort(temp, size);
	for(int i = size; i >= 0; i--)
	{
		//Assert: For index up to i, the current stored profit is the maximum profit
		for( int j = 0; j < size; j++)
		{
			if((temp[i] == price[j])&& weight[j]<=capacity)
			{
				total += temp[i];
				capacity -= weight[j];
				j=size;
			}
		}
	}
	return total;

}
