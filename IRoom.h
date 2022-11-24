#pragma once
#include "ITemp.h"
#include "IWarm.h"
class IRoom
{
public:
	virtual void WarmingON() = 0;       // ��������� ���������
	virtual void WarmingOFF() = 0;      // ���������� ���������
	virtual float ReadingTemp() = 0;    // ���������� �����������	
};

class Room :public IRoom// ����� ��������� � ������� ����� ������� � ������ �����������
{
private:
	IWarm* Warm;
	ITemp* Temp;
public:
	Room(IWarm* Warm, ITemp* Temp)
	{
		this->Warm = Warm;
		this->Temp = Temp;
	}
	~Room() {
		if (Warm != nullptr)
			delete Warm;
		if (Temp != nullptr)
			delete Temp;
	}
	
	void WarmingON() override{ 
		Warm->WarmON();
	}
	void WarmingOFF() override {
		Warm->WarmOFF();
	}
	float ReadingTemp() override {		
		return Temp->SetTemp();
	}
	
};

