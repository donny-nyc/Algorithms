/*
 * data to be sorted must be set by the
 * derived class. No params are passed
 * during the sort() call itself
 */
template <typename T>
class SortStrategy {
    public:
        virtual T* sort() = 0;
};

template <typename T>
class CountingSort : public SortStrategy<T> {
    private:
        T* records;
        int count = 0;
        int max = 0;
    public:
        CountingSort<T>();
        CountingSort<T>(T* r, int m, int c): records(r), max(m), count(c) {};
        int getMax() { return max; }
        int size() { return count; }
        T* sort();
        void setRecords(T* r, int m, int c) { records = r; max = m; count = c; }
};

#include "CountingSort.tpp"
