#!/bin/bash

g++ sort.cpp 1>/dev/null

# empty stdin should return empty
res=$(echo "" | ./a.out)

if [ -n "$res" ]; then
	echo "$res" "not empty"
	exit 1
else
	echo "pass"
fi


# sorted input should return sorted
in="1 2 3 4 5"
res=$(echo "$in" | ./a.out)

if [ "$in" != "$res" ]; then
	echo "$res" "does not equal input"
	exit 1
else
	echo "pass"
fi


# single element should return single element
in="1"
res=$(echo "$in" | ./a.out)

if [ "$in" != "$res" ]; then
	echo "$res" "does not equal input"
	exit 1
else
	echo "pass"
fi 
