#include <iostream>
#include "common.h"
#include "LongProducer.h"
#include "FileReader.h"
#include <unistd.h>


int main() {

    // read the file
    FileReader *source_file = new FileReader("/temp/path/to/testfile", "first:long,second:string");

    int test_column = source_file->getColumnNum("first");

    int buffersize = source_file->getColumnSize(test_column);

    byte buffer[buffersize];

    int fd = 0;// pretend it to be a file description

    write(fd, buffer, buffersize); // transform data to FPGA or target file

    long return_size = 0;
    byte return_header[8];
    //read 8 bytes at first , in order to get the size of returning buffer
    read(fd, return_header, 9);

    return_size = LongProducer::transFromByte(return_header);

    byte result_buffer[return_size];

    read(fd, result_buffer, return_size);

    return 0;

}