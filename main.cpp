#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "buffer.h"
#include "consumer.h"
#include "producer.h"

#define NUM_THREADS 5
#define BUF_CAPACITY 3

int main() {
    srand(time(NULL));

    SharedBuffer buffer(BUF_CAPACITY);

    std::vector<std::thread> producers;
    for (int i = 0; i < NUM_THREADS; i++) {
        std::string id = "Producer " + std::to_string(i+1);
        producers.push_back(std::thread(Producer(buffer, id)));
    }

    std::vector<std::thread> consumers;
    for (int i = 0; i < NUM_THREADS; i++) {
        std::string id = "Consumer " + std::to_string(i + 1);
        consumers.push_back(std::thread(Consumer(buffer, id)));
    }

    for (std::thread& p : producers) {
        p.join();
    }

    for (std::thread& c : consumers) {
        c.join();
    }

    std::cout << "No more production or consumption." << std::endl;
    return 0;
}