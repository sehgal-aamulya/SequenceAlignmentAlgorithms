#!/bin/bash

# To run this script (only for Linux and macOS), please install standard build tools (make, etc)
# and cmake (minimum version 3.10) using package managers

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