#pragma once
#include <iostream>
#include "IRoom.h"
#include <windows.h>
#include <conio.h>

using namespace std;

class IMode // интерфейс режимов
{
public:	
	void virtual SetClimate(IRoom* Room) = 0;   // функция установки климата	
};


class ModeEconom :public IMode // режим климата эконом
{
public:
	char i;
	void SetClimate(IRoom* Room) override // функция установления климата
	{
		cout << "Эконом  режим" << endl;
		float temp;
		cout << " Включение отопления если темп меньше 6 градусов и отключение когда темп более 10 градусов " << endl;
		while (i != '\n')
		{
			temp = Room->ReadingTemp();
			if (temp < 6)
			{
				cout << " Температура составляет " << temp << " градусов " << endl;
				Room->WarmingON(); // функция включения отопления
				Sleep(8000);
				while (temp < 10)
				{					
					temp += 0.1; // увеличение температуры
					cout << " Температура составляет " << temp << " градусов " << endl;
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
					temp -= 0.1; //уменьшение температуры, условно говоря зима за окном
					cout << " Температура составляет " << temp << " градусов " << endl;					
					Sleep(500);
					system("cls");
				}
			}
		}
	}
};

class ModeComfort :public IMode // режим климата комфорт
{
public:
	char i;
	void SetClimate(IRoom* Room) override // функция установления климата
	{
		cout << " Комфорт режим" << endl;
		float temp;
		cout << " Включение отопления при температуре менее 20 градусов и отключение если температура более 25 градусов " << endl;
		while (i != '\n')
		{
			temp = Room->ReadingTemp();
			if (temp < 20)
			{
				cout << " Температура составляет " << temp << " градусов " << endl;
				Room->WarmingON(); // функция включения отопления
				Sleep(8000);
				while (temp < 25)
				{					
					temp += 0.1; // увеличение температуры
					cout << " Температура составляет " << temp << " градусов " << endl;
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
					temp -= 0.1; //уменьшение температуры, условно говоря зима за окном
					cout << " Температура составляет " << temp << " градусов " << endl;					
					Sleep(500);
					system("cls");
				}				
			}
		}
	}
};

class ModeUser :public IMode // режим климата пользователя
{
public:
	char i;	
	void SetClimate(IRoom* Room) override // функция установления климата
	{
		cout << " Пользовательский режим" << endl;
		float temp;
		cout << " Условно говоря пользователь ввел нижний порог температуры 25 градусов, а верхний 30 " << endl;		
		while (i != '\n')
		{			
			temp = Room->ReadingTemp();
			if (temp < 25)
			{				
				cout << " Температура составляет " << temp << " градусов " << endl;				
				Room->WarmingON(); // функция включения отопления
				Sleep(8000);
				while (temp < 30)
				{											
					temp += 0.1; // увеличение температуры
					cout << " Температура составляет " <<temp << " градусов " << endl;
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
					temp -= 0.1; //уменьшение температуры, условно говоря зима за окном
					cout << " Температура составляет " << temp << " градусов " << endl;
				
					Sleep(500);
					system("cls");					
				}
				
			}
		}
	}
};