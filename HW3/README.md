# HW3
Домашняя работа - Архитектура вычислительных систем
# 1-ый способ проверки тестов

## Запустит все тесты сразу
> HW3\$ cd tests <br>
> tests\$ ./script

# 2-ой способ проверки тестов - ручной
## Для проверки времени работы тестов:
> HW2\$ cd tests <br>
> tests\$  time python3 ../src/main.py -f ../tests/input/test{X}_input.txt ../tests/output/test{X}_output1.txt ../tests/output/test{X}_output2.txt <br>
>> X - номер теста

## Для запуска рандомных тестов:
> HW2\$ cd tests <br>
> tests\$  python3 ../src/main.py -n {number} ../tests/output/test6_output1.txt ../tests/output/test6_output2.txt <br>
>> number - количество тестов

## Для запуска готовых тестов:
> HW2\$ cd tests <br>
> tests\$  python3 ../src/main.py -f ../tests/input/test{X}_input.txt ../tests/output/test{X}_output1.txt ../tests/output/test{X}_output2.txt <br>
>> X - номер теста


## Сравнительный анализ с предыдущими домашними работами на оснлове времени прогонов тестов

Время работы тестов ДЗ1
``` 
RUN: test_1
Start
Stop
0.005
RUN: test_2
Start
Stop
0.006
RUN: test_3
Start
Stop
0.007
RUN: test_4
Start
Stop
0.004
RUN: test_5
Start
Stop
0.005
RUN Random test n = 10
Start
Stop
0.005
RUN Random test n = 100
Start
Stop
0.004
RUN Random test n = 1000
Start
Stop
0.015
RUN Random test n = 10000
Start
Stop
0.060
```

Время работы тестов ДЗ2
``` 
RUN: test_1
Start
Stop
0.012
RUN: test_2
Start
Stop
0.014
RUN: test_3
Start
Stop
0.005
RUN: test_4
Start
Invalid transport type number
Invalid transport type number
Invalid transport type number
Stop
0.005
RUN: test_5
Start
Invalid transport type number
Stop
0.013
RUN Random test n = 10
Start
Stop
0.004
RUN Random test n = 100
Start
Stop
0.004
RUN Random test n = 1000
Start
Stop
0.018
RUN Random test n = 10000
Start
Stop
0.059
```

Время работы тестов ДЗ3
``` 
RUN: test_1
==> Start
==> Finish
0.074
RUN: test_2
==> Start
==> Finish
0.052
RUN: test_3
==> Start
==> Finish
0.042
RUN: test_4
==> Start
==> Finish
0.040
RUN: test_5
==> Start
==> Finish
0.048
RUN Random test n = 10
==> Start
==> Finish
0.043
RUN Random test n = 100
==> Start
==> Finish
0.047
RUN Random test n = 1000
==> Start
==> Finish
0.067
RUN Random test n = 10000
==> Start
==> Finish
0.303
RUN Random test n = 100000
==> Start
==> Finish
3.677

```

### Характеристики программы
* Число заголовочных файлов: 0
* Число модулей реализации: 7
* Общий размер исходных файлов: 11,26 Кб

### Итог
Размер исходных файлов уменьшился в несколь раз, по сравнению 
с файлами программ на статически-типизированных языках, однако скорость работы на самых маленьких тестах увеличилась в 6 раз.
На рандомных тестах в 100000 почти в 7 раз, очевидно, что с увеличением входных данных цифры будут меняться в худшую сторону<br>
Пример: <br>

```
ДЗ1
RUN: test_1
Start
Stop
0.005

ДЗ2
RUN: test_1
Start
Stop
0.012

ДЗ3
RUN: test_1
==> Start
==> Finish
0.074

```
