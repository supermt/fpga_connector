//
// Created by superMT on 2017/12/28.
//

#ifndef CONNECTOR_FILEREADER_H
#define CONNECTOR_FILEREADER_H

#include <vector>
#include <map>
#include "common.h"

class FileReader {

public:
    FileReader(std::string filename, std::string table_description) {

    }

    int getColumnCount() {
        return this->column_counter;
    }

    int getColumnNum(std::string column_name);

    std::vector<long> getNumbericColumn(int column_num);

    std::vector<std::string> getStringColumn(int column_num);

    long getColumnData(int column_num, byte *output_array, long output_size);

    long getColumnSize(int column_num); // return the size of target column count in byte unit

    int getRowData(long row_num, byte *output_array, long output_size);

private:
    int column_counter;
    std::vector<byte[]> rows;
    std::vector<std::vector<long >> numberic_column;
    std::vector<std::vector<std::string >> string_column;
    std::map<int, int> index; // the key is the index of the column_num, the result of getClumnNum , the value is the
    // index in numberic_column vector or the index in numberic_column
    // use postive or negative signal to determine which vector it's in;

};


#endif //CONNECTOR_FILEREADER_H
