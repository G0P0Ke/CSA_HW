#ifndef __plane__
#define __plane__

//------------------------------------------------------------------------------
// plane.h - содержит описание самолета
//------------------------------------------------------------------------------

#include <fstream>
#include <cstring>
#include "rnd.h"
#include "transport.h"

// Подсчет рандомного действительного значения
double randomP(double b, double e);

//------------------------------------------------------------------------------
// самолет
class Plane: public Transport{
private:
    // дальность полета
    int distance_fly;

    // грузоподъемность
    int carrying_capacity;

public:
    // Деструктор самолета
    virtual ~Plane() {}

    // Ввод параметров самолета из файла
    virtual void In(std::ifstream &ifst);

    // Случайный ввод параметров cамолета
    virtual void InRnd();

    // Вывод параметров самолета в форматируемый поток
    virtual void Out(std::ofstream &ofst);

    // Идеальное время прохождения пути для самолета
    virtual double CountTime();
};


#endif
