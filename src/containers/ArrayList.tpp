#include <iostream>
#include <stdexcept>

template <typename T>
ArrayList<T>::ArrayList() {
	count = 0;

	return;
}

// returns the number of elements stored in the underlying
// array (does not return the length of the array)
// should return an int.
template <typename T>
auto ArrayList<T>::size() -> int {
	return count;
}

// have to include the template type
template <typename T>
auto ArrayList<T>::get(int index) -> T {
	if (index < 0) {
		throw std::range_error("index cannot be less than zero");
	}

	if (index > size()) {
		throw std::range_error("index must be less than the element count");
	}

	return values[index];
}

// resize extends the underlying array.
// when no size is given, should try to double the
// array size
template <typename T>
void resize() {

}

template <typename T>
void ArrayList<T>::push_front(T elem) {

}

template <typename T>
void ArrayList<T>::push_back(T elem) {

}

template <typename T>
void ArrayList<T>::sort() {
	throw std::runtime_error("sort - not implemented");

	return;
}

template <typename T>
auto ArrayList<T>::find() -> T {
	throw std::runtime_error("find - not implemented");

	return T();
}

template <typename T>
auto operator<<(std::ostream os, const ArrayList<T>&) -> std::ostream& {
	throw std::runtime_error("operator<< - not implemented");

	return os << "ArrayList";
}
