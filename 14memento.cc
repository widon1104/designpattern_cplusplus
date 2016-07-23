#include <iostream>
#include <string>

using namespace std;

class Memo
{
public:
	string state;
	Memo(string strState)
	{
		state = strState;
	}
};

class Originator
{
public:
	string state;
	Memo* CreateMemo()
	{
		return new Memo(state);
	}
	void SetMemo(Memo* memo)
	{
		state = memo->state;
	}
	void Show()
	{
		cout << "状态: " << state << endl;
	}
};

class Caretaker
{
public:
	Memo* memo;
};

int main()
{
	Originator* on = new Originator();
	on->state = "on";
	on->Show();

	Caretaker* c = new Caretaker();
	c->memo = on->CreateMemo();

	on->state = "off";
	on->Show();

	on->SetMemo(c->memo);
	on->Show();
	return 0;
}

