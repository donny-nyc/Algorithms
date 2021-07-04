#!/bin/bash

LEN=$1

function get_random {
	for i in $(seq $LEN); do
		echo "$RANDOM"
	done
}

SOURCE_FILE=sort.cpp
OUT_FILE=sort
FLAGS="-Wall -Werror -Wextra"

GXX=g++

$GXX $SOURCE_FILE $FLAGS -o $OUT_FILE

time get_random | ./$OUT_FILE $LEN
