//------------------------------------------------------------------------------
// ship.cpp - содержит функции обработки самолета
//------------------------------------------------------------------------------

#include "ship.h"
#include <math.h>

//------------------------------------------------------------------------------
// Подсчет рандомного действительного значения
double randomS(double b, double e)
{
    return e + fabs(Random() - b) * 100;
}

//------------------------------------------------------------------------------
// Ввод параметров судна из потока
void In(ship &s, std::ifstream &ifst) {
    int type;
    ifst >> type >> s.displacement >> s.speed >> s.range;
    switch (type) {
        case 1:
            s.ship_type = ship::ship_type::LINER;
            break;
        case 2:
            s.ship_type = ship::ship_type::TUGBOAT;
            break;
        case 3:
            s.ship_type = ship::ship_type::TANKER;
            break;
        default:
            s.ship_type = ship::ship_type::INVALID_TYPE_NUMBER;
    }
}

// Случайный ввод параметров судна
void InRnd(ship &s) {
    s.range = randomS(1.54, 100);
    s.speed = Random();
    s.displacement = Random();
    switch (Random() % 3) {
        case 0:
            s.ship_type = ship::ship_type::LINER;
            break;
        case 1:
            s.ship_type = ship::ship_type::TUGBOAT;
            break;
        case 2:
            s.ship_type = ship::ship_type::TANKER;
            break;
        default:
            s.ship_type = ship::ship_type::INVALID_TYPE_NUMBER;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров судна в поток
void Out(ship &s, std::ofstream &ofst) {
    ofst << "Ship: ship type = ";
    switch (s.ship_type) {
        case ship::LINER:
            ofst << "liner";
            break;
        case ship::TUGBOAT:
            ofst << "tugboat";
            break;
        case ship::TANKER:
            ofst << "tanker";
            break;
        case ship::INVALID_TYPE_NUMBER:
            ofst << "Invalid type number!";
    }
    ofst << " Ship specifications: displacement = "
         << s.displacement
         << ", Speed = " << s.speed
         << ", Range = " << s.range
         << ". Ideal time of passage = " << CountTime(s) << "\n";
}


//------------------------------------------------------------------------------
// Идеальное время прохождения пути для судна

double CountTime(ship &s) {
    double time = s.range / (double)s.speed;
    return time;
}
