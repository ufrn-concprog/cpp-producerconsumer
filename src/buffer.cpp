/**
 * @file    buffer.cpp
 * @brief   Implements the bounded buffer shared by producer and consumer 
 *          threads
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#include <iostream>
using std::cout;
using std::endl;

#include <mutex>
using std::unique_lock;

#include <thread>
using std::this_thread::sleep_for;

#include "buffer.h"

/**
 * @brief Creates an empty buffer with the specified maximum capacity
 * @param cap Maximum number of queued items
 */
SharedBuffer::SharedBuffer(int cap) : capacity(cap) {}

/**
 * @brief Adds an item, waiting until the buffer has free capacity
 * @param item Integer item to enqueue
 * @param consumer_id Identifier of the thread performing the insertion
 */
void SharedBuffer::insert(const int item, const string producer_id) {
    unique_lock<std::mutex> lock(mutex);
    while ((int)buffer.size() == capacity) {
        cout << "Buffer is full. " << producer_id << " suspended." << endl;
        not_full.wait(lock);
    }

    buffer.push(item);
    cout << producer_id << " inserted " << item << endl;

    not_empty.notify_one();
}

/**
 * @brief Removes the oldest item, waiting until the buffer is nonempty
 * @param consumer_id Identifier of the consumer performing the removal
 */
void SharedBuffer::remove(const string consumer_id) {
    unique_lock<std::mutex> lock(mutex);
    while (buffer.empty()) {
        cout << "Buffer is empty. " << consumer_id << " suspended." << endl;
        not_empty.wait(lock);
    }

    int item = buffer.front();
    buffer.pop();
    cout << consumer_id << " removed " << item << endl;

    not_full.notify_one();
}