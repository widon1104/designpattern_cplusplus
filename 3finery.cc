#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
	string m_strName;
public:
	Person(string strName)
	{
		m_strName = strName;
	}
	Person() {}
	virtual void Show()
	{
		cout << "装扮的是:" << m_strName << endl;
	}
};

class Finery : public Person
{
protected:
	Person* m_component;
public:
	void Decorate(Person* component)
	{
		m_component = component;
	}
	virtual void Show()
	{
		m_component->Show();
	}
};

class TShirt : public Finery
{
public:
	virtual void Show()
	{
		cout << "T Shirts" << endl;
		m_component->Show();
	}
};

class BigTrouser : public Finery
{
public:
	virtual void Show()
	{
		cout << "Big Trouser" << endl;
		m_component->Show();
	}
};

int main()
{
	Person *p = new Person("小李");
	BigTrouser *bt = new BigTrouser();
	TShirt *ts = new TShirt();

	bt->Decorate(p);
	ts->Decorate(bt);
	ts->Show();
	return 0;
}

