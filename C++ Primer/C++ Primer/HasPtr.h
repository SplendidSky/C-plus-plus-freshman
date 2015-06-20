#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

using namespace std;

class HasPtr {
public:
	HasPtr(const string &s = string()) : ps(new string(s)) {}
	HasPtr(const HasPtr &p) : ps(p.ps) {}
	int getUseCnt() { return ps.use_count(); }
	bool unique() { return ps.unique(); }
	friend void swap(HasPtr &lhs, HasPtr &rhs);
private:
	shared_ptr<string> ps;
};

void swap(HasPtr &lhs, HasPtr &rhs) {
	std::swap(lhs.ps, rhs.ps);
}