//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//knapDynam.h

#ifndef KNAPDYNAM_H
#define KNAPDYNAM_H

#include <iostream>
#include <cstdlib>

//Function prototypes

//Purpose:Find a maximum profit given weight constraints
//Pre: A valid price and weight arrays, the capacity of the knapsack and the current index
//Post: The optimum profit according to the algorithm
int knapDynamic(int price[], int weight[], int capacity, int index);

//Purpose: Returns the max of 2 values
//Pre: 2 integers
//Post: the maximum of the 2 integers
int max (int num1, int num2);


#endif //KNAPDYNAM_H
