#ifndef FOLDER_H
#define FOLDER_H
#include <iostream>
#include "Message.h"

using namespace std;

class Folder {
	friend class Message;
private:
	set<Message *> messages;
};

#endif