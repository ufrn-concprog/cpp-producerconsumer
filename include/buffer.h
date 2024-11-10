#ifndef BUFFER_H
#define BUFFER_H

#include <condition_variable>
#include <mutex>
#include <queue>

class SharedBuffer {
private:
    const int capacity;
    std::queue<int> buffer;
    std::mutex mutex;
    std::condition_variable not_full;
    std::condition_variable not_empty;

public:
    SharedBuffer(int cap);
    void insert(const int item, const std::string consumer_id);
    void remove(const std::string consumer_id);
};

#endif