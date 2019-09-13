#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

using namespace std;

class Employee
{
  public:
  
  private:
    string f_name, l_name;
	double SSN;
	bool isSalary, salary_overtime;
    int hours_worked;
	float overtime_rate;
};

#endif