#include <iostream>

using namespace std;

class Matrix {
	private:
		double** matrix;
		int col;
		int row;
	public:
		Matrix(){};
		double& get(int i, int j) {
			return matrix[i][j];
		}
		void set(int i, int j, int val) {
			matrix[i][j] = val;
		}
		void Create(int row, int col);
		int GetCols();
		int GetRows();
};

int Matrix::GetCols() {
	return col;
}

int Matrix::GetRows() {
	return row;
}

void Matrix::Create(int row_, int col_) {
	// initialization value
	double val = 0.0;
	col = col_; // initialize private members
	row = row_;

	matrix = new double*[row]; // Create a new array of size row_

	for(int i = 0; i < row; i++) {
		matrix[i] = new double[col]; // Create new cols of size col (inside array of row)
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			matrix[i][j] = val;
		}
	}
}


/* n0 and n1 are the start and end iindeces for the rows
 * m0 and m1 are the start / end indeces for the cols
 */
int multiply_matrix(Matrix A, Matrix B, Matrix C, int n0, int n1, int m0, int m1) {

	int rows = n1 - n0;
	int cols = m1 - m0;

	if (rows == 1 && cols == 1) {
		C.set(n0, m0, A.get(n0, m0) * B.get(n0, m0));
		return C.get(n0, m0);
	}

	multiply_matrix(A, B, C, n0, (n0 + rows) / 2, m0, (m0 + cols) / 2);
	multiply_matrix(A, B, C, (n0 + rows) / 2, n1, m0, (m0 + cols) / 2);
	multiply_matrix(A, B, C, n0, (n0 + rows) / 2, (m0 + cols) / 2, m1);
	multiply_matrix(A, B, C, (n0 + rows) / 2, n1, (m0 + cols) / 2, m1);

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

	auto matrixA = Matrix();
	auto matrixB = Matrix();
	auto matrixC = Matrix();

	matrixA.Create(2, 2);

	matrixA.set(0,0,4);
	matrixA.set(1,0,1);
	matrixA.set(0,1,2);
	matrixA.set(1,1,3);


	matrixB.Create(2, 2);

	matrixB.set(0,0,-1);
	matrixB.set(1,0,0);
	matrixB.set(0,1,0);
	matrixB.set(1,1,-1);

	matrixC.Create(2, 2);

	matrixC.set(0,0,0);
	matrixC.set(0,0,0);
	matrixC.set(0,0,0);
	matrixC.set(0,0,0);

	multiply_matrix(matrixA, matrixB, matrixC, 0, 2, 0, 2);

	cout << matrixC.get(0, 0);
	cout << matrixC.get(1, 0) << endl;
	cout << matrixC.get(0, 1);
	cout << matrixC.get(1, 1) << endl;

	return 0;
}
