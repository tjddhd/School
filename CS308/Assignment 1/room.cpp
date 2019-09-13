//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: room.cpp
// Semester: Spring 2014
//////////////////////////////

#include "room.h"
#include <iostream>

string Room::get_name()
{
	return name;
}

Room::Room(const Room& r)
{
	*this = r;
}

Room::~Room()
{
	delete thermostat_in_room;
}

int Room::get_temp()
{
	return temperature;
}

Room& Room::operator=(const Room& r)
{
	name = r.name;
	temperature = r.temperature;
	delete thermostat_in_room;
	thermostat_in_room = new Thermostat(); 
	*thermostat_in_room = *r.thermostat_in_room;
	return *this;
}

void Room::change_temp(int new_temp)
{
	temperature = new_temp;
	thermostat_in_room = new Thermostat();
	thermostat_in_room->check_temp(new_temp, *this);
}