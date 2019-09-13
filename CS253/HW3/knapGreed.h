//Thomas Dolan
//CS253, Sec B, Gerry Howser
//Project 3
//knapGreed.h

#ifndef KNAPGREED_H
#define KNAPGREED_H

#include <iostream>
#include <cstdlib>

//Function prototypes

//Purpose:Find a maximum profit given weight constraints
//Pre: A valid price and weight arrays, the capacity of the knapsack and the current index
//Post: The optimum profit according to the algorithm
int knapGreedy(int price[], int weight[], int capacity, int size);



#endif //KNAPGREED_H
