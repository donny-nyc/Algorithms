#include <iostream>

#include <queue>

using namespace std;

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
class Node {
    private:
        T value;
    public:
        Node* parent;
        struct children_t<T> children;
        Node(T t)  {
                value = t;
                children.left = 0;
                children.right = 0;
            };
        ~Node();
        T getValue() { return value; }
        void insertLeft(Node<T>*);
        void insertRight(Node<T>*);
};

/*
 * struct children_t groups the left and right
 * child nodes together in a single container
 */
template <typename T>
struct children_t {
    Node<T>* left;
    Node<T>* right;
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
    public:
        Node<U>* root;
        Heap() {
            root = 0;
        }
        Heap(U u) { root = new Node<U>(u); }
        // ~Heap();
        // returns the `top` node in the heap, if it exists
        Node<U>* getRoot();
        // places the value at its correct location on the heap
        // (assuming sufficient space remains)
        // returns a pointer to the element holding the given
        // value (if it exists)
        //
        // Assumes that _at most_ one element exists with the
        // given value
};

template<typename T>
class MaxHeap : public Heap<T> {
    public:
        void insert(T);
        MaxHeap() {
            Heap<T>::root = 0;
        }
        string toString();
        Node<T>* find(T);
};



template<typename U>
class MinHeap : public Heap<U> {
    public:
        void insert(U);
        Node<U>* find(U);
};


template<typename T>
string MaxHeap<T>::toString() {
    string result = "";

    queue<Node<T>*> queue;     

    queue.push(Heap<T>::root);

    Node<T>* current;
    while (!queue.empty()) {
        // queue.pop() does not return a value
        // so we need to make this two separate steps
        current = queue.front();
        queue.pop();

        result.append(to_string(current->getValue()));
        result.append(", ");

        if(current->children.left) {
            queue.push(current->children.left);
        }

        if(current->children.right) {
            queue.push(current->children.right);
        }
    }

    return result;
}

template<typename T>
void MaxHeap<T>::insert(T t) {
    if (!Heap<T>::root) { /* empty heap */
       Heap<T>::root = new Node<T>(t);
       return;
    }

    // new max - need to replace the existing node
    // and find a new position for the existing max
    Node<T>* target = Heap<T>::root;
    Node<T>* prev;
    while (target && target->getValue() > t) {
        prev = target;
        target = target->children.left;
    }

    if(target) {
        Node<T>* tmp = target;
        target = new Node<T>(t);

        if (Heap<T>::root == tmp) { 
            Heap<T>::root = target;
        } else {
            target->parent = tmp->parent;
            target->parent->children.left = target;
        }
        tmp->parent = target;
        target->children.left = tmp;
    } else {
      target = new Node<T>(t);
      target->parent = prev;
      prev->children.left = target;
    }

    string result = toString();

    cout << result << endl;
}



