#include "containers/list.cpp"

template class List<int>;

int main() {
	List<int> list = List<int>();

	list.push_front(5);

	return 0;
}

