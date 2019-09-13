//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: air_conditioner.cpp
// Semester: Spring 2014
//////////////////////////////

#include "air_conditioner.h"
#include "room.h"
#include <iostream>

using namespace std;

Air_conditioner::Air_conditioner(const Air_conditioner& src)
{
	*this = src;
}

Air_conditioner::~Air_conditioner()
{
	delete location;
}

Air_conditioner& Air_conditioner::operator=(const Air_conditioner& src)
{
	name = src.name;
	state = src.state;
	delete location;
	location = new Room();
	*location = *src.location;
	return *this;
}
string Air_conditioner::get_name()
{
	return name;
}

void Air_conditioner::turn_on(Room& r)
{
	cout<< "just before locaiton copy" <<endl;
	location = new Room(r);
	cout<< "just after locaiton copy" <<endl;
	if(state == false)
	{
		state = true;
	}
	
	location->change_temp((location->get_temp()) - 1);
	cout<< location->get_name() <<" has a current temperature of "<< location->get_temp() <<endl;
}

void Air_conditioner::turn_off(Room& r)
{
	location = new Room(r);
	if(state == true)
	{
		state = false;
	}
	
	cout<< location->get_name() <<" has a current temperature of "<< location->get_temp() <<endl;
}