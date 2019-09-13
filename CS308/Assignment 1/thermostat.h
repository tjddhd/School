//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: thermostat.h
// Semester: Spring 2014
//////////////////////////////

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "air_conditioner.h"
#include "room.h"
#include<iostream>

using namespace std;

class Air_conditioner;
class Room;

class Thermostat
{
	public:
		//Pre:
		//Post:
		//Desc:
		Thermostat(): name("default"),what_it_controls(NULL),location(NULL),setting(65) {}
		
		//Pre:
		//Post:
		//Desc:
		Thermostat(const Thermostat& src);
		
		//Pre:
		//Post:
		//Desc:
		~Thermostat();
		
		//Pre:
		//Post:
		//Desc:
		Thermostat& operator=(const Thermostat& src);
		
		//Pre:
		//Post:
		//Desc:
		string get_name();
		
		//Pre:
		//Post:
		//Desc:
		void change_setting(int new_temp, Room& r);
		
		//Pre:
		//Post:
		//Desc:
		void check_temp(int new_temp, Room& r);
		
	private:
		string name;
		Air_conditioner* what_it_controls;
		Room* location;
		int setting;
};

#endif