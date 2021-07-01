#!/bin/bash
VERBOSE=0

function set_up {
	g++ sort.cpp 1>/dev/null
}

function test_case {
	input="$1"
	expected="$2"

	res=$(echo "$input" | ./a.out)

	if [ $VERBOSE == 1 ]; then
		if [ -z "$input" ]; then
			echo "case: <empty string>"
		else
			echo "case: $input"
		fi
	fi

	if [ "$expected" != "$res" ]; then
		echo "FAIL: expected $expected, got $res"
	else
		echo "pass"
	fi
}

set_up

# must have the same length
# ie - there must be an expected
# value for each test case
cases=("" "1 2 3 4 5" "1" "BADBEEF" "3 2 1" "9999999999")
expected=("" "1 2 3 4 5" "1" "" "1 2 3" "")

# iterate over the indeces so we can pull the
# test case and the expected results
for t in "${!cases[@]}"; do
	in="${cases[$i]}"
	exp="${expected[$i]}"

	test_case "$in" "$exp"
done
