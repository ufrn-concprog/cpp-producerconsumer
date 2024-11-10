#include <cstdlib>

#include "producer.h"

Producer::Producer(SharedBuffer& buf, std::string _id) : buffer(buf), id(_id) {}

void Producer::operator()() {
    int item = std::rand() % 100 + 1;
    buffer.insert(item, id);
}