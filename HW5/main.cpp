#include <iostream>
#include <pthread.h>
#include <string>
#include <unistd.h>
#include <vector>
#include "Bee.h"

pthread_mutex_t mutex;
int number_sip, number_winters, current_number_sip = 0;
const int number_names = 10;
std::string dictionary[number_names] = {"Anton", "Leha", "Platon",
                                        "Ivan", "Makar", "Kostya", "Vitalya", "Svyatoslav", "Roma", "Sanya"};

void *add_honey(void *args) {
    Bee *bee = static_cast<Bee *>(args);

    while (number_winters != 0) {
        pthread_mutex_lock(&mutex);
        if (number_winters == 0) {
            pthread_mutex_unlock(&mutex);
            return nullptr;
        }
        ++current_number_sip;
        ++bee->number_honey_sip;
        std::cout << bee->name << " bee filled the pot! Bee's Sip: " <<
                  bee->number_honey_sip << "\n";
        if (current_number_sip == number_sip) {
            current_number_sip = 0;
            --number_winters;
            ++bee->number_wake_bear;
            std::cout << bee->name << " bee wake the BEAR" <<
                      bee->number_wake_bear << "\n";
        }
        pthread_mutex_unlock(&mutex);
        usleep(100);
    }
    return nullptr;
}

std::string random_name() {
    int random_variable = std::rand() % 10;
    return dictionary[random_variable];
}

void results(std::vector<Bee> &bees) {
    std::cout << "Результаты пробуждения медведя относительно пчел" << "\n";
    for (int i = 0; i < bees.size(); ++i) {
        std::cout << "Number of bee's BEAR awakening: " << bees[i].number_wake_bear << "\n";
    }
}

int main(int argc, char *argv[]) {
    int number_bee;

    std::cin >> number_bee >> number_sip >> number_winters;

    pthread_mutex_init(&mutex, nullptr);

    auto *threads = new pthread_t[number_bee];
    std::vector<Bee> bees(number_bee);

    for (int i = 0; i < number_bee; ++i) {
        bees[i].name = random_name() + std::to_string(i);
    }

    std::cout << "Начало медвежьего сезона\n";

    for (int i = 0; i < number_bee; ++i) {
        pthread_create(&threads[i], nullptr, add_honey, &bees[i]);
    }

    for (int i = 0; i < number_bee; ++i) {
        pthread_join(threads[i], nullptr);
    }

    std::cout << "Конец медвежьего сезона\n";
    results(bees);
    pthread_mutex_destroy(&mutex);
    return 0;
}
