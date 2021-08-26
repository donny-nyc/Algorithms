/*
 * data to be sorted must be set by the
 * derived class. No params are passed
 * during the sort() call itself
 */
class SortStrategy {
    public:
        virtual void sort() = 0;
};

template <typename T>
class CountingSort : public SortStrategy {
    private:
        T* records;
    public:
        CountingSort<T>();
        void sort();
        void setRecords(T* r) { records = r; }
};

#include "CountingSort.tpp"
