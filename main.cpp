/**
 * @file    main.cpp
 * @brief   Implementation of a solution to the Producer-Consumer problem 
 *          using C++ threads, mutexes, and condition variables
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#include <cstdlib>
using std::ctime;

#include <ctime>
using std::srand;

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::to_string;

#include <thread>
using std::thread;

#include <vector>
using std::vector;

#include "buffer.h"
#include "consumer.h"
#include "producer.h"

/** @brief Number of producer and consumer threads created by the program */
#define NUM_THREADS 5

/** @brief Maximum number of items held in the shared buffer at once */
#define BUF_CAPACITY 3

/**
 * @brief Main function
 * @return Exit status code
 */
int main() {
    srand(time(NULL));

    SharedBuffer buffer(BUF_CAPACITY);

    vector<thread> producers;
    for (int i = 0; i < NUM_THREADS; i++) {
        string id = "Producer " + to_string(i+1);
        producers.push_back(thread(Producer(buffer, id)));
    }

    vector<thread> consumers;
    for (int i = 0; i < NUM_THREADS; i++) {
        string id = "Consumer " + to_string(i + 1);
        consumers.push_back(thread(Consumer(buffer, id)));
    }

    for (thread& p : producers) {
        p.join();
    }

    for (thread& c : consumers) {
        c.join();
    }

    std::cout << "No more production or consumption." << std::endl;
    return 0;
}