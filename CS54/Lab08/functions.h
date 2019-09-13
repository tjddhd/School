//Thomas Dolan
//CS54, 6pm Tue
//Brian Goldman
//functions.h
//Declarations of functions

//Guard statements
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

//Desc: Outputs greeting
//Pre:  None
//Post: greeting message displayed
void greeting();

//Desc: Outputs signoff message
//Pre:  None
//Post: Signoff message was displayed
void signoff();

//Desc: Will output the 2D coordinates inputted 
//Pre:  T can be assigned
//Post: Displays the coordinates
template<class T>
void outputCoords(const T& xCoord, const T& yCoord);

//Desc: Will display the 3D coordinates inputted
//Pre:  T can be assigned
//Post: Displays the coordinates
template<class T>
void outputCoords(const T& xCoord, const T& yCoord, const T& zCoord);

//include .hpp file thing
#include "functions.hpp"

#endif
