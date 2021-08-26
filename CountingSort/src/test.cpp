#include <iostream>

#include "CountingSort.hpp"

using namespace std;

int main() {
    //CountingSort<int> sort = CountingSort<int>();
    int records[] = {4, 6, 1, 2, 8};
    CountingSort<int> sort = CountingSort<int>(records, 8, 5);

    int* results = sort.sort();

    for(int j = 0; j < sort.size(); j++) {
        cout << results[j] << ", ";
    }

    cout << endl;

    return 0;
}
