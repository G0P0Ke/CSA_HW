//------------------------------------------------------------------------------
// train.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------

#include "train.h"
#include <cmath>

//------------------------------------------------------------------------------
// Подсчет рандомного действительного значения
double randomT(double b, double e)
{
    return e + fabs(Random() - b) * 100;
}

//------------------------------------------------------------------------------
// Ввод параметров поезда из потока
void Train::In(std::ifstream &ifst) {
    ifst >> this->number_wagons >> this->speed >> this->range;
}

// Случайный ввод параметров поезда
void Train::InRnd() {
    this->range = randomT(1.54, 100);
    this->speed = Random();
    this->number_wagons = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров поезда в поток
void Train::Out(std::ofstream &ofst) {
    ofst << "Train specifications: number of wagons = "
         << this->number_wagons
         << ", Speed = " << this->speed
         << ", Range = " << this->range
         << ". Ideal time of passage = " << this->CountTime() << "\n";
}


//------------------------------------------------------------------------------
// Идеальное время прохождения пути для поезда

double Train::CountTime() {
    double time = this->range / (double)this->speed;
    return time;
}
