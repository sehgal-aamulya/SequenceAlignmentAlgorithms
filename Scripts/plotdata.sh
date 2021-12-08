#!/bin/bash

# To run this script (only for Linux and macOS), please install standard build tools (make, etc)
# and cmake (minimum version 3.10) using package managers

if [ -z "$1" ]
    then
        output="plotdata.csv"
    else
        output=$1
fi


mkdir build
cd build

cmake ..
cmake --build .

./PlotData "../$output"

cd ..

python3 plotdata.py $output