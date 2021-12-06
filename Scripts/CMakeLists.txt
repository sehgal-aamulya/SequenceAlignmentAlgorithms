cmake_minimum_required(VERSION 3.10)

project(FinalProject)

set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(7952603892_basic 7952603892_basic.cpp NucleotideBases.cpp NucleotideBases.h SequenceAlignment.cpp SequenceAlignment.h StringGenerator.cpp StringGenerator.h StringTrim.cpp StringTrim.h)
add_executable(7952603892_efficient 7952603892_efficient.cpp NucleotideBases.cpp NucleotideBases.h SequenceAlignment.cpp SequenceAlignment.h EfficientSequenceAlignment.cpp EfficientSequenceAlignment.h StringGenerator.cpp StringGenerator.h StringTrim.cpp StringTrim.h)
add_executable(BasicCSV BasicCSV.cpp NucleotideBases.cpp NucleotideBases.h SequenceAlignment.cpp SequenceAlignment.h StringGenerator.cpp StringGenerator.h StringTrim.cpp StringTrim.h)
add_executable(EfficientCSV EfficientCSV.cpp NucleotideBases.cpp NucleotideBases.h SequenceAlignment.cpp SequenceAlignment.h EfficientSequenceAlignment.cpp EfficientSequenceAlignment.h StringGenerator.cpp StringGenerator.h StringTrim.cpp StringTrim.h)
add_executable(PlotData PlotDataGenerator.cpp)