//------------------------------------------------------------------------------
// plane.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------

#include "plane.h"
#include <cmath>

//------------------------------------------------------------------------------
// Подсчет рандомного действительного значения
double randomP(double b, double e)
{
    return e + fabs(Random() - b) * 100;
}

//------------------------------------------------------------------------------
// Ввод параметров самолета из потока
void Plane::In(std::ifstream &ifst) {
    ifst >> this->distance_fly >> this->carrying_capacity >> this->speed >> this->range;
}

// Случайный ввод параметров самолета
void Plane::InRnd() {
    this->range = randomP(1.54, 100);
    this->speed = Random();
    this->carrying_capacity = Random();
    this->distance_fly = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров самолета в поток
void Plane::Out(std::ofstream &ofst) {
    ofst << "Plane specifications: distance fly = "
         << this->distance_fly << ", carrying capacity = " << this->carrying_capacity
         << ", Speed = " << this->speed
         << ", Range = " << this->range
         << ". Ideal time of passage = " << this->CountTime() << "\n";
}


//------------------------------------------------------------------------------
// Идеальное время прохождения пути для самолета

double Plane::CountTime() {
    double time = this->range / (double)this->speed;
    return time;
}
