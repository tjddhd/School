//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: thermostat.cpp
// Semester: Spring 2014
//////////////////////////////

#include "thermostat.h"
#include <iostream>

using namespace std;

Thermostat::Thermostat(const Thermostat& src)
{
	*this = src;
}

Thermostat::~Thermostat()
{
	delete location;
	delete what_it_controls;
}

Thermostat& Thermostat::operator=(const Thermostat& src)
{
	name = src.name;
	setting = src.setting;
	delete what_it_controls;
	what_it_controls = new Air_conditioner();
	delete location;
	location = new Room();
	*what_it_controls = *src.what_it_controls;
	*location = *src.location;
	return *this;
}

string Thermostat::get_name()
{
	return name;
}

void Thermostat::change_setting(int new_temp, Room& r)
{
	check_temp(new_temp, r);
}


void Thermostat::check_temp(int new_temp, Room& r)
{
	if(new_temp > setting)
		what_it_controls->turn_on(r);
	else
		what_it_controls->turn_off(r);
}