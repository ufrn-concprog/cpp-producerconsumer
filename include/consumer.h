/**
 * @file    consumer.h
 * @brief   Declares the callable consumer thread task
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>
using std::string;

#include "buffer.h"

/** 
 * @class   Consumer
 * @brief   Removes one item from a shared buffer when invoked
 */
class Consumer {
   private:
    /** @brief Buffer from which this consumer takes an item. */
    SharedBuffer& buffer;

    /** @brief Identifier used in buffer activity messages. */
    string id;

   public:
    /** 
     * @brief Binds the consumer to a buffer and assigns its identifier
     * @param buf Shared buffer from which to consume
     * @param _id Identifier for this consumer
     */
    Consumer(SharedBuffer& buf, string _id);

    /** @brief Removes one item from the buffer */
    void operator()();
};

#endif