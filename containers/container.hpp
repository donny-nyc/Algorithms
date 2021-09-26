/* Containers
 * Description: Standard operations for data structures
 * Author: Stephen Donahue
 */
#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "../strategies/sort_strategy.hpp"
#include "../strategies/search_strategy.hpp"

#include <stdexcept>

template <typename T>
class ContainerElement {
	public:
		T value;
	public:
		ContainerElement();
		ContainerElement(T t): value(t) {};
};

/* Container
 * Provides an interface for fundamental
 * data structure operations, eg: sorting,
 * searching, inserting, or deleting
 * elements from the underlying store
 */
template <typename T>
class Container {
	private:
		SearchStrategy<T> searchStr;
		SortStrategy<T> sortStr;
	public:
		virtual T find(T);
		virtual void sort();
		virtual T get(int);
		virtual void set(int, T);
	public:
		virtual int length();
};

template <typename T>
T Container<T>::find(T target) {
	throw std::runtime_error("unimplemented: " + target);	
}

template <typename T>
void Container<T>::sort() {
	throw std::runtime_error("unimplemented: ");
}

template <typename T>
int Container<T>::length() {
	throw std::runtime_error("unimplemented");
}

template <typename T>
T Container<T>::get(int) {
	throw std::runtime_error("unimplemented");
}

template <typename T>
void Container<T>::set(int, T) {
	throw std::runtime_error("unimplemented");
}

#endif
