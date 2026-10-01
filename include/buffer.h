/**
 * @file    buffer.h
 * @brief   Declares the bounded buffer shared by producer and consumer
 *          threads
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <condition_variable>
using std::condition_variable;

#include <mutex>
using std::mutex;

#include <string>
using std::string;

#include <queue>
using std::queue;

/** 
 * @class   SharedBuffer
 * @brief   Thread-safe, fixed-capacity FIFO queue for produced integer 
 *          items.
 * @details Producers wait while the buffer is full, and consumers wait 
 *          while it is empty. Condition variables wake the opposite 
 *          side after each operation.
 */
class SharedBuffer {
private:
 /** @brief Maximum number of items the buffer can hold  */
 const int capacity;

 /** @brief Items awaiting consumption, in FIFO order */
 queue<int> buffer;

 /** @brief Protects the queue and its capacity checks. */
 mutex mutex;

 /** @brief Notifies producers when an item is removed. */
 condition_variable not_full;
 
 /** @brief Notifies consumers when an item is inserted. */
 condition_variable not_empty;

public:
    /** 
     * @brief Creates an empty buffer with the specified maximum capacity
     * @param cap Maximum number of queued items
     */
    SharedBuffer(int cap);

    /** 
     * @brief Adds an item, waiting until the buffer has free capacity
     * @param item Integer item to enqueue
     * @param consumer_id Identifier of the thread performing the insertion
     */
    void insert(const int item, const string consumer_id);

    /** 
     * @brief Removes the oldest item, waiting until the buffer is nonempty
     * @param consumer_id Identifier of the consumer performing the removal
     */
    void remove(const string consumer_id);
};

#endif