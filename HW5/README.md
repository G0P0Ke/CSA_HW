# CSA_HW
Домашняя работа - Архитектура вычислительных систем <br>
### Исполнитель:
Андреев Антон Александрович - БПИ206
Вариант 2

### Задача 
Задача о Винни-Пухе - 1 или правильные пчелы. В одном лесу живут n
пчел и один медведь, которые используют один горшок меда, вместимостью
Н глотков. Сначала горшок пустой. Пока горшок не наполнится, медведь
спит. Как только горшок заполняется, медведь просыпается и съедает весь
мед, после чего снова засыпает. Каждая пчела многократно собирает по
одному глотку меда и кладет его в горшок. Пчела, которая приносит
последнюю порцию меда, будит медведя. Создать многопоточное
приложение, моделирующее поведение пчел и медведя.

### Решение

Для реализации моего многопоточного приложения была выбрана парадигма Управляющий и рабочие.
> Управляющий и рабочие - модель организации вычислений, при
которой существует поток, координирующий работу всех остальных
потоков. Как правило, управляющий поток распределяет данные, собирает и
анализирует результаты

Данную модель также называют моделью делегирования. (https://intuit.ru/studies/courses/5938/1074/lecture/16465)
В моем случае главный поток в лице main запускает все дочерние потоки в лице пчел, а после ждет их завершения, и в итоге мы получаем конечный результат, 
что и заключает в себе парадигма "Управляющий и рабочие". 
Было принято реализовать функционал
Медведя в самом потоке пчелы, так как он не выполняет функций требующих параллельной реализации. 



### Способ запуска

Из-за способа решения Вам необходимо ввести 3 переменные в строку

{Число пчел \ Объем горшка \ Кол-во пробуждений медведЯ}

### Информация

####class Bee:
   * Имя - генерируется "рандомно"
   * Общее количество пополнений - увеличивается в процессе
   * Общее кол-во раз, когда пчела будит медведя - увеличивается в процессе

#### constant 
   * number_names - количество имен для рандома

#### global variables
* number_sip - объем горшка
* number_winters - количетсво пробуждений медведя
* current_number_sip - текущая наполненность горшка