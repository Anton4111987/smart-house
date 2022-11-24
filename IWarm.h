#pragma once
#include <iostream>
using namespace std;
class IWarm // абстрактный класс включения и выключения отопления
{
public:
	virtual void WarmON() = 0; //
	virtual void  WarmOFF() = 0;
};

class Warm : public IWarm
{
public:
	void WarmON() override
	{
		cout << " Включение отопления!" << endl;
	}
	void WarmOFF() override
	{
		cout << " Отопление отключено!" << endl;
	}
};