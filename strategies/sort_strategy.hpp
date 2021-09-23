#ifndef SORT_STRATEGY_H
#define SORT_STRATEGY_H

template <typename C>
class SortStrategy {
	public:
		virtual C* sort(C*);
};

#endif
