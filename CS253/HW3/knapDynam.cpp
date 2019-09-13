//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//knapDynam.cpp


#include <iostream>
#include <cstdlib>
#include "knapDynam.h"
using namespace std;

//Purpose:Find a maximum profit given weight constraints
//Pre: A valid price and weight arrays, the capacity of the knapsack and the current index
//Post: The optimum profit according to the algorithm
int knapDynamic(int price[], int weight[], int capacity, int index)
{
	int temp[1400][1400];
	int i, j;
	for(i = 1; i <= capacity; i++)
	{
		//Assert: For index up to i, the current stored profit is the maximum profit
		for(j = 0; j < index; j++)
		{
			if(j>0)
			{
				temp[j][i] = temp[j-1][i];
				if(weight[j] <= i)
					temp[j][i] = max(temp[j][i], temp[j-1][i-weight[j]]+price[j]);
			}
			else
			{
				temp[j][i] = 0;
				if(weight[j] <= i)
					temp[j][i] = max(temp[j][i], price[j]);
			}
		}
	}
	return temp[index-1][capacity];
}

//Purpose: Returns the max of 2 values
//Pre: 2 integers
//Post: the maximum of the 2 integers
int max(int num1, int num2)
{
	int temp;
	if(num1 > num2)
		temp = num1;
	else
		temp = num2;
	return temp;
}
