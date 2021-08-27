#include <exception>
#include <iostream>

#include "CountingSort.hpp"

using namespace std;

#define PASS 1
#define FAIL 0
int test_sort_basic_int_array() {
    cout << "test_sort_basic_int_array: ";
    int records[] = {4, 6, 1, 2, 8};
    CountingSort<int> sort = CountingSort<int>(records, 8, 5);

    int* results = sort.sort();

    for(int j = 1; j < sort.size(); j++) {
        if(results[j] < results[j-1]) { // sort failed
            cout << "FAIL: " << "expected " << results[j] << " to be less than " << results[j-1] << endl;
            return FAIL;
        }
    }

    cout << "PASS" << endl;

    return PASS;
}

int test_sort_single_element_int_array() {
    cout << "test_sort_single_element_int_array: ";
    int records[] = {4};
    CountingSort<int> sort = CountingSort<int>(records, 4, 1);

    int* results = sort.sort();

    if(results[0] != 4) { // sort failed
        cout << "FAIL: " << "expected 4, got " << results[0] << endl;
        return FAIL;
    }

    cout << "PASS" << endl;

    return PASS;
}

int test_constructor_handles_empty_array() {
    cout << "test_handles_empty_array";
    int records[] = {};
    CountingSort<int> sort = CountingSort<int>(records, 4, 0);

    int* results = sort.sort();

    cout << "PASS" << endl;

    return PASS;
}

int main() {
    //CountingSort<int> sort = CountingSort<int>();
    if(!test_sort_basic_int_array()) {
        return 1;
    }

    if(!test_sort_single_element_int_array()) {
        return 1;
    }

    if(!test_constructor_handles_empty_array()) {
        return 1;
    }

    return 0;
}
