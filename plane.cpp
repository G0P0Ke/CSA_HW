//------------------------------------------------------------------------------
// plane.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------

#include "plane.h"
#include <math.h>

//------------------------------------------------------------------------------
// Подсчет рандомного действительного значения
double randomP(double b, double e)
{
    return e + fabs(Random() - b) * 100;
}

//------------------------------------------------------------------------------
// Ввод параметров самолета из потока
void In(plane &p, std::ifstream &ifst) {
    ifst >> p.distance_fly >> p.carrying_capacity >> p.speed >> p.range;
}

// Случайный ввод параметров самолета
void InRnd(plane &p) {
    p.range = randomP(1.54, 100);
    p.speed = Random();
    p.carrying_capacity = Random();
    p.distance_fly = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров самолета в поток
void Out(plane &p, std::ofstream &ofst) {
    ofst << "Plane specifications: distance fly = "
         << p.distance_fly << ", carrying capacity = " << p.carrying_capacity
         << ", Speed = " << p.speed
         << ", Range = " << p.range
         << ". Ideal time of passage = " << CountTime(p) << "\n";
}


//------------------------------------------------------------------------------
// Идеальное время прохождения пути для самолета

double CountTime(plane &p) {
    double time = p.range / (double)p.speed;
    return time;
}
