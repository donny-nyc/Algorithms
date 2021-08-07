// typedef struct children_t children;
template <typename T>
struct children_t;

/*
 * HeapElement represents an entry in a Heap object.
 * Each element has a single templated value, and pointers
 * to its children. Here, we establish that there are
 * _at most_ two children (named left and right).
 *
 * No invariants are applied by default, but the same
 * min/Max rules described below may be considered
 */
template <typename T>
class HeapElement {
    private:
        T value;
        HeapElement* parent;
        struct children_t<T> children;
    public:
        HeapElement(T);
        ~HeapElement();
        HeapElement* getParent();
        int insertLeft(T);
        int insertRight(T);
};

/*
 * struct children_t groups the left and right
 * child nodes together in a single container
 */
template <typename T>
struct children_t {
    HeapElement<T>* left;
    HeapElement<T>* right;
};

/*
 * Heap is an array-based data structure supporting
 * O(n lg n) insert and search algorithms.
 *
 * Each node has at most two `children` (every child has
 * at most one `parent`.
 *
 * For multi-level heaps, one of two invariants can
 * hold:
 * 1. MaxHeap - the parent must be greater than its children
 *              Every child node of a MaxHeap is, itself, a smaller MaxHeap
 * 2. minHeap - the parent must be less than its children
 *              Similarly to the MaxHeap, each child node is itself
 *              a smaller minHeap.
 */
template<typename U>
class Heap {
    private:
        HeapElement<U> *elements;
    public:
        Heap(int);
        ~Heap();
        // returns the `top` node in the heap, if it exists
        U root();
        // exchanges the values of the two provided elements
        int swap(HeapElement<U>*, HeapElement<U>*);
        // places the value at its correct location on the heap
        // (assuming sufficient space remains)
        int insert(U);
        // returns a pointer to the element holding the given
        // value (if it exists)
        //
        // Assumes that _at most_ one element exists with the
        // given value
        HeapElement<U>* find(U);
};
