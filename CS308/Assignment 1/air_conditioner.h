//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: air_conditioner.h
// Semester: Spring 2014
//////////////////////////////

#ifndef AIR_CONDITIONER_H
#define AIR_CONDITIONER_H

#include "room.h"
#include <iostream>

using namespace std;

class Room;

class Air_conditioner
{
	public:
	
		//Pre:
		//Post:
		//Desc:
		Air_conditioner(): name("default"),location(NULL),state(false) {}
		
		//Pre:
		//Post:
		//Desc:
		Air_conditioner(const Air_conditioner& src);
		
		//Pre:
		//Post:
		//Desc:
		~Air_conditioner(); 
		
		//Pre:
		//Post:
		//Desc:
		Air_conditioner& operator=(const Air_conditioner& src);
		
		//Pre:
		//Post:
		//Desc:
		string get_name();
		
		//Pre:
		//Post:
		//Desc:
		void turn_on(Room& r);
		
		//Pre:
		//Post:
		//Desc:
		void turn_off(Room& r);
		
	private:
		string name;
		Room* location;
		bool state;
};

#endif