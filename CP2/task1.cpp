#include<iostream>
using namespace std;

void main1() {
	char* str = new char[100];
	cout << "enter string: ";
	gets_s(str, 100);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
			continue;
		else
			cout << str[i];
	}
	cout << endl;

}