#include<iostream>
using namespace std;



int* readArray(int n) {
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	return arr;
}

int* foundIndexes(int* arr, int x, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			k++;
		}
	}
	if (k == 0)
		return 0;
	int* foundArr = new int[k];
	k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			foundArr[k] = i;
			k++;
		}
	}
	return foundArr;
}

int foundIndexNumbers(int* arr, int x, int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x)
			k++;
	}
	return k;
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;
}

void main1() {
	int n;
	cout << "n = ";
	cin >> n;
	int x;
	cout << "x = ";
	cin >> x;
	int* arr = readArray(n);
	int* indexes = foundIndexes(arr, x, n);
	int k = foundIndexNumbers(arr, x, n);
	printArray(indexes, k);
	delete[] arr;
	delete[] indexes;
}
