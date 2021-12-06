#!/bin/bash

# To run this script (only for Linux and macOS), please install standard build tools (make, etc),
# cmake (minimum version 3.10) and new c++ compiler (like g++-10/clang++-10) 
# set as the default compiler - https://stackoverflow.com/questions/45933732/how-to-specify-a-compiler-in-cmake

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

./7952603892_basic "../$input" "../$output"