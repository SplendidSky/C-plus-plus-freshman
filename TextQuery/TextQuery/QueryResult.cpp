#include "QueryResult.h"


QueryResult::QueryResult(std::string s, shared_ptr<set<line_no>> p, shared_ptr<vector<std::string>> f) : sought(s), lines(p), file(f) {}


QueryResult::QueryResult::~QueryResult()
{
}


ostream &print(ostream & os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " " << "time(s)" << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << std::endl;
	return os;
}
