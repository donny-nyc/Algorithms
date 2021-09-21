#include "InsertSort.hpp"
#include "List.hpp"

#include <iostream>

using namespace std;

using namespace ds;

using namespace sort;

int main() {

	List<int> l = List<int>();

	for(int i = 9; i >= 0; i--) {
		l.push(i);
	}

	InsertSort<int> is;

	List<int> result = is.sort(l);

	cout << result.String() << endl;

	return 0;
}
