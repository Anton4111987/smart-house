#pragma once
#include <iostream>
#include "IRoom.h"
#include <windows.h>
#include <conio.h>

using namespace std;

class IMode // ��������� �������
{
public:	
	void virtual SetClimate(IRoom* Room) = 0;   // ������� ��������� �������	
};


class ModeEconom :public IMode // ����� ������� ������
{
public:
	char i;
	void SetClimate(IRoom* Room) override // ������� ������������ �������
	{
		cout << "������  �����" << endl;
		float temp;
		cout << " ��������� ��������� ���� ���� ������ 6 �������� � ���������� ����� ���� ����� 10 �������� " << endl;
		while (i != '\n')
		{
			temp = Room->ReadingTemp();
			if (temp < 6)
			{
				cout << " ����������� ���������� " << temp << " �������� " << endl;
				Room->WarmingON(); // ������� ��������� ���������
				Sleep(8000);
				while (temp < 10)
				{					
					temp += 0.1; // ���������� �����������
					cout << " ����������� ���������� " << temp << " �������� " << endl;
					Sleep(500);
					system("cls");
				}
			}
			if (temp >= 10)
			{
				Room->WarmingOFF();
				Sleep(8000);
				while (temp >6)
				{
					temp -= 0.1; //���������� �����������, ������� ������ ���� �� �����
					cout << " ����������� ���������� " << temp << " �������� " << endl;					
					Sleep(500);
					system("cls");
				}
			}
		}
	}
};

class ModeComfort :public IMode // ����� ������� �������
{
public:
	char i;
	void SetClimate(IRoom* Room) override // ������� ������������ �������
	{
		cout << " ������� �����" << endl;
		float temp;
		cout << " ��������� ��������� ��� ����������� ����� 20 �������� � ���������� ���� ����������� ����� 25 �������� " << endl;
		while (i != '\n')
		{
			temp = Room->ReadingTemp();
			if (temp < 20)
			{
				cout << " ����������� ���������� " << temp << " �������� " << endl;
				Room->WarmingON(); // ������� ��������� ���������
				Sleep(8000);
				while (temp < 25)
				{					
					temp += 0.1; // ���������� �����������
					cout << " ����������� ���������� " << temp << " �������� " << endl;
					Sleep(500);
					system("cls");
				}
			}
			if (temp >= 25)
			{
				Room->WarmingOFF();
				Sleep(8000);
				while (temp > 20)
				{
					temp -= 0.1; //���������� �����������, ������� ������ ���� �� �����
					cout << " ����������� ���������� " << temp << " �������� " << endl;					
					Sleep(500);
					system("cls");
				}				
			}
		}
	}
};

class ModeUser :public IMode // ����� ������� ������������
{
public:
	char i;	
	void SetClimate(IRoom* Room) override // ������� ������������ �������
	{
		cout << " ���������������� �����" << endl;
		float temp;
		cout << " ������� ������ ������������ ���� ������ ����� ����������� 25 ��������, � ������� 30 " << endl;		
		while (i != '\n')
		{			
			temp = Room->ReadingTemp();
			if (temp < 25)
			{				
				cout << " ����������� ���������� " << temp << " �������� " << endl;				
				Room->WarmingON(); // ������� ��������� ���������
				Sleep(8000);
				while (temp < 30)
				{											
					temp += 0.1; // ���������� �����������
					cout << " ����������� ���������� " <<temp << " �������� " << endl;
					Sleep(500);
					system("cls");
				}				
			}
			if (temp >= 30)
			{
				Room->WarmingOFF();
				Sleep(8000);				
				while (temp > 25)
				{					
					temp -= 0.1; //���������� �����������, ������� ������ ���� �� �����
					cout << " ����������� ���������� " << temp << " �������� " << endl;
				
					Sleep(500);
					system("cls");					
				}
				
			}
		}
	}
};