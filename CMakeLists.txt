cmake_minimum_required(VERSION 3.8)
project(connector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LongProducer.cpp LongProducer.h FileReader.cpp FileReader.h common.h)
add_executable(connector ${SOURCE_FILES})