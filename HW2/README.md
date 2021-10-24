# HW2
Домашняя работа - Архитектура вычислительных систем
# 1-ый способ проверки тестов

## Запустит все тесты сразу
> HW2\$ cd tests <br>
> tests\$ ./script

# 2-ой способ проверки тестов - ручной
## Для проверки времени работы тестов:
> HW2\$ cd cmake-build-debug <br>
> cmake-build-debug\$  time ./HW2 -f ../tests/input/test{X}_input.txt ../tests/output/test{X}_output1.txt ../tests/output/test{X}_output2.txt <br>
>> X - номер теста

## Для запуска рандомных тестов:
> HW2\$ cd cmake-build-debug <br>
> cmake-build-debug\$  ./HW2 -n {number} ../tests/output/test6_output1.txt ../tests/output/test6_output2.txt <br>
>> number - количество тестов

## Для запуска готовых тестов:
> HW2\$ cd cmake-build-debug <br>
> cmake-build-debug\$  ./HW2 -f ../tests/input/test{X}_input.txt  ../tests/output/test{X}_output1.txt ../tests/output/test{X}_output2.txt <br>
>> X - номер теста 


## Сравнительный анализ с предыдущей домашней работой

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

### Итог
На основе представленного времени прогонов тестов первого и второго домашних заданий мы можем сделать вывод, 
что процедурный подход программирования работает быстрее, чем объектно-ориентированный. <br>
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
```

Такой вывод о работе одного подхода делается и потому, что число модулей реализации осталось неизменным