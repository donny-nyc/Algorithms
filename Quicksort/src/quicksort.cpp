#include <iostream>

using namespace std;

int* partition(int *p, int *r) {
    int x = *r;
    int* i = p - 1;
    for (int* j = p; j < r - 1; j++) {
        if (*j < x) {
            i++;

            // exchange A[i] with A[j]
            int tmp = *j;
            *j = *i;
            *i = tmp;
        }
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

int main() {

    int A[] = {3, 5, 1, 4, 9, 2, 7};

    quicksort(A, A + 6);

    for(int i = 0; i < 7; i++) {
        cout << i << ", ";
    }
    cout << endl;

    return 0;
}
