#include "List.hpp"

#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

using namespace ds;

namespace sort {
  template <typename V>
	class SortStrategy {
		public:
			SortStrategy();
			~SortStrategy();
			List<V> sort(List<V>&);
	};

	template <typename V>
	SortStrategy<V>::SortStrategy() {}

	template <typename V>
	SortStrategy<V>::~SortStrategy() {}

	template <typename V>
	List<V> SortStrategy<V>::sort(List<V>& unordered) {
		return unordered;
	}
}

#endif
