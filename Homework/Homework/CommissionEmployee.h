#ifndef COMMISSION_H
#define COMMISSION_H
#include <iostream>
#include <string>  //  C++ standard string class
using std::string;

class CommissionEmployee {
public:
	CommissionEmployee(const string &, const string &, const string &,
		double = 0.0, double = 0.0);

	/*******************************************************************
	*   cout << "CommissionEmployee constructor: " << endl;           *
	*   print();                                                      *
	*   cout << "\n\n";                                               *
	*   this is the print format in constructor                       *
	*******************************************************************/
	~CommissionEmployee();  //  destructor

	/*******************************************************************
	*   cout << "CommissionEmployee destructor: " << endl;            *
	*   print();                                                      *
	*   cout << "\n\n";                                               *
	*   this is the print format in destructor                        *
	*******************************************************************/

	void setFirstName(const string &);  //  set first name
	string getFirstName() const;  //  return first name

	void setLastName(const string &);  //  set last name
	string getLastName() const;  //  return last name

	void setSocialSecurityNumber(const string &);  //  set SSN
	string getSocialSecurityNumber() const;  //  return SSN

	void setGrossSales(double sales);  //  set gross sales amount
	double getGrossSales() const;  //  return gross sales amount

	void setCommissionRate(double rate);
	/*  set commission rate, note: rate should > 0.0 and < 1.0,
	if not, please set rate=0*/

	double getCommissionRate() const;  //  return commission rate

	double earnings() const;
	/*  calculate earnings, it is the product of
	commissionRate and grossSales*/

	void print() const {
		std::cout << "commission employee: "
			<< getFirstName() << ' ' << getLastName()
			<< "\nsocial security number: " << getSocialSecurityNumber()
			<< "\ngross sales: " << getGrossSales()
			<< "\ncommission rate: " << getCommissionRate();
	}  //  end function print

private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	double grossSales;  //  gross weekly sales
	double commissionRate;  //  commission percentage
};  //  end class CommissionEmployee

#endif
