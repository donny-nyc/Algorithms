#include <iostream>

using namespace std;

template <typename T> T* CountingSort<T>::sort() {
    if (getMax() <= 0) {
        return NULL;
    }

    T helper[getMax() + 1] = {0};

    for(int i = 0; i < size(); i++) {
        // helper[records[i] will contain the
        // number of elements in `records` equal
        // to `i`
        helper[records[i]]++;
    }

    for(int j = 1; j <= getMax(); j++) {
        // each helper entry now reflects the number
        // of elements less than or equal to `j`
        //
        // so we know relatively where each `j` should
        // be in the final array (we know how many
        // entries come before it)
        helper[j] += helper[j - 1];
    }

    T* results = new T[size()];
    for(int k = size() - 1; k >= 0; k--) {
       results[helper[records[k]] - 1] = records[k];
       helper[records[k]]--;
    }

    return results;
}

template <typename T> CountingSort<T>::CountingSort() {
    return;
}
