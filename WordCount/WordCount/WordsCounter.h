#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

class WordsCounter {
private:
    int bound;
public:
    WordsCounter(int _bound) : bound(_bound) {}
    void setBound(int newBound) { bound = newBound; }
    int operator()(string text) {
        istringstream is(text);
        string s;
        set<string> count;
        while (is >> s) {
            if (s.length() >= bound)
                count.insert(s);
        }
        return count.size();
    }
};
