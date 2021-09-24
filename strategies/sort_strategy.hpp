#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

#include <stdexcept>

template <typename C>
class SortStrategy {
	public:
		virtual C* sort(C*);
};

template <typename C>
C* SortStrategy<C>::sort(C* container) {
	throw std::runtime_error("unimplemented");
}

#endif
