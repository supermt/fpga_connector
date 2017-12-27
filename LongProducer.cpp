//
// Created by superMT on 2017/12/28.
//

#include "LongProducer.h"

long LongProducer::addToBuffer(long value) {

    if (offset + 8 >= this->size) {
        return -1; // the size is too big
    }
    byte temp[8];
    if (BYTE_ORDER == LITTLE_ENDIAN) {

    } else {

    }

    for (int i = 0; i < 8; i++) {
        this->array[offset] = temp[i];
        offset++;
    }
    return offset;

}

long LongProducer::toOutPut(byte *output) {
    return offset;
}