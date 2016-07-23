#include <iostream>

using namespace std;

class Work;
class ForenoonState;
class NoonState;

class State
{
public:
	virtual void WriteProgram(Work* w) = 0;
};

class Work
{
private:
	State* current;
public:
	double hour;
	Work();
	void SetState(State* temp)
	{
		if (current) {
			delete current;
		}
		current = temp;
	}
	void WriteProgram()
	{
		current->WriteProgram(this);
	}
	~Work()
	{
		if (current) {
			delete current;
		}
	}
};

class NoonState : public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		cout << "execute" << endl;
		if ((w->hour) < 13) {
			cout << "Noon hour < 13" << endl;
		} else {
			cout << "Noon hour > 13" << endl;
		}
	}
};

class ForenoonState : public State
{
public:
	virtual void WriteProgram(Work* w)
	{
		if ((w->hour) < 12) {
			cout << "forenoon hour < 12" << endl;
		} else {
			w->SetState(new NoonState());
			w->WriteProgram();
		}
	}
};

Work::Work()
{
	current = new ForenoonState();
}

int main()
{
	Work* mywork = new Work();
	mywork->hour = 9;
	mywork->WriteProgram();
	mywork->hour = 14;
	mywork->WriteProgram();
	delete mywork;
	return 0;
}

