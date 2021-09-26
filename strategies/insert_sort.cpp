#include "sort_strategy.hpp"
#include "../containers/container.hpp"

template <typename C>
class InsertSort : public SortStrategy<C> {
	public:
		Container<C>* sort(Container<C>*);
};

template <typename C>
Container<C>* InsertSort<C>::sort(Container<C>* container) {
	if(container->length() <= 1) {
		return container;
	}

	for(int j = 1; j < container->length(); j++) {

		C key = container->get(j);

		int i = j - 1;
		while(i >= 0 && container->get(i) > key) {
			container->set(i + 1, container->get(i));
			i = i - 1;
		}
		container->set(i + 1, key);
	}

	return container;
}
