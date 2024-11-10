#include <iostream>
#include <thread>

#include "buffer.h"

SharedBuffer::SharedBuffer(int cap) : capacity(cap) {}

void SharedBuffer::insert(const int item, const std::string producer_id) {
    std::unique_lock<std::mutex> lock(mutex);
    while ((int)buffer.size() == capacity) {
        std::cout << "Buffer is full. " << producer_id << " suspended." << std::endl;
        not_full.wait(lock);
    }

    buffer.push(item);
    std::cout << producer_id << " inserted " << item << std::endl;

    not_empty.notify_one();
}

void SharedBuffer::remove(const std::string consumer_id) {
    std::unique_lock<std::mutex> lock(mutex);
    while (buffer.empty()) {
        std::cout << "Buffer is full. " << consumer_id << " suspended." << std::endl;
        not_empty.wait(lock);
    }

    int item = buffer.front();
    buffer.pop();
    std::cout << consumer_id << " removed " << item << std::endl;

    not_full.notify_one();
}