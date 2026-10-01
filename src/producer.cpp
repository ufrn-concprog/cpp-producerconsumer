/**
 * @file    producer.cpp
 * @brief   Implements the callable producer thread task
 * @author	Everton Cavalcante (everton.cavalcante@ufrn.br)
 * @date	September 30, 2026
 */

#include <cstdlib>
using std::rand;

#include "producer.h"

/** 
 * @brief Stores the shared buffer reference and producer identifier.
 * @param buf Buffer that receives the produced item.
 * @param _id Identifier for this producer.
 */
Producer::Producer(SharedBuffer& buf, string _id) : buffer(buf), id(_id) {}

/**
 * @brief Produces and inserts one item (an integer between 1 and 100)
 *        into the shared buffer
 */
void Producer::operator()() {
    int item = rand() % 100 + 1;
    buffer.insert(item, id);
}