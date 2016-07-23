#include <iostream>

using namespace std;

class COperation
{
public:
	int m_nFirst;
	int m_nSecond;
	virtual double GetResult() = 0;
};

class AddOperation : public COperation
{
public:
	AddOperation(int a, int b)
	{
		m_nFirst = a;
		m_nSecond = b;
	}
	virtual double GetResult()
	{
		return m_nFirst + m_nSecond;
	}
};

class SubOperation : public COperation
{
public:
	SubOperation(int a, int b)
	{
		m_nFirst = a;
		m_nSecond = b;
	}
	virtual double GetResult()
	{
		return m_nFirst - m_nSecond;
	}
};

class Context
{
private:
	COperation *op;
public:
	Context(COperation* temp)
	{
		op = temp;
	}
	double GetResult()
	{
		return op->GetResult();
	}
};


int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	//Context* context = new Context(new AddOperation(a,b));
	Context* context = new Context(new SubOperation(a,b));
	cout << context->GetResult() << endl;
	return 0;
}

