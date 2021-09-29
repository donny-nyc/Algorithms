#include "container.hpp"
#include <stdexcept>
#include <memory>

template <typename T>
class Vector : public Container<T> {
	private:
		int count;
		int max;
		std::unique_ptr<T> values;
	public:
		Vector();
		Vector(int);
		~Vector();
		Vector(Vector<T>&&);
		auto operator=(Vector) -> Vector<T>&;
		auto operator=(Vector&&) -> Vector<T>&;
		Vector(const Vector& other);
	public:
		void push_end(T);
		auto pop_end() -> T;
		void push_front(T);
		auto pop_front() -> T;
		void insert(int, T);
		auto remove_from(int) -> T;
	public:
		auto front() -> T;
		auto back() -> T;
	public:
		auto get(int) -> T;
		void set(int, T);
		auto find(T) -> T;
		void sort();
	public:
		auto length() -> int;
};

constexpr int VECTOR_DEFAULT_SIZE = 10;

template <typename T>
Vector<T>::Vector(Vector<T>&& other) {
	count = other.count;
	max = other.max;
	values = other.values;

	other.values = nullptr;
}

template <typename T>
auto Vector<T>::operator=(Vector<T>&& other) -> Vector<T>& {
	// check for self-assignment
	if(&other == this) {
		return *this;
	}

	// delete resources held by this
	delete values;

	// transfer ownership from other to this
	count = other.count;
	max = other.max;
	values = other.values;

	return *this;
}

template <typename T>
Vector<T>::Vector() {
	values = std::unique_ptr<T>(new T[VECTOR_DEFAULT_SIZE]);
	max = VECTOR_DEFAULT_SIZE;
	count = 0;
}

template <typename T>
Vector<T>::Vector(int size) {
	if(size <= 0) {
		throw std::invalid_argument("size must be greater than zero");
	}
	values = std::unique_ptr<T>(new T[size]);
	max = size;
	count = 0;
}

template <typename T>
auto Vector<T>::operator=(Vector<T> other) -> Vector<T>& {
	count = other.count;
	max = other.max;
	values = other.values;
}

template <typename T>
Vector<T>::~Vector() {
	delete[] values;
}

template <typename T>
void Vector<T>::push_end(T elem) {
	insert(count, elem);
}

template <typename T>
void Vector<T>::push_front(T elem) {
	/* insert should already take care of this
	// shift any existing elements forward
	// to make room
	if(count > 0) {
		for(int i = count; i > 0; i--) {
			insert(i, get(i - 1));	
		}
	}

	*/
	insert(0, elem);
}

template <typename T>
auto Vector<T>::pop_end() -> T {
	return remove_from(count);
}

template <typename T>
auto Vector<T>::pop_front() -> T {
	return remove_from(0);
}

template <typename T>
void Vector<T>::insert(int idx, T elem) {
	// if idx falls outside the limits of our data
	// store, we should return an error
	if (idx < 0 || idx > count) {
		throw std::range_error("out of bounds");
	}

	// if we're at capacity, we'll need to
	// allocate a new data store. Just
	// double the array length.
	if (count == max) {
		std::unique_ptr<T> new_values = std::unique_ptr<T>(new T[max * 2]);	

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
	while(j >= 0 && j >= idx) {
		values[j + 1] = values[j];
		j--;
	}

	values[j + 1] = elem;

	count++;
}

template <typename T>
auto Vector<T>::remove_from(int idx) -> T {
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
auto Vector<T>::get(int idx) -> T {
	// don't accept idx that fall outside our bounds
	if (idx < 0 || idx >= count) {
		throw std::range_error("out of range");
	}

	// otherwise, simply return the value at the
	// requested index
	return values[idx];
}

template <typename T>
void Vector<T>::set(int idx, T value) {
	if (idx < 0 || idx > count) {
		throw std::range_error("out of range");
	}

	values[idx] = value;
}

template <typename T>
auto Vector<T>::find(T) -> T {
	throw std::runtime_error("unimplemented");
}

template <typename T>
void Vector<T>::sort() {
	throw std::runtime_error("unimplemented");
}

template <typename T>
auto Vector<T>::length() -> int {
	return count;
}

/*
 * front() returns the first element in the collection
 * if it exists
 *
 * throws std::range_error if no element is available
 */
template <typename T>
auto Vector<T>::front() -> T {
	if(count == 0) {
		throw std::range_error("vector is empty");
	}

	return values[0];
}

/*
 * back() returns the last element in the collection
 * if it exists
 *
 * throws std::range_error if the collection is empty
 */
template <typename T>
auto Vector<T>::back() -> T {
	if (count == 0) {
		throw std::range_error("collection is empty");
	}

	return values[count - 1];
}
