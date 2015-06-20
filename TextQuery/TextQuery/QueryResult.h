#pragma once
#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::vector;
using std::set;
using std::ostream;

class QueryResult
{
public:
	using line_no = vector<std::string>::size_type;
	QueryResult(std::string s, shared_ptr<set<line_no>> p, shared_ptr<vector<std::string>> f);
	~QueryResult();
private:
	std::string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<std::string>> file;
public:
	friend ostream & print(ostream & os, const QueryResult& qr);
};

#endif