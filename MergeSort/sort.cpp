#include <iostream>

using namespace std;

class Vector {
	public:
		Vector(int s) {
			if(s < 0) throw length_error{"too long"};
			elem = new int[s];
			sz = s;
		}
		~Vector() { delete[] elem; }
		int& operator[](int i) { 
			if (i < 0 || size() <= i) throw out_of_range("Vector::operator[]");
			return elem[i]; 
		}
		int size() { return sz; }
	private:
		int* elem;
		int sz;
};

void merge(Vector& v, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q - 1;

	Vector left(n1 + 1); // for sentinel
	Vector right(n2 + 1);

	for(int i = 0; i != n1; i++) {
		left[i] = v[i + p];
	}
	for(int j = 0; j != n2; j++) {
		right[j] = v[q + j + 1]; 
	}

	left[n1] = 9999;
	right[n2] = 9999;

	int i = 0;
	int j = 0;

	for(int k = p; k < r; k++) {
		if (left[i] <= right[j]) {
			v[k] = left[i];
			i++;
		} else {
			v[k] = right[j];
			j++;
		}
	}
}

void mergeSort(Vector& v, int s, int r) {
	if (r<=s) return;

	int q = (r + s) / 2;

	mergeSort(v, s, q);
	mergeSort(v, q + 1, r);
	merge(v, s, q, r);
	for(int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i < v.size() - 1) {
			cout << ", ";
		}
	}
	cout << endl;
}

int main() {
	Vector v(5);

	for(int i = 0; i != v.size(); i++)
		cin >> v[i];
	
	mergeSort(v, 0, v.size());

	for(int i = 0; i != v.size(); i++) {
		cout << v[i];
		if (i < v.size() - 1) {
			cout << ", ";
		}
	}
	cout << endl;

	return 0;
}


