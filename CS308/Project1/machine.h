#ifndef MACHINE_H
#define MACHINE_H

#include "change.h"
#include "coffee.h"

using namespace std;

class Coffee;
class Change;

class Machine
{
  public:
    Machine():cream(false),sugar(false),sugar_amount(2) {}
	
	Machine(bool creamSelected, bool sugarSelected, Change& amount, Coffee& my_coffee):cream(creamSelected),sugar(sugarSelected),inserted(amount),dispensed(my_coffee),sugar_amount(2) {}
	
    void button_push(bool white, bool sweet, int amount);
	
	Coffee& coffee_dispense(Coffee& new_coffee);
	
  private:
    bool cream;
	bool sugar;
	int sugar_amount;
	Change inserted;
	Coffee dispensed;
};

#endif