#ifndef __ship__
#define __ship__

//------------------------------------------------------------------------------
// ship.h - содержит описание корабля
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "rnd.h"

// Подсчет рандомного действительного значения
double randomS(double b, double e);

//------------------------------------------------------------------------------
// корабль
struct ship {
    enum ship_type { // виды судна
        LINER, TUGBOAT, TANKER, INVALID_TYPE_NUMBER
    };
    ship_type ship_type; // вид судна
    int displacement; // водоизмещение
    int speed; // скорость
    double range; // расстояние между пунктами отправления и назначения
};

// Ввод параметров корабля из файла
void In(ship &s, std::ifstream &ifst);

// Случайный ввод параметров корабля
void InRnd(ship &s);

// Вывод параметров корабля в форматируемый поток
void Out(ship &s, std::ofstream &ofst);

// Идеальное время прохождения пути для корабля
double CountTime(ship &s);

#endif
