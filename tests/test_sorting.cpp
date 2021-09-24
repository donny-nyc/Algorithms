#include "../containers/list.cpp"
#include "../strategies/insert_sort.cpp"

#include <stdexcept>
#include <iostream>

using namespace std;

void testBasic() {
	List<int> list = List<int>();

	list.push_end(5);
	list.push_end(4);
	list.push_end(3);

	InsertSort<int> s = InsertSort<int>();

	List<int>* sorted = (List<int>*)s.sort(&list);

	cout <<	sorted->get(0) << endl;
	return;
}

int main(int argc, char** argv) {
	testBasic();
}
