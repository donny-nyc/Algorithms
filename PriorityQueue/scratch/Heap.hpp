#include <iostream>

using namespace std;

template <class T>
class Heap {
	public:
		void insert(T t);
};

template <class T>
class MaxHeap : public Heap<T> {
	public:
		void insert(T t);
};

template <class T>
void MaxHeap<T>::insert(T t) {
	cout << "Insert things" << endl;	
}

template <class T>
void Heap<T>::insert(T t) {
	cout << "Heap insert things" << endl;
}
