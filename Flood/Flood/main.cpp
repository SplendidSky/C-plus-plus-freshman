#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    while (1) {
        vector<string> friends;
        int n, m;
        cin >> n;
        if (n == 0)
            break;
        cin >> m;
        for (int i = 0; i < n; i++) {
            string f;
            cin >> f;
            char f_[20];
            for (int i = 0; i < f.length(); i++)
                f_[i] = toupper(f[i]);
            f_[f.length()] = '\0';
            friends.push_back(string(f_));
        }
        for (int i = 0; i < m; i++) {
            string s_;
            cin >> s_;
            char s[20];
            for (int i = 0; i < s_.length(); i++)
                s[i] = toupper(s_[i]);
            s[s_.length()] = '\0';
            vector<string>::iterator it = find(friends.begin(), friends.end(), string(s));
            if (it != friends.end())
                friends.erase(it);
        }
        cout << friends.size() << endl;
    }
}
