#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

//  BasePlusCommissionEmployee class definition
#include "BasePlusCommissionEmployee.h"


int main() {
	//  set floating-point output formatting
	cout << fixed << setprecision(2);

	BasePlusCommissionEmployee
		bpc("Lisa", "Jones", "555-55-5555", 2000, .06, 800);
	bpc.setFirstName("frank");
	cout << bpc.earnings() << endl;
	cout << bpc.CommissionEmployee::earnings();

	{  //  begin new scope
		CommissionEmployee c(
			"Bob", "Lewis", "333-33-3333", 5000, .04);
	}  //  end scope

	cout << endl;
	cout << endl;
	BasePlusCommissionEmployee
		bpc2("Mark", "Sands", "888-88-8888", 8000, .15, 2000);
	cout << endl;
	return 0;
}  //  end main
