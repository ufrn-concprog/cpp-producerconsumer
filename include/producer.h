/**
 * @file    producer.h
 * @brief   Declares the callable producer thread task
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>
using std::string;

#include "buffer.h"

/** 
 * @class Producer
 * @brief Produces one random integer and inserts it into a shared buffer
 */
class Producer {
private:
    /** @brief Buffer receiving this producer's item. */
    SharedBuffer& buffer;

    /** @brief Identifier used in buffer activity messages. */
    string id;

public:
    /** 
     * @brief Binds the producer to a buffer and assigns its identifier.
     * @param buf Shared buffer that will receive the produced item.
     * @param _id Identifier for this producer.
     */
    Producer(SharedBuffer& buf, string _id);

    /** 
     * @brief Produces and inserts one item (an integer between 1 and 100) 
     *        into the shared buffer 
     */
    void operator()();
};

#endif