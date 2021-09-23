#include "sort_strategy.hpp"
#include "../containers/container.hpp"

template <typename C>
class InsertSort : public SortStrategy<C> {
	public:
		Container<C>* sort(Container<C>*);
};

template <typename C>
Container<C>* InsertSort<C>::sort(Container<C>* container) {
	if(container->length <= 1) {
		return container;
	}

	for(int j = 2; j < container->length; j++) {

		ContainerElement<C> key = container->get(j);

		int i = j - 1;
		while(i > 0 && container->get(i).value > key.value) {
			container->get(i + 1).value = container->get(i).value;
			i = i - 1;
		}
		container->get(i + 1) = key.value;
	}
}
