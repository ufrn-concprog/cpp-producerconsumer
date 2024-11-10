#ifndef PRODUCER_H
#define PRODUCER_H

#include <string>

#include "buffer.h"

class Producer {
private:
    SharedBuffer& buffer;
    std::string id;

public:
    Producer(SharedBuffer& buf, std::string _id);
    void operator()();
};

#endif