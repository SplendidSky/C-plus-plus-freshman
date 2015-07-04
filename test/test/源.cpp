#include <iostream>
#include <string>
using namespace std;

//抽象类A
class A
{
public:
	A()
	{
		cout << "抽象类A的构造函数" << endl;
	}
	//纯虚函数fun
	virtual void fun1() = 0;
};

//抽象类B
class B
{
public:
	B()
	{
		cout << "抽象类B的构造函数" << endl;
	}
	//纯虚函数fun
	virtual void fun2() = 0;
};

//普通类C
class C
{
public:
	C()
	{
		cout << "类C的构造函数" << endl;
	}
};

//普通类D
class D
{
public:
	D()
	{
		cout << "类D的构造函数" << endl;
	}
};

//普通类E
class E
{
public:
	E()
	{
		cout << "类E的构造函数" << endl;
	}
};

//普通类F
class F
{
public:
	F()
	{
		cout << "类F的构造函数" << endl;
	}
};

//普通类G
class G
{
public:
	G()
	{
		cout << "类G的构造函数" << endl;
	}
};

//普通类H
class H
{
public:
	H()
	{
		cout << "类H的构造函数" << endl;
	}
};
//普通类M
class M
{
public:
	M()
	{
		cout << "类M的构造函数" << endl;
	}
};

class Test : public A, public B, virtual public C, virtual public D, public E, public F
{
public:
	Test() :B(), A(), D(), C(), F(), E()
	{
		cout << "类Test的构造函数" << endl;
	}
	void fun1()
	{
	}
	void fun2()
	{
	}
private:
	G g;
	static H h;
	static M m;
};

H Test::h;
M Test::m;

int main(int argc, char* argv[])
{
	Test test;
	system("pause");
	return EXIT_SUCCESS;
}