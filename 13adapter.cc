#include <iostream>

using namespace std;

class Target
{
public:
	virtual void Request()
	{
		cout << "normal request" << endl;
	}
};

class SpecialTarget
{
public:
	virtual void SpecialRequest()
	{
		cout << "Special request" << endl;
	}
};

class Adapter : public Target
{
private:
	SpecialTarget* m_target;
public:
	Adapter()
	{
		m_target = new SpecialTarget();
	}
	~Adapter()
	{
		delete m_target;
	}
	virtual void Request()
	{
		m_target->SpecialRequest();
		Target::Request();
	}
};

int main()
{
	Adapter* a = new Adapter();
	a->Request();
	delete a;
	return 0;
}

