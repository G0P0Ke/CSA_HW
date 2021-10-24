# HW1
Домашняя работа - Архитектура вычислительных систем
# 1-ый способ проверки тестов

## Запустит все тесты сразу
> HW1\$ cd tests <br>
> tests\$ ./script

# 2-ой способ проверки тестов
## Для проверки времени работы тестов:
> HW1\$ cd cmake-build-debug <br>
> cmake-build-debug\$  time ./HW1 -f ../tests/input/test{X}_input.txt ../tests/output/test{X}_output1.txt ../tests/output/test{X}_output2.txt <br>
>> X - номер теста

## Для запуска рандомных тестов:
> HW1\$ cd cmake-build-debug <br>
> cmake-build-debug\$  ./HW1 -n {number} ../tests/output/test6_output1.txt ../tests/output/test6_output2.txt <br>
>> number - количество тестов

## Для запуска готовых тестов:
> HW1\$ cd cmake-build-debug <br>
> cmake-build-debug\$  ./HW1 -f ../tests/input/test{X}_input.txt  ../tests/output/test{X}_output1.txt ../tests/output/test{X}_output2.txt <br>
>> X - номер теста 
