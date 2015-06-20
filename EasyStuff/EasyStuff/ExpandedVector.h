#include <vector>
#include <algorithm>

using namespace std;

class ExpandedVector {
private:
    vector<int> v;
public:
    void push_back(int val) { v.push_back(val); }
    void my_reverse() {
        for (int i = 0; i < v.size() / 2; i++)
            swap(v[i], v[v.size() - i - 1]);
    }
    int size() { return v.size(); }
    int operator[](unsigned i) { return v[i]; }
};
