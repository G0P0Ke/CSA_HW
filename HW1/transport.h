#ifndef __transport__
#define __transport__

//------------------------------------------------------------------------------
// transport.h - содержит описание обобщающего пассажирского транспорта
//------------------------------------------------------------------------------


#include "plane.h"
#include "train.h"
#include "ship.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся пассажирские транспорты
struct transport {
    // значения ключей для каждого растения
    enum key {PLANE, TRAIN, SHIP, INVALID_TRANSPORT_TYPE};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        plane p;
        train t;
        ship s;
    };
};

// Ввод обобщенного пассажирского транспорта из файла
transport *In(std::ifstream &ifst);

// Случайный ввод обобщенного пассажирского транспорта
transport *InRnd();

// Вывод обобщенного пассажирского транспорта в форматируемый поток
void Out(transport &tr, std::ofstream &ofst);

// Идеальное время прохождения пути для транспорта
double CountTime(transport &tr);

#endif