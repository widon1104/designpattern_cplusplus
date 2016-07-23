#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Barbucer
{
public:
	void MakeMutton()
	{
		cout << "烤羊肉" << endl;
	}
	void MakeChickenWing()
	{
		cout << "烤鸡翅膀" << endl;
	}
};

class Command
{
protected:
	Barbucer* receiver;
public:
	Command(Barbucer* temp)
	{
		receiver = temp;
	}
	virtual void ExecuteCmd() = 0;
};

class BakeMuttonCmd : public Command
{
public:
	BakeMuttonCmd(Barbucer* temp) : Command(temp) {}
	virtual void ExecuteCmd()
	{
		receiver->MakeMutton();
	}
};

class ChickenWingCmd : public Command
{
public:
	ChickenWingCmd(Barbucer* temp) : Command(temp)
	{}
	virtual void ExecuteCmd()
	{
		receiver->MakeChickenWing();
	}
};

class Waiter
{
protected:
	vector<Command*> m_commandList;
public:
	void SetCmd(Command* temp)
	{
		m_commandList.push_back(temp);
		cout << "增加订单" << endl;
	}

	void Notify()
	{
		for (auto p = m_commandList.begin();
				p != m_commandList.end(); p++) {
			(*p)->ExecuteCmd();
		}
	}
};

int main()
{
	Barbucer* barbucer = new Barbucer();
	Command* cmd = new BakeMuttonCmd(barbucer);
	Command* cmd2 = new ChickenWingCmd(barbucer);
	Waiter* girl = new Waiter();
	girl->SetCmd(cmd);
	girl->SetCmd(cmd2);
	girl->Notify();
	return 0;
}

