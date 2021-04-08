#include<iostream>
using namespace std;

float** create_matrix(int n, int m) {
	float** matrix = new float* [n];
	for (int i = 0; i < n; i++) {
		float* row = new float[m];
		for (int j = 0; j < m; j++) {
			row[j] = 0;
		}
		matrix[i] = row;
	}
	return matrix;
}

void matrix_read(float** matrix, int n, int m) {

	for (int i = 0; i < n; i++) {
		float* row = new float[m];
		for (int j = 0; j < m; j++) {
			cout << "m[" << i << "][" << j << "] = ";
			cin >> row[j];
		}
		matrix[i] = row;
	}
}


float** sum_matrix(float** m1, float** m2, int n) {
	float** sum = create_matrix(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return sum;
}

float sumDiadonals(float** matrix, int n) {
	float s = 0;
	for (int i = 0; i < n; i++) {
			s += matrix[i][i] + matrix[n-1-i][i];
	}
	return s;
}

void transpon(float** m, int n) {
	float curr;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			curr = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = curr;
		}
	}
}

void print_matrix(float** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mat[i][j] << "\t";
		}
		cout << endl;
	}
}

void dublicate(float** m1, float** m2, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m2[i][j] = m1[i][j];
		}
	}
}

void delMat(float** m, int n) {
	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;
}

void main() {
	int n;
	cout << "n = ";
	cin >> n;
	float** a = create_matrix(n, n);
	matrix_read(a, n, n);
	float** a_t = create_matrix(n, n);
	dublicate(a, a_t, n);
	transpon(a_t, n);
	float** b = sum_matrix(a, a_t, n);
	float sum = sumDiadonals(b, n);
	cout << "sum = " << sum << endl;
	delMat(b, n);
	delMat(a, n);
	delMat(a_t, n);
}