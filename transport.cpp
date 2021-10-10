//------------------------------------------------------------------------------
// transport.cpp - содержит процедуры связанные с обработкой обобщенного пассажирского транспорта
// и создания произвольного транспорта
//------------------------------------------------------------------------------

#include "transport.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного транспорта из файла
transport* In(std::ifstream &ifst) {
    transport *tr;
    int k;
    ifst >> k;
    switch(k) {
        case 1:
            tr = new transport;
            tr->k = transport::PLANE;
            In(tr->p, ifst);
            return tr;
        case 2:
            tr = new transport;
            tr->k = transport::SHIP;
            In(tr->s, ifst);
            return tr;
        case 3:
            tr = new transport;
            tr->k = transport::TRAIN;
            In(tr->t, ifst);
            return tr;
        default:
            tr = new transport;
            tr->k = transport::INVALID_TRANSPORT_TYPE;
            return tr;
    }
}

// Случайный ввод обобщенной фигуры
transport *InRnd() {
    transport *tr;
    int k = Random() % 3;
    switch(k) {
        case 0:
            tr = new transport;
            tr->k = transport::PLANE;
            InRnd(tr->p);
            return tr;
        case 1:
            tr = new transport;
            tr->k = transport::TRAIN;
            InRnd(tr->t);
            return tr;
        case 2:
            tr = new transport;
            tr->k = transport::SHIP;
            InRnd(tr->s);
            return tr;
        default:
            tr = new transport;
            tr->k = transport::INVALID_TRANSPORT_TYPE;
            return tr;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(transport &tr, std::ofstream &ofst) {
    switch(tr.k) {
        case transport::PLANE:
            Out(tr.p, ofst);
            break;
        case transport::SHIP:
            Out(tr.s, ofst);
            break;
        case transport::TRAIN:
            Out(tr.t, ofst);
            break;
        default:
            ofst << "Invalid transport type!\n";
    }
}

//------------------------------------------------------------------------------
// Идеальное время прохождения пути для транспорта
double CountTime(transport &tr){
    switch(tr.k) {
        case transport::PLANE:
            return CountTime(tr.p);
        case transport::SHIP:
            return CountTime(tr.s);
        case transport::TRAIN:
            return CountTime(tr.t);
        default:
            return 0.0;
    }
};

