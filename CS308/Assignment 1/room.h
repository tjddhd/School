//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: room.h
// Semester: Spring 2014
//////////////////////////////

#ifndef ROOM_H
#define ROOM_H

#include<iostream>
#include "thermostat.h"

using namespace std;

class Thermostat;

class Room
{
  public:
  
	//Pre:
	//Post:
	//Desc:
    Room(string new_name="default"): name(new_name),temperature(65),thermostat_in_room(NULL) {}
	
	//Pre:
	//Post:
	//Desc:
	Room(const Room& r);
	
	//Pre:
	//Post:
	//Desc:
	~Room();
	
	//Pre:
	//Post:
	//Desc:
	Room& operator=(const Room& r);
	
	//Pre:
	//Post:
	//Desc:
	string get_name();
	
	//Pre:
	//Post:
	//Desc:
	int get_temp();
	
	//Pre:
	//Post:
	//Desc:
	void change_temp(int new_temp);
  private:
    string name;
	int temperature;
	Thermostat *thermostat_in_room;
};

#endif