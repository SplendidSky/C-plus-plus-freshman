#ifndef ISE
#define ISE
#include <string>

using namespace std;

class IllegalSubscriptException {
private:
	string msg;
public:
	explicit IllegalSubscriptException(string _msg
		= "Illegal Subscript Exception") {
		msg = _msg;
	}
	string what() { return msg; }
};

#endif
