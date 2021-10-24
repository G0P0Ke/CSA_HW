#ifndef __train__
#define __train__

//------------------------------------------------------------------------------
// train.h - содержит описание поезда
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "rnd.h"
#include "transport.h"

// Подсчет рандомного действительного значения
double randomT(double b, double e);

//------------------------------------------------------------------------------
// поезд
class Train: public Transport{
private:
    // количество вагонов
    int number_wagons;

public:
    // Деструктор поезда
    virtual ~Train() {}

    // Ввод параметров поезда из файла
    virtual void In(std::ifstream &ifst);

    // Случайный ввод параметров поезда
    virtual void InRnd();

    // Вывод параметров поезда в форматируемый поток
    virtual void Out(std::ofstream &ofst);

    // Идеальное время прохождения пути для поезда
    virtual double CountTime();
};

#endif
