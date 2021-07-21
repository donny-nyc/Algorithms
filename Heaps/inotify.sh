#!/bin/bash

while inotifywait -e close_write binary_heap.cpp; do
	cmake --build ./build
	./build/binary_heap
done
