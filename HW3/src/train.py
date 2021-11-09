import newRandom


# ----------------------------------------------
# Класс поезда
class Train:
    # Конструктор поезда
    def __init__(self):
        self.range = 0
        self.speed = 0
        self.number_wagons = 0

    # Считывание параметров поезда из строки
    def ReadStrArray(self, strArray, i):
        if i >= len(strArray) - 1:
            return 0
        self.number_wagons = int(strArray[i])
        self.speed = int(strArray[i + 1])
        self.range = int(strArray[i + 2])
        i += 3
        return i

    # Случайная генерация параметров поезда
    def RandomIn(self):
        self.range = newRandom.randDouble(10, 10000)
        self.speed = newRandom.randInt(100, 10000)
        self.number_wagons = newRandom.randInt(1, 50)

    # Вывод данных поезда в файл
    def Write(self, ostream):
        ostream.write("Train: number of wagons = {}, speed = {}, range = {}, Ideal time of travel = {}"
                      .format(self.number_wagons, self.speed, self.range, self.CountTime()))
        pass

    #  Идеальное время прохождения пути для поезда
    def CountTime(self):
        return self.range / self.speed
