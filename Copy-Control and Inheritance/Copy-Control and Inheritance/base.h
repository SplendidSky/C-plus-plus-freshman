#ifndef __BASE_H__
#define __BASE_H__
class Base {
public:
	explicit Base(int _value = 0) : value(_value) {}
	int getValue() const {
		return value;
	}
	virtual ~Base() {}
private:
	int value;
};
#endif
