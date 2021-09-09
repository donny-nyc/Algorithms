#include <assert.h>
#include <cmath>

class List {
    private:
        int* values;
        int count;
        int max;
        int maxLen;
    public:
        List();
        List(int c);
        List(const List& other); // copy constructor
        ~List(); // destructor
        List& operator=(const List& other); // copy assignment
        int* insert(int v);
        int getCount();
        int getMax();
        int getMaxLen();
        int get(int i);
};

int List::getCount() { return count; }
int List::getMax() { return max; }
int List::getMaxLen() { return maxLen; }

List::List() {
    values = new int[10];
    count = 0;
    max = 10;;
    maxLen = 0;
}

// List::List(int count) { this took a while to find
// we shadowed `count`, so it was never being set
List::List(int c) {
    values = new int[c];
    count = 0;
    max = c;
    maxLen = 0;
}

List::~List() {
    delete[] values;
}

List& List::operator=(const List& other) {
    count = other.count;
    max = other.max;
    maxLen = other.maxLen;

    values = new int[other.max];

    for(int i = 0; i < other.count; i++) {
        values[i] = other.values[i];
    }

    return *this;
}

/*
 * List::insert places the value on the calling object
 *
 * returns:
 * reference to the value inserted, if successful
 * a nullptr if there's no space left on the list
 *
 * state:
 * internal counter that gets incremented after every
 * insert.
 */
int* List::insert(int value) {
    assert(count < max);

    int len = trunc(log10(value)) + 1;

    if(len > maxLen) maxLen = len;

    if (count >= max) return nullptr;

    values[count] = value;

    int* res = values + count;

    count++;

    return res;
}

/*
 * iAt assumes a decimal endocing, and returns the
 * number in `value` at position `pos`
 *
 * For example:
 * iAt(123, 0) should return 3
 * iAt(123, 1) should return 2
 *
 * assert:
 * value is >= zero
 * pos is >= zero
 *
 * returns:
 * the value at pos, if it exists
 * -1 if the pos is out of bounds, or
 *  value is unsupported
 */

int iAt(int value, int pos) {
    assert(value >= 0);
    assert(pos >= 0); 

    if(value < 0) return -1;
    if(pos < 0) return -1;

    // return (value >> pos) % 10; this is incorrect for a base-10 value
    if(pos > 0) {
        // value = (value / (pos * 10)); this is still wrong
        value = (value / (pow(10, pos)));
    }

    return value % 10;
}

/*
 * List::get returns the value stored at the given index
 *
 * assert:
 * idx is >= 0 and < the count;
 *
 * returns
 * the value, if it exists
 * -1 for out of bounds requests
 */
int List::get(int idx) {
    assert(idx >= 0);
    assert(idx < getCount());

    if(idx < 0) return -1;
    if(idx >= getCount()) return -1;

    return values[idx];
}

/* 
 * sort should return the given numbers in ascending order
 * in O(n) time
 */
void sortList(List& list) {

    int current = 0;
    for(int i = 0; i < list.getMaxLen(); i++) {
        List helper[10];
        for(int j = 0; j < list.getCount(); j++) {
            current = list.get(j);

            int value = iAt(current, i);

            helper[value].insert(current);
        }

        int count = list.getCount();
        List* results = new List(count);

        for(int l = 0; l < 10; l++) {
            for(int m = 0; m < helper[l].getCount(); m++) {
                results->insert(helper[l].get(m));
            }
        }

        list = *results;
    }
}

int main() {
    List l = List(3);    

    l.insert(500);
    l.insert(123);
    l.insert(43);

    sortList(l);

    return 0;
}
