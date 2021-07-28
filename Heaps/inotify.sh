#!/bin/bash

while inotifywait -e close_write ./; do
	make clang-format
	cmake --build ./build
	./build/binary_heap
done
