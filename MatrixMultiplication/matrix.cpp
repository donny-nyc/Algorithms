#include <iostream>

using namespace std;


int multiply_matrix(int A[2][2], int B[2][2], int C[2][2], int n, int m) {
	
	return 0;
}

int main() {
	/*
	int A[2][2] = {
		{1, 2},
		{3, 4},
	};

	int B[2][2] = {
		{4, 5},
		{6, 7},
	};
	*/

	auto A = new int[2][2];
	auto B = new int[2][2];

	auto C = new int[2][2];


	auto err = multiply_matrix(A, B, C, 2, 2);

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}
