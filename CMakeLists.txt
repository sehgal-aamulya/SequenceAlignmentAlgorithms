cmake_minimum_required(VERSION 3.20)
project(CSCI570FinalProject)

set(CMAKE_CXX_STANDARD 20)

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.76.0/include)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.76.0/lib)
find_package(Boost 1.76.0)
include_directories(${Boost_INCLUDE_DIR})

if (NOT Boost_FOUND)
	message(FATAL_ERROR "Could not find boost!")
endif ()

add_executable(CSCI570FinalProject main.cpp SequenceAlignment.cpp SequenceAlignment.h NucleotideBases.cpp NucleotideBases.h EfficientSequenceAlignment.cpp EfficientSequenceAlignment.h)
