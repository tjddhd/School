#include "payroll.h"

float calculate_pay(const Employee& e, const Sales& s))
{
  total_pay = 0.0;
  emp = e;
  sales = s;
  if(isSalary)
  {
    total_pay += emp.base_salary;
	if(salary_overtime)
	{
	  total_pay += (emp.hours_worked - 8)*1.25;
	}
  }
  else
  {
    if(emp.hours_worked <= 8)
	{
	  total_pay += emp.hours_worked * emp.hourly_rate;
	}
	else
	{
	  total_pay += 8* emp.hourly_rate;
	  total_pay += (emp.hours_worked - 8) * 1.5;
	}
  }
  
  if(s.sales_amounts.isNull() != true)
  {
    for(int i = 0; i <s.sales_amounts.count(); i++
	{
	  total_pay += s.sales_amounts[i] * commission_rate;
	}
  }
  
  return total_pay
}