#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HandsetSoft
{
public:
	virtual void Run() = 0;
};

class HandsetGame : public HandsetSoft
{
public:
	virtual void Run()
	{
		cout << "运行手机游戏" << endl;
	}
};

class HandsetAddressList : public HandsetSoft
{
public:
	virtual void Run()
	{
		cout << "手机通讯录" << endl;
	}
};

class HandsetBrand
{
protected:
	HandsetSoft* m_soft;
public:
	void SetHandsetSoft(HandsetSoft* temp)
	{
		m_soft = temp;
	}
	virtual void Run() = 0;
};

class HandsetBrandM : public HandsetBrand
{
public:
	virtual void Run()
	{
		m_soft->Run();
	}
};

class HandsetBrandN : public HandsetBrand
{
public:
	virtual void Run()
	{
		m_soft->Run();
	}
};

int main()
{
	HandsetBrand* brand;
	brand = new HandsetBrandM();
	brand->SetHandsetSoft(new HandsetGame());
	brand->Run();
	brand->SetHandsetSoft(new HandsetAddressList());
	brand->Run();

	return 0;
}

