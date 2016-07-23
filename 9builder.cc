#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Product
{
private:
	vector<string> m_product;
public:
	void Add(string strtemp)
	{
		m_product.push_back(strtemp);
	}
	void Show()
	{
		auto p = m_product.begin();
		while (p != m_product.end()) {
			cout << *p << endl;
			p++;
		}
	}
};

class Builder
{
public:
	virtual void BuilderA() = 0;
	virtual void BuilderB() = 0;
	virtual Product* GetResult() = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
	Product* m_product;
public:
	ConcreteBuilder1()
	{
		m_product = new Product();
	}
	virtual void BuilderA()
	{
		m_product->Add("one");
	}
	virtual void BuilderB()
	{
		m_product->Add("two");
	}
	virtual Product* GetResult()
	{
		return m_product;
	}
};

class ConcreteBuilder2 : public Builder
{
private:
	Product* m_product;
public:
	ConcreteBuilder2()
	{
		m_product = new Product();
	}
	virtual void BuilderA()
	{
		m_product->Add("A");
	}
	virtual void BuilderB()
	{
		m_product->Add("B");
	}
	virtual Product* GetResult()
	{
		return m_product;
	}
};

class Direct
{
public:
	void Construct(Builder* temp)
	{
		temp->BuilderA();
		temp->BuilderB();
	}
};

int main()
{
	Direct* p  = new Direct();
	Builder* b1 = new ConcreteBuilder1();
	Builder* b2 = new ConcreteBuilder2();

	p->Construct(b1);
	Product* pb1 = b1->GetResult();
	pb1->Show();

	p->Construct(b2);
	Product* pb2 = b2->GetResult();
	pb2->Show();

	return 0;
}

