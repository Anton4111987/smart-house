// Реализация умного дома с ООП.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include "IWarm.h"
#include "IRoom.h"
#include "ITemp.h"
#include "IMode.h"

using namespace std;

class controller  //  это контроллер 
{
private:
    string brand;
    string model;
    int s_n;
   
public:   
    controller()
    {
        this->brand = "No brand";
        this->model = "No model";
        this->s_n = 0000000;
    }
    controller(string brand, string model, int s_n)
    {
        this->brand = brand;
        this->model = model;
        this->s_n = s_n;
    }
    void control(IMode* IMode, IRoom * Room)  // функция управление на контроллере, т.е. можно включить любой режим климата
    {
        IMode->SetClimate(Room);
    }

};





int main()
{
    srand(time(0));
    setlocale(LC_ALL, "RUS");
    
    controller  controller;
       
    //controller.control(new ModeUser,new Room(new Warm,new Temp));
    controller.control(new ModeEconom, new Room(new Warm, new Temp));
   // controller.control(new ModeComfort, new Room(new Warm, new Temp));
   
    return 0;
}

