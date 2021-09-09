#include "Radix.hpp"
#include <assert.h>

int Number::iAt(int pos) {
    // assert(pos > 0); // can't do that - zero indexed array
    assert(pos >= 0);
    if(pos < 0) {
        return -1;
    }

    return (value >> pos) % 10;  
}
