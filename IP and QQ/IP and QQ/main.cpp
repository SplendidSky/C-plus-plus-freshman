#include <map>
#include <string>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, set<string> > QQ_IP;
    map<string, set<string> > IP_QQ;
    for (int i = 0; i < n; i++) {
        string QQ, IP;
        cin >> QQ >> IP;
        QQ_IP[QQ].insert(IP);
        IP_QQ[IP].insert(QQ);
    }
    string testQQ, testIP;
    cin >> testIP >> testQQ;
    if (IP_QQ.find(testIP) != IP_QQ.end()) {
        cout << testIP << " ==> [ ";
        for (set<string>::iterator it = IP_QQ[testIP].begin(); it != IP_QQ[testIP].end(); it++)
            cout << *it << " ";
        cout << "]" << endl;
    }
    else
        cout << "no ip" << endl;
    if (QQ_IP.find(testQQ) != QQ_IP.end()) {
        cout << testQQ << " ==> [ ";
        for (set<string>::iterator it = QQ_IP[testQQ].begin(); it != QQ_IP[testQQ].end(); it++)
            cout << *it << " ";
        cout << "]" << endl;
    }
    else
        cout << "no qq" << endl;
}
