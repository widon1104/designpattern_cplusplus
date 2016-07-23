#include <string>
#include <iostream>
#include <vector>

using namespace std;

class IUser
{
public:
	virtual void GetUser() = 0;
	virtual void InsertUser() = 0;
};

class CAccessUser : public IUser
{
public:
	virtual void GetUser()
	{
		cout << "Access GetUser" << endl;
	}
	virtual void InsertUser()
	{
		cout << "Access InsertUser" << endl;
	}
};

class IFactory
{
public:
	virtual IUser* CreateUser() = 0;
};

class AccessFactory : public IFactory
{
public:
	virtual IUser* CreateUser()
	{
		return new CAccessUser();
	}
};

int main()
{
	AccessFactory* factory = new AccessFactory();
	IUser* user = factory->CreateUser();
	user->GetUser();
	return 0;
}

