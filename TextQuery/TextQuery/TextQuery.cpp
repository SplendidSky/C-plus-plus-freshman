#include "TextQuery.h"

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
	string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word) {
			auto &lines = wm[word]; //mapped_type If word doesn't not exist, lines will be nullptr.
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
QueryResult TextQuery::query(const string &sought) const {
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	map<string, shared_ptr<set<line_no>>>::const_iterator loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}