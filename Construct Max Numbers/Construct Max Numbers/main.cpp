#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool com(string a, string b) {
    if (a.length() < b.length()) {
        for (int i = 0, j = 0; i < b.length(); i++, j++) {
            if (j == a.length())
                j = 0;
            if (a[j] != b[i])
                return a[j] > b[i];
        }
        return a < b;
    }
    if (a.length() > b.length())
        return !com(b, a);
    return a > b;
}
int main() {
    int N;
    string data[1000];
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> data[i];
    std::stable_sort(data, data + N, com);
    for (int i = 0; i < N; i++)
        cout << data[i];
    cout << endl;
}
