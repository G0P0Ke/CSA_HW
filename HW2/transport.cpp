//------------------------------------------------------------------------------
// transport.cpp - содержит процедуры связанные с обработкой обобщенного пассажирского транспорта
// и создания произвольного транспорта
//------------------------------------------------------------------------------

#include <iostream>

#include "plane.h"
#include "train.h"
#include "ship.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного транспорта из файла
Transport* Transport::StaticIn(std::ifstream &ifst) {
    Transport* tr = nullptr;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            tr = new Plane;
            break;
        case 2:
            tr = new Ship;
            break;
        case 3:
            tr = new Train;
            break;
        default:
            std::cerr << "Invalid transport type number" << std::endl;
            return nullptr;
    }
    tr->In(ifst);
    return tr;
}

// Случайный ввод обобщенного транспорта
Transport* Transport::StaticInRnd() {
    Transport *tr = nullptr;
    int k = Random() % 3;
    switch(k) {
        case 0:
            tr = new Plane;
            break;
        case 1:
            tr = new Train;
            break;
        case 2:
            tr = new Ship;
            break;
        default:
            std::cerr << "Invalid transport type number" << std::endl;
            return nullptr;
    }
    tr->InRnd();
    return tr;
}


