//------------------------------------------------------------------------------
// ship.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------

#include <iostream>
#include "ship.h"
#include <cmath>

//------------------------------------------------------------------------------
// Подсчет рандомного действительного значения
double randomS(double b, double e)
{
    return e + fabs(Random() - b) * 100;
}

//------------------------------------------------------------------------------
// Ввод параметров судна из потока
void Ship::In(std::ifstream &ifst) {
    int type;
    ifst >> type >> this->displacement >> this->speed >> this->range;
    switch (type) {
        case 1:
            this->ship_type = LINER;
            break;
        case 2:
            this->ship_type = TUGBOAT;
            break;
        case 3:
            this->ship_type = TANKER;
            break;
        default:
            std::cerr << "Invalid transport type number" << std::endl;
    }
}

// Случайный ввод параметров судна
void Ship::InRnd() {
    this->range = randomS(1.54, 100);
    this->speed = Random();
    this->displacement = Random();
    switch (Random() % 3) {
        case 0:
            this->ship_type = LINER;
            break;
        case 1:
            this->ship_type = TUGBOAT;
            break;
        case 2:
            this->ship_type = TANKER;
            break;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров судна в поток
void Ship::Out(std::ofstream &ofst) {
    ofst << "Ship: ship type = ";
    switch (this->ship_type) {
        case LINER:
            ofst << "liner";
            break;
        case TUGBOAT:
            ofst << "tugboat";
            break;
        case TANKER:
            ofst << "tanker";
            break;
    }
    ofst << " Ship specifications: displacement = "
         << this->displacement
         << ", Speed = " << this->speed
         << ", Range = " << this->range
         << ". Ideal time of passage = " << this->CountTime() << "\n";
}


//------------------------------------------------------------------------------
// Идеальное время прохождения пути для судна

double Ship::CountTime() {
    double time = this->range / (double)this->speed;
    return time;
}
