#include <iostream>
#include "multi_throw.h"

using namespace std;

int main() {
    int test;
    while (cin >> test) {
        try {
            multi_throw(test);
        }
        catch (out_of_range or) {
            cout << "Exception: " << or.what() << endl;
            cout << "Exception type: class out_of_range" << endl;
        }
        catch (runtime_error re) {
            cout << "Exception: " << re.what() << endl;
            cout << "Exception type: runtime_error" << endl;
        }
        catch (logic_error le) {
            cout << "Exception: " << le.what() << endl;
            cout << "Exception type: logic_error" << endl;
        }
        catch (int) {
            cout << "Exception: " << test << endl;
            cout << "Exception type: int" << endl;
        }
    }
}
