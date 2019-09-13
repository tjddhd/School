#ifndef PERSON_H
#define PERSON_H

#include "coffee.h"
#include "machine.h"
#include "change.h"
#include <vector>
#include <iostream>

using namespace std;

class Machine;
class Coffee;
class Change;

class Person
{
  public:
    Person() {}
	
	Person(Machine m):my_machine(m) {}
	
	void selection(bool white, bool sugar);
	
	void insert_coins(int amount);
	
	void coin_return();
  private:
    vector<Coffee> my_coffees;
	Machine my_machine;
	Change my_change;
};

#endif