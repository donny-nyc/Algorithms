/* Containers
 * Description: Standard operations for data structures
 * Author: Stephen Donahue
 */
#ifndef CONTAINERS_H
#define CONTAINERS_H

#include "../strategies/sort_strategy.hpp"
#include "../strategies/search_strategy.hpp"

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
		virtual void push_end(T);
		virtual T pop_end();
		virtual void push_front(T);
		virtual T pop_front();
		virtual void insert(int, T);
		virtual T* get(int); // return the element at the given index
		virtual T find(T);
		virtual void sort();
	public:
		virtual int length();
};

#endif
