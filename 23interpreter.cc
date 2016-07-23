#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Context;
class AbstractExpression
{
public:
	virtual void Interpret(Context* context) = 0;
};

class Expression : public AbstractExpression
{
public:
	virtual void Interpret(Context* context)
	{
		cout << "终端解释器" << endl;
	}
};

class NonterminalExpression : public AbstractExpression
{
public:
	virtual void Interpret(Context* context)
	{
		cout << "非终端解释器" << endl;
	}
};

class Context
{
public:
	string input;
	string output;
};

int main()
{
	Context* context = new Context();
	vector<AbstractExpression*> express;
	express.push_back(new Expression());
	express.push_back(new NonterminalExpression());
	express.push_back(new NonterminalExpression());

	auto p = express.begin();
	while (p != express.end())
	{
		(*p)->Interpret(context);
		p++;
	}
	return 0;
}
