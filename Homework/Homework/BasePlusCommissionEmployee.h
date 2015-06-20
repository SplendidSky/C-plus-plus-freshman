#ifndef BASEPLUS_H
#define BASEPLUS_H

#include <string>  //  C++ standard string class
using std::string;

#include "CommissionEmployee.h"  //  CommissionEmployee class declaration

class BasePlusCommissionEmployee : public CommissionEmployee {
public:
	BasePlusCommissionEmployee(const string &, const string &,
		const string &, double = 0.0, double = 0.0, double = 0.0);
	/*******************************************************************
	*   cout << "BasePlusCommissionEmployee constructor: " << endl;   *
	*   print();                                                      *
	*   cout << "\n\n";                                               *
	*   this is the print format in constructor                       *
	*******************************************************************/

	~BasePlusCommissionEmployee();  //  destructor

	/*******************************************************************
	*   cout << "BasePlusCommissionEmployee destructor: " << endl;    *
	*   print();                                                      *
	*   cout << "\n\n";                                               *
	*   this is the print format in destructor                        *
	*******************************************************************/

	//  set base salary, if salary<0, then set salary=0
	void setBaseSalary(double salary);
	double getBaseSalary() const;  //  return base salary

	double earnings() const;
	/*  calculate earnings, it is the sum of baseSalary and
	CommissionEmployee's earnings*/

	void print() const;  //  print BasePlusCommissionEmployee object

	/*******************************************************************
	*   cout << "base-salaried ";                                     *
	*   CommissionEmployee::print();                                  *
	*   cout << "\nbase salary: " << getBaseSalary()                  *
	*   this is the print format in BasePlusCommissionEmployee::print *
	*******************************************************************/

private:
	double baseSalary;  //  base salary
};  //  end class BasePlusCommissionEmployee

#endif
