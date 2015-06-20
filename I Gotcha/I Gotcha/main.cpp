#include <map>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    map<string, string> m;
    string MAC;
    string STO;
    while (cin >> MAC >> STO) {
        if (m.find(MAC) != m.end() && m[MAC] != STO) {
            bool flag = true;
            for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
                if (it->second == STO && it->first != MAC) {
                    cout << "GOTCHA: " << STO << " MAC address not consistent." << endl;
                    flag = false;
                }
            }
            if (flag)
                cout << "GOTCHA: MAC address already occupied by " << m[MAC] << '.' << endl;
        }
        else if (m.find(MAC) != m.end() && m[MAC] == STO) {
            cout << m[MAC] << " signed in." << endl;
        }
        else {
            bool flag = true;
            for (map<string, string>::iterator it = m.begin(); it != m.end(); it++) {
                if (it->second == STO && it->first != MAC) {
                    cout << "GOTCHA: " << STO << " MAC address not consistent." << endl;
                    flag = false;
                }
            }
            if (flag) {
                m.insert(map<string, string>::value_type(MAC, STO));
                cout << STO << " registered." << endl;
            }
        }
    }
}
