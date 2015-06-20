#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include "QueryResult.h"

using namespace std;

class TextQuery {
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};


#endif