#pragma once
#include <iostream>
using namespace std;
class IWarm // ����������� ����� ��������� � ���������� ���������
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
		cout << " ��������� ���������!" << endl;
	}
	void WarmOFF() override
	{
		cout << " ��������� ���������!" << endl;
	}
};