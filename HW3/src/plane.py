import newRandom


# ----------------------------------------------
# Класс самолета
class Plane:
    # Конструктор самолета
    def __init__(self):
        self.range = 0
        self.speed = 0
        self.distance_fly = 0
        self.carrying_capacity = 0

    # Считывание параметров самолета из строки
    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.distance_fly = int(strArray[i])
        self.carrying_capacity = int(strArray[i + 1])
        self.speed = int(strArray[i + 2])
        self.range = int(strArray[i + 3])
        i += 4
        return i

    # Случайная генерация параметров самолета
    def RandomIn(self):
        self.range = newRandom.randDouble(10, 10000)
        self.speed = newRandom.randInt(100, 10000)
        self.distance_fly = newRandom.randInt(1000, 1e9)
        self.carrying_capacity = newRandom.randInt(10, 10000)

    # Вывод данных самолета в файл
    def Write(self, ostream):
        ostream.write(
            "Plane: distance_fly = {}, carrying_capacity = {}, speed = {}, range = {}, Ideal time of travel = {}"
            .format(self.distance_fly, self.carrying_capacity, self.speed, self.range, self.CountTime()))
        pass

    #  Идеальное время прохождения пути для самотела
    def CountTime(self):
        return self.range / self.speed
