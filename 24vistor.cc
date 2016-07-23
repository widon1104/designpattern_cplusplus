#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Man;
class Woman;
class Action
{
public:
	virtual void GetManConclusion(Man* concreteElementA) = 0;
	virtual void GetWomanConclusion(Woman* concreteElementB) = 0;
};

class Person
{
public:
	virtual void Accept(Action* visitor) = 0;
};

class Man : public Person
{
public:
	virtual void Accept(Action* visitor)
	{
		visitor->GetManConclusion(this);
	}
};

class Woman : public Person
{
public:
	virtual void Accept(Action* visitor)
	{
		visitor->GetWomanConclusion(this);
	}
};

class Success : public Action
{
public:
	virtual void GetManConclusion(Man* concreteElementA)
	{
		cout << "Success GetManConclusion" << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteElementB)
	{
		cout << "Success GetWomanConclusion" << endl;
	}
};

class Failure : public Action
{
public:
	virtual void GetManConclusion(Man * concreteElementA)
	{
		cout << "Failure GetManConclusion" << endl;
	}
	virtual void GetWomanConclusion(Woman* concreteElementB)
	{
		cout << "Failure GetWomanConclusion" << endl;
	}
};

class ObjectStruture
{
private:
	vector<Person*> m_personList;
public:
	void Add(Person* p)
	{
		m_personList.push_back(p);
	}
	void Display(Action* a)
	{
		auto p = m_personList.begin();
		while (p != m_personList.end())
		{
			(*p)->Accept(a);
			p++;
		}
	}
};

int main()
{
	ObjectStruture* os = new ObjectStruture();
	os->Add(new Man());
	os->Add(new Woman());

	Success* success = new Success();
	os->Display(success);

	Failure* f1 = new Failure();
	os->Display(f1);

	return 0;
}

