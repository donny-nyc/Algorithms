#!/bin/bash

# install your distribubtion's inotify-tools package

while inotifywait -e close_write matrix.cpp; do
	#g++ -Wall matrix.cpp
	#./a.out
	cmake --build ./build
	./build/matrix
done
