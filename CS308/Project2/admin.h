#ifndef ADMIN_H
#define ADMIN_H

#include "employee.h"
#include <vector>

using namespace std;

class Admin
{
  public:
  
  private:
    vector<Employee> emps;
	vector<float> pay;
	int day_count;
};

#endif