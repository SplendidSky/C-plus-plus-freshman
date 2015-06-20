#include "Message.h"
#include <algorithm>

Message::~Message() {}
Message::Message(const Message& msg) {
	contents = msg.contents;
	for (auto const &f : msg.folders)
		folders.insert(f);
}
Message& Message::operator=(Message msg) {
	swap(*this, msg);
	return *this;
}
void Message::save(Folder &fd) {
	fd.messages.insert(this);
	folders.insert(&fd);
}
void Message::remove(Folder &fd) {
	fd.messages.erase(this);
	folders.erase(&fd);
}
