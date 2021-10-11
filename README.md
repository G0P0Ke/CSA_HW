# HW1
Домашняя работа - Архитектура вычислительных систем

## Для проверки времени работы тестов:
> HW1: cd cmake-build-debug
> cmake-build-debug:  time ./HW1 -f ../tests/input/testX_input.txt ../tests/output/testX_output1.txt ../tests/output/testX_output2.txt 
>> X - номер теста

## Для запуска рандомных тестов:
> HW1: cd cmake-build-debug 
> cmake-build-debug:  ./HW1 -n {number} ../tests/output/test6_output1.txt ../tests/output/test6_output2.txt 
>> number - количество тестов

## Для запуска готовых тестов:
> HW1: cd cmake-build-debug 
> cmake-build-debug:  ./HW1 -f ../tests/input/testX_input.txt  ../tests/output/testX_output1.txt ../tests/output/testX_output2.txt 
>> X - номер теста 
