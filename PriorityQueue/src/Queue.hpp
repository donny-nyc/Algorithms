template<typename T>
class QueueEntry {
    public:
        T value;
};

template<typename U>
class PriorityQueue {
    private:
        Heap<U> heap;
    public:
        int Insert(const QueueEntry<U>);
        QueueEntry<U> Maximum();
        QueueEntry<U> ExtractMax();
        int IncreaseKey(const QueueEntry<U>, const U);
};
