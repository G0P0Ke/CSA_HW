//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    for (int i = 0; i < c.len; i++) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    while (!ifst.eof()) {
        if ((c.cont[c.len] = In(ifst)) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while (c.len < size) {
        if ((c.cont[c.len] = InRnd()) != nullptr) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << "\n";
    for (int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(*(c.cont[i]), ofst);
    }
}

void heapify(container &c, int n, int i) {
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && CountTime(*c.cont[l]) < CountTime(*c.cont[largest]))
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && CountTime(*c.cont[r]) < CountTime(*c.cont[largest]))
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        transport* tmp = c.cont[i];
        c.cont[i] = c.cont[largest];
        c.cont[largest] = tmp;

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(c, n, largest);
    }
}

//------------------------------------------------------------------------------
// Сортировка контейнера по убыванию с помощью "дерева" - HeapSort
void HeapSort(container &c) {
    // Построение кучи (перегруппируем массив)
    for (int i = c.len / 2 - 1; i >= 0; --i)
        heapify(c, c.len, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = c.len - 1; i >= 0; --i) {
        // Перемещаем текущий корень в конец
        transport* tmp = c.cont[i];
        c.cont[i] = c.cont[0];
        c.cont[0] = tmp;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(c, i, 0);
    }
}
