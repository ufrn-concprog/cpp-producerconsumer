#include "consumer.h"

Consumer::Consumer(SharedBuffer& buf, std::string _id) : buffer(buf), id(_id) {}

void Consumer::operator()() {
    buffer.remove(id);
}