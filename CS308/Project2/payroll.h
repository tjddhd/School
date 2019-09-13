#ifndef PAYROLL_H
#define PAYROLL_H

#include "sales.h"

using namespace std;

class PayRoll
{
  public:
    float calculate_pay(const Employee& e, const Sales& s);
  private:
	float total_pay;
	Sales sales;
	Employee emp;
};

#endif