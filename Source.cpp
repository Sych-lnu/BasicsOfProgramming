#include<iostream>;
#include<cmath>;
using namespace std;

void main() {
	//1
	int n;
	int k = 1;

	cout << "n = ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cout << k << " ";
			k++;
		}

		cout << endl;
	}


	//2
	int a, b, c;
	cout << "a = ";
	cin >> a;
	c = 0;
	while (a>0)
	{
		b = (a % 10)* pow(2,c);
		c++;
		a /= 10;
	}
	cout << b;
}