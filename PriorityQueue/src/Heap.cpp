#include "Heap.hpp"

template <typename T>
Node<T>::~Node() {
    delete children;
}

/*
template <typename T>
Node<T>* Node<T>::getParent() {
    return parent;
}
*/

/*
template <typename T>
int Node<T>::insertChild(Node<T>* t, Node<T>* child) {
    if (child) {
        delete child;
    }

    child = t;

    return 0;
}
*/

template <typename T>
void Node<T>::insertLeft(Node<T>* t) {
    children->left = t;
}

template <typename T>
void Node<T>::insertRight(Node<T>* t) {
    children->right = t;
}

/*
template <typename T>
Heap<T>::~Heap() {
   delete root; 
}

template <typename T>
void Heap<T>::insert(T t) {
    // implement in child class
}
*/

/*
template <typename T>
HeapElement<T>* Heap<T>::getRoot() {
    return root;
}

template <typename T>
void Heap<T>::setRoot(T new_root) {
    root = new_root;
}
template <typename T>
int Heap<T>::swapValue(HeapElement<T>* element, HeapElement<T>* other) {
    T tmp = element->getValue();
    element->setValue(other->getValue());

    other->setValue(tmp);

    return 0;
}
*/
