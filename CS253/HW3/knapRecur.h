//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//knapRecur.h

#ifndef KNAPRECUR_H
#define KNAPRECUR_H

#include <iostream>
#include <cstdlib>

//Function prototypes

//Purpose: Find a maximum profit given weight constraints
//Pre: A valid price and weight arrays, the capacity of the knapsack and the current index
//Post: The optimum profit according to the algorithm
int knapRecursion(int price[], int weight[], int capacity, int index);

//Purpose: Returns the max of 2 values
//Pre: 2 integers
//Post: the maximum of the 2 integers
int maxRecur(int num1, int num2);

#endif //KNAPRECUR_H
