///////////////////////////////////////
// Name:       Thomas Dolan
// Class:      CS328
// Professor:  Clayton Price
// Assignment: 3
// File name:  newton.h
// Semester:   Spring 2014
///////////////////////////////////////

#ifndef NEWTON_H
#define NEWTON_H

#include "stdlib.h"
#include "array.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

template <class T>
class Newton
{
  public:
  
    //Pre: Default constructor if there's enough memory
	//Post: Creates a Newton object
	//Desc: Creates a Newton object
    Newton(): x_pos(0),coefficient(0) {};
	
	//Pre: Requistion for the x position varible
	//Post: Returns the value of the x position
	//Desc: Accesses and returns the value of the x position
	float getX() const;
	
	//Pre: Requistion for the coefficient varible
	//Post: Returns the value of the coeffiicent
	//Desc: Accesses and returns the value of the coefficient
	T getCoef() const;
	
	//Pre: Sets a new value for the x position
	//Post: X position has a new value
	//Desc: X position has a new value
	void setX(const float& new_x);
	
	//Pre: Sets a new value for the coefficient
	//Post: Coefficient has a new value
	//Desc: Coefficient has a new value
	void setCoef(const T& new_coef);
  private:
    float x_pos;
	T coefficient;
};

#include "newton.hpp"

#endif