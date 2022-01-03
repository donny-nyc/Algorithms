#include <iostream>
#include <random>
#include <vector>

using std::vector;
using std::random_device;
using std::mt19937; // Mersenne Twister pseudo-random generator; 32-bit numbers with state size of 19937 bits
using std::uniform_int_distribution;
using std::cout;
using std::endl;


auto random_number() -> int {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<mt19937::result_type> dist(0,4);

	return int(dist(rng));
}

auto main() -> int {
	const vector<int> search_space {1, 3, 5, 7, 9};

	const int target = 9;
	auto it = search_space.begin();

	while(it != search_space.end() && *it < target) {
		int j = random_number();
		if(*it < search_space[j] && search_space[j] <= target) {
			it = search_space.begin() + j;	
			if (*it == target) {
				cout << distance(search_space.begin(), it) << '\n';	
				return 0;
			}
		}
		it++;

	}

	if (it == search_space.end() || *it > target) {
		cout << "Not found\n";
		return 1;
	} else {
		cout << distance(search_space.begin(), it) << '\n';
	}
	
	return 0;
}
