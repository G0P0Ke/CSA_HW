#ifndef __ship__
#define __ship__

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "rnd.h"
#include "transport.h"

// Подсчет рандомного действительного значения
double randomS(double b, double e);

// виды судна
enum ship_type {
    LINER, TUGBOAT, TANKER
};

//------------------------------------------------------------------------------
// корабль
class Ship: public Transport{
private:
    ship_type ship_type; // вид судна
    int displacement; // водоизмещение
public:
    // Деструктор корабля
    virtual ~Ship(){}

    // Ввод параметров корабля из файла
    virtual void In(std::ifstream &ifst);

    // Случайный ввод параметров корабля
    virtual void InRnd();

    // Вывод параметров корабля в форматируемый поток
    virtual void Out(std::ofstream &ofst);

    // Идеальное время прохождения пути для корабля
    virtual double CountTime();
};


#endif
