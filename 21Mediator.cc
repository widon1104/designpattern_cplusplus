#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Colleague;

class Mediator
{
public:
	virtual void Send(string message, Colleague* col) = 0;
};

class Colleague
{
protected:
	Mediator* mediator;
public:
	Colleague(Mediator* temp)
	{
		mediator = temp;
	}
};

class Colleague1 : public Colleague
{
public:
	Colleague1(Mediator* media) : Colleague(media) {}
	void Send(string strMessage)
	{
		mediator->Send(strMessage, this);
	}
	void Notify(string strMessage)
	{
		cout << "同事一获得了消息" << strMessage << endl;
	}
};

class Colleague2 : public Colleague
{
public:
	Colleague2(Mediator* media) : Colleague(media) {}
	void Send(string strMessage)
	{
		mediator->Send(strMessage, this);
	}
	void Notify(string strMessage)
	{
		cout << "同事二获得了消息" << strMessage << endl;
	}
};

class ConcreteMediator : public Mediator
{
public:
	Colleague1* col1;
	Colleague2* col2;
	virtual void Send(string message, Colleague* col)
	{
		if (col == col1) 
		{
			col2->Notify(message);
		}
	   	else
	   	{
			col1->Notify(message);
		}
	}
};

int main()
{
	ConcreteMediator* m = new ConcreteMediator();
	Colleague1* col1 = new Colleague1(m);
	Colleague2* col2 = new Colleague2(m);
	m->col1 = col1;
	m->col2 = col2;

	col1->Send("吃饭了吗?");
	col2->Send("还没吃，你请吗?");
	return 0;
}

