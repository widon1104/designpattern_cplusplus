#include <string>
#include <iostream>

using namespace std;

class LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "雷锋扫地" << endl;
	}
	virtual ~LeiFeng() {};
};

class Student : public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "学生扫地" << endl;
	}
};

class Volenter : public LeiFeng
{
public:
	virtual void Sweep()
	{
		cout << "志愿者扫地" << endl;
	}
};

class LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new LeiFeng();
	}
	virtual ~LeiFengFactory() {};
};

class StudentFactory : public LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new Student();
	}
};

class VolenterFactory : public LeiFengFactory
{
public:
	virtual LeiFeng* CreateLeiFeng()
	{
		return new Volenter();
	}
};


int main()
{
	LeiFengFactory *sf = new LeiFengFactory();
	LeiFeng *s = sf->CreateLeiFeng();
	s->Sweep();
	delete s;
	delete sf;
	return 0;
}

