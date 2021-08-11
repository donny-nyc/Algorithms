#include "Heap.hpp"

#include <iostream>

using namespace std;

int main() {
    MaxHeap<int> heap;

    int x;
    while(cin >> x) {
        heap.insert(x);
    }
}
