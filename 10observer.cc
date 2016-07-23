#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Secretary;

class StockObserver
{
private:
	string name;
	Secretary* sub;
public:
	StockObserver(string strname, Secretary* strsub)
	{
		name = strname;
		sub = strsub;
	}
	void Update();
};

class Secretary
{
private:
	vector<StockObserver> observers;
public:
	string action;
	void Add(StockObserver ob)
	{
		observers.push_back(ob);
	}
	void Notify()
	{
		auto p = observers.begin();
		while (p != observers.end()) {
			(*p).Update();
			p++;
		}
	}
};

void StockObserver::Update()
{
	cout << name << ":" << sub->action << "update" << endl;
}

int main()
{
	Secretary *p = new Secretary();
	StockObserver *s1 = new StockObserver("小李", p);
	StockObserver *s2 = new StockObserver("小赵", p);

	p->Add(*s1);
	p->Add(*s2);

	p->action = "老板来了";

	p->Notify();

	return 0;
}

