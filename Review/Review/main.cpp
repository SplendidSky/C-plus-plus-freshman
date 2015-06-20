#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool sort_by_title(pair<string, unsigned> first, pair<string, unsigned> second) {
    return first.first < second.first;
}

bool sort_by_rating(pair<string, unsigned> first, pair<string, unsigned> second) {
    return first.second < second.second;
}

int main() {
    string check;
    getline(cin, check);
    if (check != "quit") {
        vector<pair<string, unsigned> > library;
        string kp = check;
        unsigned rate;
        cin >> rate;
        cin.get();
        library.push_back(make_pair(kp, rate));
        getline(cin, kp);
        while (kp != "quit") {
            cin >> rate;
            cin.get();
            library.push_back(make_pair(kp, rate));
            getline(cin, kp);
        }
        cout << "Thank you. You entered the following " << library.size() << " ratings:" << endl;
        cout << "Rating\tBook" << endl;
        for (int i = 0; i < library.size(); i++)
            cout << library[i].second << "\t" << library[i].first << endl;
        cout << "Sorted by title:" << endl;
        cout << "Rating\tBook" << endl;
        sort(library.begin(), library.end(), sort_by_title);
        for (int i = 0; i < library.size(); i++)
            cout << library[i].second << "\t" << library[i].first << endl;
        sort(library.begin(), library.end(), sort_by_rating);
        cout << "Sorted by rating:" << endl;
        cout << "Rating\tBook" << endl;
        for (int i = 0; i < library.size(); i++)
            cout << library[i].second << "\t" << library[i].first << endl;
        cout << "Bye." << endl;
    }
    else
        cout << "No entries. Bye." << endl;
    system("pause");
}
