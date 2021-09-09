#include "Radix.hpp"

class NumberList {
    private:
        Number* numbers;
        int count;
    public:
        NumberList(int);
        ~NumberList();
        NumberList(const NumberList& other); // copy constructor
        NumberList& operator=(const NumberList& other); // copy assignment
        void swap(int, int);
        Number* insertAt(Number, int);
        Number* get(int);
        void sort();
};
