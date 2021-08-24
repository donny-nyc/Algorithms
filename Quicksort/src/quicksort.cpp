#include <iostream>

#include "quicksort.hpp"

using namespace std;

int* partition(int *p, int *r) {
    int x = *r;
    int* i = p - 1;
    for (int* j = p; j < r; j++) {
        if (*j < x) {
            i++;

            // exchange A[i] with A[j]
            int tmp = *j;
            *j = *i;
            *i = tmp;
        }
        cout << "(j: " << *j << ") ";
        cout << "(x: " << x << ") ";
        cout << "(i: " << i << ") ";
        for(int* w = p; w <= r; w++) {
            cout << *w << ", ";
        }

        cout << endl;
    }
    int tmp = *(i + 1);
    *(i + 1) = *r;
    *r = tmp;


    return i + 1;
}

void quicksort(int *p, int *r) {
    if (p < r) {
        int *q = partition(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}
