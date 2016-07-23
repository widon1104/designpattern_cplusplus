#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WebSite
{
public:
	virtual void Use() = 0;
};

class ConcreteWebSite: public WebSite
{
private:
	string name;
public:
	ConcreteWebSite(string strName)
	{
		name = strName;
	}
	virtual void Use()
	{
		cout << "网站分类: " << name << endl;
	}
};

class UnShareWebSite : public WebSite
{
private:
	string name;
public:
	UnShareWebSite(string strName)
	{
		name = strName;
	}
	virtual void Use()
	{
		cout << "不共享网站: " << name << endl;
	}
};

class WebFactory
{
private:
	vector<WebSite*> websites;
public:
	WebSite* GetWeb()
	{
		vector<WebSite*>::iterator p = websites.begin();
		return *p;
	}
	WebFactory()
	{
		websites.push_back(new ConcreteWebSite("测试"));
	}
};

int main()
{
	WebFactory* f = new WebFactory();
	WebSite* ws = f->GetWeb();
	ws->Use();
	WebSite* ws2 = f->GetWeb();
	ws2->Use();

	WebSite* ws3 = new UnShareWebSite("测试");
	ws3->Use();
	return 0;
}

