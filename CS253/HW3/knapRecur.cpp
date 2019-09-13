//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//knapRecur.cpp


#include <iostream>
#include <cstdlib>
#include "knapRecur.h"
using namespace std;

//Purpose: Find a maximum profit given weight constraints
//Pre: A valid price and weight arrays, the capacity of the knapsack and the current index
//Post: The optimum profit according to the algorithm
int knapRecursion(int price[], int weight[], int capacity, int index)
{
	//Assert: For index up to i, the current stored profit is the maximum profit
	if(index == 34)
		return (capacity < weight[index] ? 0 : price[index]);
	if(capacity < weight[index])
		return (knapRecursion(price, weight, capacity, index+1));
	return maxRecur((knapRecursion(price, weight, capacity, index+1)),
	  (knapRecursion(price, weight, capacity-weight[index], index+1)+ price[index]));
}

//Purpose: Returns the max of 2 values
//Pre: 2 integers
//Post: the maximum of the 2 integers
int maxRecur(int num1, int num2)
{
	int temp;
	if(num1 > num2)
		temp = num1;
	else
		temp = num2;
	return temp;
}
