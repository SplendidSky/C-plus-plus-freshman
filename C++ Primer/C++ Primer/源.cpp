#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <typeinfo>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>
#include <forward_list>
#include <functional>
#include <iterator>
#include <numeric>
#include <map>
#include <set>
#include <cctype>
#include <memory>
#include <typeinfo>
#include <tuple>
#include "HasPtr.h"
#include "Stack.h"

using namespace std;

int main() {
	auto item1 = make_tuple("ISBN", 100, 0.8);
	auto item2 = make_tuple("ISBN", 200, 0.9);
	tuple<int, int, int> int_tuple(10, 20, 30);
	cout << get<0>(int_tuple) << endl;
	tuple<string, vector<string>, pair<string, int>> mix_tuple;
	cout << typeid(decltype(item1)).name() << endl;
	cout << typeid(decltype(item2)).name() << endl;
	typedef decltype(item1) trans;
	cout << tuple_size<trans>::value << endl;
	cout << get<0>(item1) << endl;
}
