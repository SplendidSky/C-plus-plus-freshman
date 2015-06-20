#ifndef MESSAGE_H
#define MESSAGE_H
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include "Folder.h"
using namespace std;

class Message {
	friend class Folder;
private:
	string contents;
	set<Folder *> folders;
	void add_to_Folders(const Message &);
	void remove_from_Folders();
public:
	Message(const string &str = "") : contents(str) {}
	Message(const Message&);
	Message& operator=(const Message);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	friend void swap(Message&, Message&);
};
inline
void swap(Message &lMsg, Message &rMsg) {
	std::swap(lMsg.folders, rMsg.folders);
}

#endif