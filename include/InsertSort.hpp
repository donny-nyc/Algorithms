#include "SortStrategy.hpp"
#include <iostream>

using namespace std;

#ifndef INSERT_SORT_H
#define INSERT_SORT_H

namespace sort {
	template <class V>
	class InsertSort : public SortStrategy<V> {
		public:
			InsertSort();
			~InsertSort();
			List<V> sort(List<V>&);
	};

	template <class V>
	InsertSort<V>::InsertSort() {

	}

	template <class V>
	InsertSort<V>::~InsertSort() {

	}

	template <class V>
	List<V> InsertSort<V>::sort(List<V>& unordered) {
		List<V> ordered;

		ListElement<V>* current = unordered.getHead();
		for (int j = 0; j < unordered.getCount(); j++) {
		// for (int j = 1; j < unordered.getCount(); j++) { why were we starting at 1?
			// cout << unordered.String() << endl;
			ListElement<V>* key = unordered.popElement(j);
			int i = j;
			// while(i > 0 && in.at(i) > key) {  // related to above - we need to include lowest bound (0)
			while(i < unordered.getCount() && unordered.peekValue(i) < key->getValue()) { 
				// unordered.insertAt(i + 1, unordered.popElement(i));
				i++;
			}
			// unordered.insertAt(i + 1, key);
			unordered.insertAt(i, key);
		}


		current = unordered.getHead();
		while(current) {
			ordered.push(current->getValue());

			current = current->getNext();
		}

		return ordered;
	}
}

#endif
