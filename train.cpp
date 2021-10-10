//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------

#include "train.h"
#include <math.h>

//------------------------------------------------------------------------------
// Подсчет рандомного действительного значения
double randomT(double b, double e)
{
    return e + fabs(Random() - b) * 100;
}

//------------------------------------------------------------------------------
// Ввод параметров поезда из потока
void In(train &t, std::ifstream &ifst) {
    ifst >> t.number_wagons >> t.speed >> t.range;
}

// Случайный ввод параметров поезда
void InRnd(train &t) {
    t.range = randomT(1.54, 100);
    t.speed = Random();
    t.number_wagons = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров поезда в поток
void Out(train &t, std::ofstream &ofst) {
    ofst << "Train specifications: number of wagons = "
         << t.number_wagons
         << ", Speed = " << t.speed
         << ", Range = " << t.range
         << ". Ideal time of passage = " << CountTime(t) << "\n";
}


//------------------------------------------------------------------------------
// Идеальное время прохождения пути для поезда

double CountTime(train &t) {
    double time = t.range / (double)t.speed;
    return time;
}
