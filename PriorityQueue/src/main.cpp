#include "Heap.hpp"

#include <iostream>

using namespace std;

int main() {
    MaxHeap<int> heap;

    int x;
    while(cin >> x) {
        if(x == 0) {
            heap.pop();
        } else {
            heap.insert(x);
        }
    }
}
