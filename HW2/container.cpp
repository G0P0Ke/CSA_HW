//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container() {
    this->len = 0;
}

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for(int i = 0; i < len; i++) {
        delete this->cont[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(std::ifstream &ifst) {
    while (!ifst.eof()) {
        if ((this->cont[this->len] = Transport::StaticIn(ifst)) != 0) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(size_t size) {
    while (this->len < size) {
        if ((this->cont[this->len] = Transport::StaticInRnd()) != nullptr) {
            this->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(std::ofstream &ofst) {
    ofst << "Container contains " << this->len << " elements." << "\n";
    for (int i = 0; i < this->len; i++) {
        ofst << i << ": ";
        this->cont[i]->Out(ofst);
    }
}

void Container::heapify(int n, int i) {
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && this->cont[l]->CountTime() < this->cont[largest]->CountTime())
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && this->cont[r]->CountTime() < this->cont[largest]->CountTime())
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        Transport* tmp = this->cont[i];
        this->cont[i] = this->cont[largest];
        this->cont[largest] = tmp;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(n, largest);
    }
}

//------------------------------------------------------------------------------
// Сортировка контейнера по убыванию с помощью "дерева" - HeapSort
void Container::HeapSort() {
    // Построение кучи (перегруппируем массив)
    for (int i = this->len / 2 - 1; i >= 0; --i)
        this->heapify(this->len, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = this->len - 1; i >= 0; --i) {
        // Перемещаем текущий корень в конец
        Transport* tmp = this->cont[i];
        this->cont[i] = this->cont[0];
        this->cont[0] = tmp;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(i, 0);
    }
}

