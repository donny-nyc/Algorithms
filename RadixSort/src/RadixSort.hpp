class SortStrategy {
    public:
        virtual void sort();
};

class RadixSortStrategy : public SortStrategy {
    private:
        int* values;
        int count;
        int digits;
    public:
        RadixSortStrategy(): values(0), count(0), digits(0) {};
        RadixSortStrategy(int* v, int c, int d): values(v), count(c), digits(d) {};
        ~RadixSortStrategy() { delete[] values; }
        void sort();
};
