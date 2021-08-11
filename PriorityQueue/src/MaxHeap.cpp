#include "Heap.hpp"

template<typename T>
void MaxHeap<T>::insert(T t) {
    if (!Heap<T>::root) { /* empty heap */
       Heap<T>::root = new Node<T>(t);
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
        tmp->parent = target;
        target->children.left = tmp;
    } else {
      target = new Node<T>(t);
      target->parent = prev;
      prev->children->left = target;
    }
}
