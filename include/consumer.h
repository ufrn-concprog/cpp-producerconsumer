#ifndef CONSUMER_H
#define CONSUMER_H

#include <string>

#include "buffer.h"

class Consumer {
   private:
    SharedBuffer& buffer;
    std::string id;

   public:
    Consumer(SharedBuffer& buf, std::string _id);
    void operator()();
};

#endif