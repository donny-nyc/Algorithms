#include <iostream>

#include "quicksort.hpp"

using namespace std;

int test_handles_single_element_array() {
    cout << "test_handles_single_element_array" << endl;
    int A[] = {1};
    quicksort(A, A);

    if (A[0] != 1) {
        cout << "FAIL: test_handles_single_element_array" << endl;
        cout << "expected 1, got " << A[0] << endl;
        return 1;
    }

    cout << "PASS" << endl;

    return 0;
}

int test_handles_empty_array() {
    cout << "test_handles_empty_array" << endl;
    int A[0];
    quicksort(A, A);

    cout << "PASS" << endl;

    return 0;
}

int test_handle_unsorted_array_10() {
    cout << "test_handle_unsorted_array" << endl;
    int A[] = {9, 4, 0, 2, 7, 6, 1, 8, 3, 5};

    quicksort(A, A + 9);

    for(int i = 1; i < 10; i++) {
        if (A[i] < A[i-1]) {
            cout << "invariant failed: " << A[i - 1];
            cout << " is not less than " << A[i] << endl;
            return 1;
        }
    }

    cout << endl;

    cout << "PASS" << endl;

    return 0;
}

int test_handle_sorted_array_10() {
    cout << "test_handle_sorted_array_10" << endl;

    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    quicksort(A, A + 9);

    for(int i = 1; i < 10; i++) {
        if (A[i] < A[i-1]) {
            cout << "invariant failed: " << A[i - 1];
            cout << " is not less than " << A[i] << endl;
            return 1;
        }

    }

    cout << "PASS" << endl;

    return 0;
}

int test_handle_duplicate_values() {
    cout << "test_handle_duplicate_values" << endl;

    int A[] = {0, 0, 0, 0, 0, 1, 2, 3, 4, 5};
    quicksort(A, A + 9);

    for(int i = 1; i < 10; i++) {
        if (A[i] < A[i-1]) {
            cout << "invariant failed: " << A[i - 1];
            cout << " is not less than " << A[i] << endl;
            return 1;
        }

    }

    cout << "PASS" << endl;

    return 0;
}

int main() {
    int result = 0;
    result = test_handles_single_element_array();

    result = test_handles_empty_array();

    result = test_handle_unsorted_array_10();

    result = test_handle_sorted_array_10();

    result = test_handle_duplicate_values();

    return result;
}
