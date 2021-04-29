#include<fstream>
#include<iostream>
using namespace std;
int main() {
	ifstream fin("in.txt");
	int k = 0;
	char** arr;
	for (int i = 0;; i++) {
		char* str = new char[100];
		fin >> str;
		arr[i] = str;
		k++;
		if (str == "\0") {

			break;
		}


	}
	for (int i = k - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}
	cout << endl;
}