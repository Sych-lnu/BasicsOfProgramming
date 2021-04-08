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

void findBlock(float** matrix,float** m_k, int n, int m, int k) {
	int last_n = 0, last_m = 0;
	float max_s = 0;
	float curr_s = 0;
	for (int curr_n = 0; curr_n <= (n - k); curr_n++) {
		for (int curr_m = 0; curr_m <= (m - k); curr_m++) {
			for (int i = curr_n; i < (curr_n + k); i++) {
				for (int j = curr_m; j < (curr_m + k); j++) {
					curr_s += matrix[i][j];
				}
			}
			if (curr_s > max_s) {
				last_n = curr_n;
				last_m = curr_m;
				max_s = curr_s;
			}
			curr_s = 0;
		}
	}
	for (int i = last_n; i < (last_n + k); i++) {
		for (int j = last_m; j < (last_m + k); j++) {
			m_k[i - last_n][j - last_m] = matrix[i][j];
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
void delMat(float** m, int n) {
	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;
}

void main2() {
	int n, m, k;
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	cout << "k = ";
	cin >> k;
	float** matrix = create_matrix(n, m);
	matrix_read(matrix, n, m);
	float** m_k = create_matrix(k, k);
	findBlock(matrix, m_k, n, m, k);
	print_matrix(m_k, k);
	delMat(matrix, n);
	delMat(m_k, k);
}