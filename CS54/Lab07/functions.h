//Thomas Dolan
//CS54, Tues. 6pm
//Brian Goldman
//Functions.h

//guard statements
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Function prototypes
void greetings();

int getSides();

int getRolls();

int rollDice(const int sides);

void checkFairness(const int sides, const int rolls, int& low, int& high);

void signoff();

#endif


