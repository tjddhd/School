//////////////////////////////////////////
// Name: Thomas Dolan
// Date 3/6/13
// Assignment 3 - Gram-Schmidt Process
// Professor: Clayton Price
// File: Vector.cpp
//////////////////////////////////////////
#include <vector>
#include<iostream>
#include"Vector.h"
using namespace std;

template<unsigned int def>
Vector<def>::Vector(const Vector<def>& src)
{
	for(int i =0; i < def; i++)
		components[i] = src.components[i];
}

template<unsigned int def>
void Vector<def>::setComponent(float num, int index)
{
	components[index] = num;
}

template<unsigned int def>
ostream& operator<<(ostream& out, const Vector<def>& src)
{
	for(int i =0; i<def;i++)
		out << src.components[i];
	return out;
}