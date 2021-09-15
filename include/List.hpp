//
// Worth spending some more time with templates
// reading the documentation, and so forth,
// rather than just trying to hack my way through.
//
// https://stackoverflow.com/a/495056/15016489
#ifndef LIST_H
#define LIST_H

#include <assert.h>

namespace ds {

	template <typename T>
	class ListElement {
		private:
			ListElement *head, *prev, *next;
			T value;
		public:
			ListElement();
			ListElement(ListElement<T>&);
			~ListElement();
			void insertAfter(T);
			void insertBefore(T);
			ListElement(T t): value(t) {};
			T getValue() { return value; };
			bool hasPrev() { return prev != nullptr; }
			bool hasNext() { return next != nullptr; }
			ListElement* getNext() { return next; };
			ListElement* getPrevious() { return prev; };
	};

	template <typename U>
	class List {
		private:
			ListElement<U> *head, *tail;
			int count;
		public:
			List();
			List(const List<U>&);
			~List();
			void push(U);
			U pop();
			void insertAt(int i, U);
			bool empty();
			bool full();
			int getCount();
			ListElement<U>* getHead() { return head; }
	};

	template <typename W>
	W* sort_list(W&);

	template <typename U>
	List<U>::List() {
		head = nullptr;
		tail = head;

		count = 0;
	}

	template <typename U>
	List<U>::List(const List<U>& list) {
		ListElement<U>* new_head = new ListElement<U>(list.head->getValue());
		head = new_head;

		ListElement<U>* current = list.head;
		ListElement<U>* next = new_head;
		while((current = current->getNext())) {
			next->insertAfter(current->getValue());	
			next = next->getNext();
		}
		tail = next;
		count = list.count;
	}

	template <typename Y>
	List<Y>::~List() {
		if (count <= 0) return;

		ListElement<Y>* next, * current = head;

		while(current && count-- > 0) {
			next = current->getNext();
			delete current;
			current = next;
		}
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
	ListElement<T>::ListElement(ListElement<T>& element) {
		head = element.head;
		next = element.next;
		prev = element.prev;

		value = element.value;
	}

	template <typename T>
	ListElement<T>::~ListElement() {
		if (next && prev) {
			prev->next = next;
			next->prev = prev;
		} else if(next) {
			next->prev = nullptr;
		} else if (prev) {
			prev->next = nullptr;
		}
	}

}

#endif
