#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Request
{
public:
	string m_strContent;
	int m_nNumber;
};

class Manager
{
protected:
	Manager* manager;
	string name;
public:
	Manager(string temp)
	{
		name = temp;
	}
	void SetSuccessor(Manager* temp)
	{
		manager = temp;
	}
	virtual void GetRequest(Request* request) = 0;
};

class CommonManager : public Manager
{
public:
	CommonManager(string strTemp) : Manager(strTemp) {}
	virtual void GetRequest(Request* request)
	{
		if (request->m_nNumber >= 0 && request->m_nNumber < 10) 
		{
			cout << name << "处理了" << request->m_nNumber << "个请求" << endl;
		}
		else
		{
			manager->GetRequest(request);
		}
	}
};

class MajorDomo : public Manager
{
public:
	MajorDomo(string name) : Manager(name) {}
	virtual void GetRequest(Request* request)
	{
		if (request->m_nNumber >= 10) 
		{
			cout << name << "处理了" << request->m_nNumber
				<< "个请求" << endl;
		}
	}
};

int main()
{
	Manager* common = new CommonManager("张经理");
	Manager* major = new MajorDomo("李总监");

	common->SetSuccessor(major);

	Request* req = new Request();
	req->m_nNumber = 33;
	common->GetRequest(req);

	req->m_nNumber = 3;
	common->GetRequest(req);

	return 0;
}

