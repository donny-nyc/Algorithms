//
// Worth spending some more time with templates
// reading the documentation, and so forth,
// rather than just trying to hack my way through.
//
// https://stackoverflow.com/a/495056/15016489
#include <stdexcept>
#include <string>

using namespace std;

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
			ListElement(T t): value(t), next(nullptr), prev(nullptr) {};
			T getValue() { return value; };
			bool hasPrev() { return prev != nullptr; }
			bool hasNext() { return next != nullptr; }
			ListElement* getNext() { return next; };
			void setNext(ListElement<T>*);
			void setPrev(ListElement<T>*);
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
			void insertAt(int, ListElement<U>*);
			U  peekValue(int); // safely remove element at index, if exists
			ListElement<U>* popElement(int); // safely remove element at index, if exists
			bool empty();
			bool full();
			int getCount();
			std::string String();
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

	template <typename T>
	std::string List<T>::String() {
		std::string result = "";
		for(int i = 0; i < count; i++) {
			result += to_string(peekValue(i)) + ", ";
		}
		result += "\n";

		return result;
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

	template <typename T>
	int List<T>::getCount() {
		return count;
	}

	template <typename T>
	void List<T>::insertAt(int idx, ListElement<T>* elem) {
		if (idx < 0) throw std::range_error("idx cannot be negative");

		if (idx > count) throw std::range_error("idx outside of range: " + to_string(idx));

		ListElement<T>* current = head;
		for(int i = 0; i <= idx; i++) {
			if (current->hasNext()) {
				current = current->getNext();
			} else {
				current->setNext(elem);
				elem->setPrev(current);
				elem->setNext(nullptr);

				tail = elem;

				count++;
				
				return;
			}

			if (!current) throw std::runtime_error("current is null");
		}

		if(current->hasPrev()) {
			current->getPrevious()->setNext(elem);
		}
		elem->setNext(current);
		current->setPrev(elem);	

		count++;
	}

	template <typename T>
  T List<T>::peekValue(int idx) {
		if (idx < 0) throw std::range_error("idx cannot be negative");

		if (idx >= count) throw std::range_error("idx outside of range");

		ListElement<T>* current = head;
		for(int i = 0; i < idx; i++) {
			if(current->hasNext()) {
				current = current->getNext();
			}
		}

		return current->getValue();
	}

	template <typename T>
	void ListElement<T>::setNext(ListElement<T>* elem) {
		next = elem;
	}

	template <typename T>
	void ListElement<T>::setPrev(ListElement<T>* elem) {
		prev = elem;
	}

	template <typename T>
  ListElement<T>* List<T>::popElement(int idx) {
		if (idx < 0) throw std::range_error("idx cannot be negative");

		if (idx > count) throw std::range_error("idx outside of range: " + to_string(idx));

		ListElement<T>* current = head;
		for(int i = 0; i < idx; i++) {
			if(current->hasNext()) {
				current = current->getNext();
			} 
		}

		if (current->hasNext() && current->hasPrev()) {
			current->getPrevious()->setNext(current->getNext());
			current->getNext()->setPrev(current->getPrevious());
		} else if(current->hasPrev())
			current->getPrevious()->setNext(nullptr);
		else if(current->hasNext())
			head = current->getNext();
			current->getNext()->setPrev(nullptr);

		count--;

		return current;
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
