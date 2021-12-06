cmake_minimum_required(VERSION 3.20)
project(CSCI570FinalProject)

set(CMAKE_CXX_STANDARD 20)

#set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.76.0/include)
#set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.76.0/lib)
#find_package(Boost 1.76.0)
#include_directories(${Boost_INCLUDE_DIR})
#
#if (NOT Boost_FOUND)
#	message(FATAL_ERROR "Could not find boost!")
#endif ()

add_executable(CSCI570FinalProject main.cpp SequenceAlignment.cpp SequenceAlignment.hpp NucleotideBases.cpp NucleotideBases.hpp EfficientSequenceAlignment.cpp EfficientSequenceAlignment.hpp StringGenerator.cpp StringGenerator.hpp StringTrim.cpp StringTrim.hpp)
add_executable(Basic 7952603892_basic.cpp SequenceAlignment.cpp SequenceAlignment.hpp NucleotideBases.cpp NucleotideBases.hpp StringGenerator.cpp StringGenerator.hpp StringTrim.cpp StringTrim.hpp)
add_executable(Efficient 7952603892_efficient.cpp SequenceAlignment.cpp SequenceAlignment.hpp NucleotideBases.cpp NucleotideBases.hpp EfficientSequenceAlignment.cpp EfficientSequenceAlignment.hpp StringGenerator.cpp StringGenerator.hpp StringTrim.cpp StringTrim.hpp)
add_executable(BasicCSV BasicCSV.cpp NucleotideBases.cpp NucleotideBases.hpp SequenceAlignment.cpp SequenceAlignment.hpp)
add_executable(EfficientCSV EfficientCSV.cpp NucleotideBases.cpp NucleotideBases.hpp SequenceAlignment.cpp SequenceAlignment.hpp EfficientSequenceAlignment.cpp EfficientSequenceAlignment.hpp)
add_executable(PlotData PlotDataGenerator.cpp SequenceAlignment.cpp SequenceAlignment.hpp NucleotideBases.cpp NucleotideBases.hpp EfficientSequenceAlignment.cpp EfficientSequenceAlignment.hpp)
