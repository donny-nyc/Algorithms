#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int> in;

	string i;
	while(cin >> i) {
		in.push_back(stoi(i));
	}

	/* before c++11, use iterator
	 for (vector<int>::iterator i = in.begin(); i != in.end(); i++) {
		 cout << i << endl;
	 }
  */

	// for (int j = 2; j < in.size(); j++) {  // zero-based array, not 1-based. A[1] is 2nd element
	for (int j = 1; j < in.size(); j++) {
		int key = in.at(j);
		int i = j - 1;
		// while(i > 0 && in.at(i) > key) {  // related to above - we need to include lowest bound (0)
		while(i >= 0 && in.at(i) > key) { 
			in.at(i + 1) = in.at(i);
			i--;
		}
		in.at(i + 1) = key;

	}

	// if c++11 is available, use range-based loops
	// for (auto i : in) {
	for(vector<int>::iterator i = in.begin(); i != in.end(); i++) {
		cout << *i;
		if(i < in.end() - 1) {
			cout << " ";
		}
	}

	return 0;
}
