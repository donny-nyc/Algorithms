#include "container.hpp"
#include <stdexcept>

template <typename T>
class List {
	private:
		int count;
		int max;
		T* values;
	public:
		List();
		~List();
		List(const List& other);
		void push_end(T);
		T pop_end();
		void push_front(T);
		T pop_front();
		void insert(int, T);
		T remove_from(int);
		T get(int);
		T find(T);
		void sort();
	public:
		int length();
};

template <typename T>
List<T>::List() {
	values = new T[10];
	max = 10;
	count = 0;
}

template <typename T>
List<T>::~List() {
	delete[] values;
}

template <typename T>
void List<T>::push_end(T elem) {
	insert(count, elem);
}

template <typename T>
void List<T>::push_front(T elem) {
	insert(0, elem);
}

template <typename T>
T List<T>::pop_end() {
	return remove_from(count);
}

template <typename T>
T List<T>::pop_front() {
	return remove_from(0);
}

template <typename T>
void List<T>::insert(int idx, T elem) {
	// if idx falls outside the limits of our data
	// store, we should return an error
	if (idx < 0 || idx > count) {
		throw std::range_error("out of bounds");
	}

	// if we're at capacity, we'll need to
	// allocate a new data store. Just
	// double the array length.
	if (count == max) {
		T* new_values = new T[max * 2];				

		// copy existing values into  new data store
		for(int i = 0; i < count; i++) {
			new_values[i] = values[i];
		}

		values = new_values;
	}

	// if we're adding to the end, no need 
	// to shift elements - just append it
	// and bump the count (assuming there's space)
	if (idx == count) {
		values[idx] = elem;
		count++;

		return;
	}

	// otherwise, shift all existing elements down
	// to make space for the new value
	int j = count - 1;
	while(j > 0 && j > idx) {
		values[j + 1] = values[j];
		j--;
	}

	values[j + 1] = elem;
}

template <typename T>
T List<T>::remove_from(int idx) {
	// we should err if idx is out of bounds
	if (idx < 0 || idx > count) {
		throw std::range_error("out of range");
	}

	// we can just return the last element
	// without shifting the rest if
	// idx points to the end
	if (idx == count) {
		count--;
		return values[idx];

		// we may decide to properly purge the value
		// for now, we simply decrease count, and treat
		// and out of bound requests as undefined behavior
	}

	// for any 'inner' requests, we have to
	// shift the trailing values down, as:
	T result = values[idx];
	int j = count - 1;
	while( j > 0 && j > idx ) {
		values[j - 1] = values[j];
		j--;
	}

	count--;

	return result;
}

template <typename T>
T List<T>::get(int idx) {
	// don't accept idx that fall outside our bounds
	if (idx < 0 || idx > count) {
		throw std::range_error("out of range");
	}

	// otherwise, simply return the value at the
	// requested index
	return values[idx];
}
