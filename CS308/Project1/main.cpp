#include "person.h"
#include "coffee.h"
#include "machine.h"
#include "change.h"
#include <iostream>

using namespace std;

int main()
{
  
  /*
  1.	Fred puts in a quarter and then selects a coffee, then pushes the coin return lever.
  2.	Fred puts two quarters in and then selects a coffee.
  3.	Fred selects black with sugar, then changes his mind and selects black and then inserts a quarter and a dime.
  4.	Fred inserts 3 quarters. Fred buys two coffees, white with sugar. The sugar dispenser runs out of sugar after the first.
  */
  
  cout<<"Scenario 1"<<endl;
  Person Fred(Machine coffee_machine);
  Fred.insert_coins(25);
  Fred.selection(true,true);
  Fred.coin_return();
  
  cout<<"Scenario 2"<<endl;
  Fred.insert_coins(50);
  Fred.selection(true,true);
  
  cout<<"Scenario 3"<<endl;
  Fred.selection(false,true);
  Fred.selection(false,false);
  Fred.insert_coins(35);
  
  cout<<"Scenario 4"<<endl;
  Fred.insert_coins(75);
  Fred.selection(true,true);
  Fred.selection(true,true);
  
  return 0;
}