from plane import *
import plane
from train import *
import train
from ship import *
import ship

import newRandom


# ----------------------------------------------
# Класс контейнер для транспорта
class Container:
    def __init__(self):
        self.store = []

    def ReadStrArray(self, strArray):
        arrayLen = len(strArray)
        i = 0  # Индекс, задающий текущую строку в массиве
        transport_count = 0
        while i < arrayLen:
            str = strArray[i]
            key = int(str)
            if key == 1:  # признак самолета
                i += 1
                transport = Plane()
                i = transport.ReadStrArray(strArray, i)  # чтение самолтеа с возвратом позиции за ним
            elif key == 2:  # признак корабля
                i += 1
                transport = Ship()
                i = transport.ReadStrArray(strArray, i)  # чтение корабля с возвратом позиции за ним
            elif key == 3:  # признак поезда
                i += 1
                transport = Train()
                i = transport.ReadStrArray(strArray, i)  # чтение поезда с возвратом позиции за ним
            else:
                return transport_count
            # Количество пробелами фигур увеличивается на 1
            if i == 0:
                return transport_count
            transport_count += 1
            self.store.append(transport)
        return transport_count

    def RandomIn(self, numOfElems):
        for i in range(numOfElems):
            key = newRandom.randInt(1, 3)
            if key == 1:  # признак самолета
                transport = plane.Plane()
            elif key == 2:  # признак корабля
                transport = train.Train()
            elif key == 3:  # признак поезда
                transport = ship.Ship()
            transport.RandomIn()
            self.store.append(transport)

    # Вывод всех элементов контейнера в файл
    def Write(self, ostream):
        ostream.write("Container stores {} transports:\n".format(len(self.store)))
        for i in range(len(self.store)):
            ostream.write("{}: ".format(i))
            self.store[i].Write(ostream)
            ostream.write("\n")
        pass

    def heapify(self, n, i):
        largest = i
        # Инициализируем наибольший элемент как корень
        l = 2 * i + 1  # левый = 2*i + 1
        r = 2 * i + 2  # правый = 2*i + 2

        # Если левый дочерний элемент больше корня
        if l < n and self.store[l].CountTime() < self.store[largest].CountTime():
            largest = l

        # Если правый дочерний элемент больше, чем самый большой элемент на данный момент
        if r < n and self.store[r].CountTime() < self.store[largest].CountTime():
            largest = r

        # Если самый большой элемент не корень
        if largest != i:
            tmp = self.store[i]
            self.store[i] = self.store[largest]
            self.store[largest] = tmp

            # Рекурсивно преобразуем в двоичную кучу затронутое поддерево
            self.heapify(n, largest)

    # Сортировка контейнера по убыванию с помощью "дерева" - HeapSort
    def HeapSort(self):
        # Построение кучи (перегруппируем массив)
        for i in range((len(self.store) // 2) - 1, -1, -1):
            self.heapify(len(self.store), i)

        # Один за другим извлекаем элементы из кучи
        for i in range(len(self.store) - 1, -1, -1):
            # Перемещаем текущий корень в конец
            tmp = self.store[i]
            self.store[i] = self.store[0]
            self.store[0] = tmp

            # вызываем процедуру heapify на уменьшенной куче
            self.heapify(i, 0)
