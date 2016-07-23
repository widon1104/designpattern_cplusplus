#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Prototype
{
private:
	string m_strName;
public:
	Prototype(string strName)
	{
		m_strName = strName;
	}
	Prototype()
	{
		m_strName = "";
	}
	void Show()
	{
		cout << m_strName << endl;
	}
	virtual Prototype* Clone() = 0;
};

class ConcretePrototype1 : public Prototype
{
public:
	ConcretePrototype1(string strName) : Prototype(strName) {}
	ConcretePrototype1() {}
	virtual Prototype* Clone()
	{
		ConcretePrototype1 *p = new ConcretePrototype1();
		*p = *this;
		return p;
	}
};

int main()
{
	Prototype *p1 = new ConcretePrototype1("小王");
	Prototype *p2 = (ConcretePrototype1 *)p1->Clone();
	p1->Show();
	p2->Show();
	return 0;
}

