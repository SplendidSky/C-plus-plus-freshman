#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vector<pair<int, bool>> print;
        for (int i = 0; i < a; i++) {
            int p;
            cin >> p;
            if (i == b)
                print.push_back(make_pair(p, true));
            else
                print.push_back(make_pair(p, false));
        }
        vector<pair<int, bool>>::iterator begin = print.begin();
        int j = 0;
        while (1) {
            bool sw = false;
            for (vector<pair<int, bool>>::iterator it = print.begin(); it != print.end(); it++) {
                if (begin->first < it->first) {
                    pair<int, bool> temp = *begin;
                    print.erase(begin);
                    print.push_back(temp);
                    begin = print.begin();
                    sw = true;
                    break;
                }
            }
            if (!sw) {
                if (begin->second == true) {
                    cout << j + 1 << endl;
                    break;
                }
                print.erase(begin);
                j++;
                begin = print.begin();
            }
        }
    }
}