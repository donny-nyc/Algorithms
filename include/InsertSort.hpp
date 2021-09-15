#include "SortStrategy.hpp"

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
		return unordered;
	}
}

#endif
