#!/bin/bash

while inotifywait -e close_write ./; do
	cmake --build ./build
	./build/binary_heap
done
