#include <string>
#include <iostream>

using namespace std;

class Interface
{
public:
	virtual void Request() = 0;
	virtual ~Interface() { printf("~interface\n"); }
};

class RealClass : public Interface
{
public:
	virtual void Request()
	{
		cout << "真实的请求" << endl;
	}
	~RealClass()
	{
		printf("~RealClass\n");
	}
};

class ProxyClass : public Interface
{
private:
	RealClass m_realClass;
public:
	virtual void Request()
	{
		m_realClass.Request();
	}
	~ProxyClass()
	{
		printf("~ProxyClass\n");
	}
};

int main()
{
	ProxyClass* test = new ProxyClass();
	test->Request();
	delete test;
	return 0;
}

