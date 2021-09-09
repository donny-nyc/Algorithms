#include <assert.h>

#include "NumberList.hpp"

NumberList::NumberList(int c) {
    count = c;
    numbers = new Number[c];
}

NumberList::NumberList(const NumberList& other): numbers(other.numbers), count(other.count) {};

NumberList& NumberList::operator=(const NumberList& other) {
    if (this == &other) return *this;

    numbers = new Number[other.count];
    count = other.count;

    for(int i = 0; i < other.count; i++) {
        numbers[i] = other.numbers[i];
    }

    return *this;
}

NumberList::~NumberList() {
    delete[] numbers;
}


void NumberList::swap(int l, int r) {
    Number* tmp = numbers + l;

    numbers[l] = numbers[r];
    numbers[r] = *tmp;
}

Number* NumberList::insertAt(Number n, int idx) {
    assert(idx >= 0);
    if (idx < 0) {
        return nullptr;
    }

    assert(idx < count);
    if (idx >= count) {
        return nullptr;
    }

    numbers[idx] = n;

    return numbers + idx;
}

Number* NumberList::get(int c) {
    assert(c >= 0);
    if (c < 0) {
        return nullptr;
    }

    assert(c < count);
    if (c >= count) {
        return nullptr;
    }

    Number* result = nullptr;

    result = numbers + (c * sizeof(Number));

    return result;
}


void NumberList::sort() {
  Number* helper[10];  

  Number* n = nullptr;
  for(int j = 10; j >= 0; j--) {
    for(int i = 0; i < count; i++) {
      //n = get(i);
      n = &numbers[i];

      int value = n->iAt(j);

      if(!helper[value]) {
          helper[value] = n;
      } else {
          Number* next = helper[value];
          while(next->getNext()) next = next->getNext();
          next->setNext(n);
      }
    }

    int k = 0;
    Number* results = new Number(count);
    Number* n = nullptr;
    for(int i = 0; i < 10; i++) {
        n = helper[i];
        while(n) {
           results[k] = *n;
           n = n->getNext();
           j++;
        }
    }
    numbers = results;
  }
}
