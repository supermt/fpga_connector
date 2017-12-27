//
// Created by superMT on 2017/12/28.
//

#ifndef CONNECTOR_LONGPRODUCER_H
#define CONNECTOR_LONGPRODUCER_H

#include "common.h"

class LongProducer {

public:

    static long transFromByte(byte * array);

    LongProducer(long init_size) {
        array = static_cast<byte *>(calloc(init_size, sizeof(byte)));
        this->size = init_size;
        memset(array, 0, init_size * sizeof(byte));
        offset = 0;
    }

    ~LongProducer() {
        free(array);
    }

    long addToBuffer(long value);

    long toOutPut(byte *output); // returning buffer size

private:
    byte *array;
    long offset;
    long size;

};


#endif //CONNECTOR_LONGPRODUCER_H
