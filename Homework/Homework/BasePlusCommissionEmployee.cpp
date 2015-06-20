#include "BasePlusCommissionEmployee.h"
#include <iostream>

using std::cout;
using std::endl;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &fN, const string &lN,
    const string &sSN, double gS, double cR, double bS) : CommissionEmployee(fN, lN, sSN, gS, cR) {
    baseSalary = bS;
    cout << "BasePlusCommissionEmployee constructor: " << endl;
    print();
    cout << "\n\n";
}
BasePlusCommissionEmployee::~BasePlusCommissionEmployee() {
    cout << "BasePlusCommissionEmployee destructor: " << endl;
    print();
    cout << "\n\n";
}

void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    if (salary < 0)
        baseSalary = 0;
    else
        baseSalary = salary;
}
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried ";
    CommissionEmployee::print();
    cout << "\nbase salary: " << getBaseSalary();
}
