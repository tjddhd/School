//////////////////////////////
// Name: Thomas Dolan
// Professor: William Bond
// Class: CS308
// Assignment: 1
// File: main.cpp
// Semester: Spring 2014
//////////////////////////////

#include "room.h"
#include "thermostat.h"
#include "air_conditioner.h"

using namespace std;

int main()
{
	Room r("room 400");
	
	cout<<r.get_name()<<" has a current temperature of " <<r.get_temp()<<endl;
	
	//r.change_temp(70);
	//cout<<r.get_name()<<" has a current temperature of " <<r.get_temp()<<endl;
	
	//r.change_temp(60);
	//cout<<r.get_name()<<" has a current temperature of " <<r.get_temp()<<endl;
	
	//r.change_temp(55);
	//cout<<r.get_name()<<" has a current temperature of " <<r.get_temp()<<endl;
	
	return 0;
}