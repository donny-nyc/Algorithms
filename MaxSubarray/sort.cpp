#include <iostream>
#include <climits>
#include <cstdarg>

using namespace std;

// recursively search for left-max subarray
// recursively search for right-max subarray
// iteratively search for max-spanning subarray

struct max_subarray {
	uint max_left_index;
	uint max_right_index;
	int max_sum;
};

typedef struct max_subarray max_subarray_t;

max_subarray_t max_spanning_subarray(int* A, uint low, uint mid, uint high) {
	if (low == high) {
		max_subarray_t s = {
			low,
			high,
			A[low],
		};

		return s;
	}
	int left_max = 0;
	uint left_idx = 0;
	int l_sum = 0;

	// catch unsigned int rollover, check i <= mid
	for(uint i = mid; i >= low && i <= mid; i--) {
		l_sum += A[i];
		if (l_sum > left_max) {
			left_max = l_sum;
			left_idx = i;
		}
	}

	int right_max = 0;
	uint right_idx = 0;
	int r_sum = 0;

	for(uint j = mid + 1; j <= high; j++) {
		r_sum += A[j];
		if (r_sum > right_max) {
			right_max = r_sum;
			right_idx = j;
		}
	}

	max_subarray_t result = {
		left_idx,
		right_idx,
		left_max + right_max,
	};

	return result;
}

max_subarray_t max(max_subarray_t left, max_subarray_t right, max_subarray_t span) {
	max_subarray_t max = left;

	cout << "max is left" << endl;

	if (right.max_sum > max.max_sum) {
		max = right;
	} 
	cout << "max is right" << endl;

	if (span.max_sum > max.max_sum) {
		max = span;
	}

	return max;
}

max_subarray_t max_subarray(int *A, uint low, uint high) {
	max_subarray_t result;
	if (high == low) {
		result = {
			low,
			high,
			A[low],
		};

		return result;
	}

	max_subarray_t left, right, span;

	uint mid = (low + high) / 2;
	left = max_subarray(A, low, mid);
	right = max_subarray(A, mid + 1, high);
	span = max_spanning_subarray(A, low, mid, high);

	return max(left, right, span);
}


int main() {
  int A[]= {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	try {
		max_subarray_t max_array = max_subarray(A, 0, 15);

		cout << "left: " << max_array.max_left_index << " right: " << max_array.max_right_index << " max sum: " << max_array.max_sum << endl;
	} catch (const exception& ex) {
		cout << ex.what() << endl;
	} catch (const string& ex) {
		 cout << ex << endl;
	}


	return 0;
}
