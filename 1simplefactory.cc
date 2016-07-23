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
	virtual double GetResult()
	{
		return m_nFirst + m_nSecond;
	}
};

class SubOperation : public COperation
{
public:
	virtual double GetResult()
	{
		return m_nFirst - m_nSecond;
	}
};

class CCalculatorFactory
{
public:
	static COperation* Create(char cOperator);
};

COperation* CCalculatorFactory::Create(char cOperator)
{
	COperation *oper;
	switch (cOperator)
	{
	case '+':
		oper = new AddOperation();
		break;
	case '-':
		oper = new SubOperation();
		break;
	default:
		oper = new AddOperation();
		break;
	}
	return oper;
}


int main()
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	COperation *op = CCalculatorFactory::Create('+');
	op->m_nFirst = a;
	op->m_nSecond = b;
	cout << op->GetResult() << endl;
	return 0;
}

