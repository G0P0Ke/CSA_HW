import newRandom
from enum import Enum


# ----------------------------------------------

class ShipType(Enum):
    UNKNOWN_TYPE = 0
    LINER = 1
    TUGBOAT = 2
    TANKER = 3


# Класс корабля
class Ship:
    # Конструктор корабля
    def __init__(self):
        self.range = 0
        self.speed = 0
        self.displacement = 0
        self.ship_type = ShipType.UNKNOWN_TYPE.name

    # Считывание параметров поезда из строки
    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        type = int(strArray[i])
        if 1 <= type <= 3:
            self.ship_type = ShipType(type).name
        else:
            self.ship_type = ShipType.UNKNOWN_TYPE.name
        self.displacement = int(strArray[i + 1])
        self.speed = int(strArray[i + 2])
        self.range = int(strArray[i + 3])
        i += 4
        return i

    # Случайная генерация параметров корабля
    def RandomIn(self):
        self.range = newRandom.randDouble(10, 10000)
        self.speed = newRandom.randInt(100, 10000)
        self.displacement = newRandom.randInt(1, 1000)
        self.ship_type = ShipType(newRandom.randInt(1, 3)).name

    # Вывод данных корабля в файл
    def Write(self, ostream):
        ostream.write("Ship: type = {}, displacement = {} ,speed = {}, range = {}, Ideal time of travel = {}"
                      .format(self.ship_type, self.displacement, self.speed, self.range, self.CountTime()))
        pass

    #  Идеальное время прохождения пути для корабля
    def CountTime(self):
        return self.range / self.speed
