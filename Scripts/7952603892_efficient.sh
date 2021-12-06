#!/bin/bash

# To run this script (only for Linux and macOS), please install standard build tools (make, etc),
# cmake (minimum version 3.10) and a newer c++ compiler (like g++-10/clang++-10) using package managers
# Set as the newer compiler as the compiler for cmake to use -
# https://stackoverflow.com/questions/45933732/how-to-specify-a-compiler-in-cmake
# If you use the first way mentioned in the above link, you might have to do export CXX= and delete the build folder
# for the changes to take place

if [ -z "$1" ]
    then
        input="input.txt"
    else
        input=$1
fi

if [ -z "$2" ]
    then
        output="output.txt"
    else
        output=$2
fi

mkdir build
cd build

cmake ..
cmake --build .

./7952603892_efficient "../$input" "../$output"