#include "List.hpp"

#include <iostream>
#include <stdexcept>
#include <assert.h>

using namespace std;

using namespace ds;

template <typename T>
T* sort_list(T* input, SortStrategy<T> strategy) {

	return strategy.sort(input);
}

template <typename U>
List<U>::List() {
	head = nullptr;
	tail = head;

	count = 0;
}

template <typename Y>
List<Y>::~List() {
	delete head;
}

/*
 * push(t t) appends an element to the end
 * of the list
 */
template <typename T>
void List<T>::push(T t) {
	if (tail) {
		tail->insertAfter(t);

		tail = tail->getNext();
	} else {
		tail = new ListElement<T>(t);
		head = tail;
	}

	count++;
}

/*
 * pop() - removes the last element on the list
 * and returns it (if it exists)
 *
 * raises `runtime_error` when length is zero
 */
template <typename T>
T List<T>::pop() {
	assert(count > 0);

	if (count <= 0) {
		throw runtime_error("List is empty");
	}

	T result = tail->getValue();

	if (tail->hasPrev()) {
		tail = tail->getPrevious();
		delete tail->getNext();
	}

	count--;

	return result;
}

template <typename T>
void ListElement<T>::insertAfter(T t) {
	ListElement* tmp = nullptr;
	if (next) {
		/*
		 * Need to preserve a reference to the
		 * following element, so that we can 
		 * come back and re-link this->next and
		 * next_orig->prev
		 */
		tmp = next;
	}
	next = new ListElement(t);

	next->prev = this;

	if (tmp) {
		/*
		 * re-link the previous `next`
		 * reference, if it exists
		 */
		next->next = tmp;
		tmp->prev = next;
	}
}

template <typename T>
ListElement<T>::~ListElement() {
	if (next) {
		delete next;
	}

	if (prev) {
		prev->next = nullptr;
	}
}

int main() {

	List<int> list = List<int>();

	for(int i = 0; i < 10; i++) {
		list.push(i);
	}

	ListElement<int>* head = list.getHead();

	while(head) {
		cout << head->getValue() << endl;
		head = head->getNext();
	}

	for(int i = 0; i < 10; i++) {
		int result = list.pop();
		cout << result << endl;
	}

	return 0;
}
