//Thomas Dolan
//CS54, 6pm Tues
//Brian Goldman
//functions.h

//guard statements
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

using namespace std;

//Desc: swap 2 numbers
//Pre:  ints are passed in
//Post: numbers have been swapped
void swap(int& num1, int& num2);

//Desc: shuffles the array values
//Pre:  values entered into each array spot
//Post: array values have been shuffled
void shuffle(int my_array[], const int array_size);

//Desc: greets user
//Pre:  none
//Post: user has been greeted
void greeting();

//Desc: says bye to user
//Pre:  none
//Post: user has been "byed"
void signoff();

#endif



