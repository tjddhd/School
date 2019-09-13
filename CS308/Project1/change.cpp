#include "change.h"
#include <iostream>

bool Change::can_pay()
{
  return total >= 35;
}

void Change::coin_return()
{
  cout<<total<<" cents has been returned"<<endl;
  total = 0;
}

void Change::set_total(int amount)
{
  total += amount;
  
  cout<<"You have now inserted "<<total<<" cents"<<endl;
}