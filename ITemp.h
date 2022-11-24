#pragma once
#include <stdlib.h>
class ITemp // абстрактный класс датчик температуры
{
public:
	virtual float SetTemp() = 0;
};

class Temp:public ITemp
{	
public:
	float temp;
	float SetTemp() override
	{
		temp = rand() % 50 - 7.4; // первоначальное значение температуры
		return temp;
	}
};

