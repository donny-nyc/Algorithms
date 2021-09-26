#include "containers/vector.cpp"

template class Vector<int>;

int main() {
	Vector<int> vector = Vector<int>();

	vector.push_front(5);

	return 0;
}

