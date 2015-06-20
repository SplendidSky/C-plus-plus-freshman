#include "CommissionEmployee.h"

#include <iostream>

using std::cout;
using std::endl;

CommissionEmployee::CommissionEmployee(const string &fN, const string &lN,
    const string &sSN, double gS, double cR) : firstName(fN), lastName(lN), 
    socialSecurityNumber(sSN), grossSales(gS), commissionRate(cR) {
    cout << "CommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
}
CommissionEmployee::~CommissionEmployee() {
    cout << "CommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
}

void CommissionEmployee::setFirstName(const string &fN) {
    firstName = fN;
}
string CommissionEmployee::getFirstName() const {
    return firstName;
}

void CommissionEmployee::setLastName(const string &lN) {
    lastName = lN;
}
string CommissionEmployee::getLastName() const {
    return lastName;
}

void CommissionEmployee::setSocialSecurityNumber(const string &sSN) {
    socialSecurityNumber = sSN;
}
string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}

void CommissionEmployee::setGrossSales(double sales) {
    grossSales = sales;
}
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}

void CommissionEmployee::setCommissionRate(double rate) {
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        commissionRate = 0;
}
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

double CommissionEmployee::earnings() const {
    return commissionRate * grossSales;
}
