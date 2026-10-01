/**
 * @file    consumer.cpp
 * @brief   Implements the callable consumer thread task
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#include "consumer.h"

/**
 * @brief Binds the consumer to a buffer and assigns its identifier
 * @param buf Shared buffer from which to consume
 * @param _id Identifier for this consumer
 */
Consumer::Consumer(SharedBuffer& buf, string _id) : buffer(buf), id(_id) {}

/** @brief Removes one item from the buffer */
void Consumer::operator()() {
    buffer.remove(id);
}