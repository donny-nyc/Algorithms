#!/bin/bash

while inotifywait -r -e close_write ./; do
    cmake --build ./build
    ./build/RadixSort
done
