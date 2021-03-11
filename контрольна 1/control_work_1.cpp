#include<iostream>;
using namespace std;
#include<cmath>;
#include<string>;

float cos_eps(float x, float eps) {   //ркхує косинус за формулою
	float a = 1;
	float s = 0;
	int n = 0;
	while (abs(a) > eps) {
		a = 1;
		for (int i = 1; i <= 2 * n; i++) {
			a *= x / i;
		}
		if (n % 2 > 0) {
			a *= -1;
		}
		s += a;
		n++;
	}
	return s;


}
void try_cos() { //перевіряє роботу першого завдання
	cout << "No 1" << "\n";
	float x, eps;
	cout << "x = ";
	cin >> x;
	cout << "eps = ";
	cin >> eps;
	cout << cos_eps(x, eps) << "\n";
	cout << "real cos = " << cos(x)<<"\n";
}

void proste() { //перевіряє число на простоту
	cout << "No 2" << "\n";
	int n;
	string n1, n2;
	n2 = "";
	cout << "n = ";
	cin >> n1;
	bool correct = true;

	for (int i = 0; i < n1.length(); i++) {
		if (i % 2 == 0) {
			n2 += n1[i];
		}

	}
	
	n = stoi(n2);
	for (int i = 1; i <= int(sqrt(n)); i++) {
		if (n % i == 0) {
			correct = false;
			break;
		}
	}
	if(correct)
		cout << "is prime: true "<<"\n";
	else
		cout << "is prime: false " << "\n";
}
int not_rec(int n) {    //не рекурсивна, рахує значення елемента рядка
	int a0 = 1;
	int a_i, curr;
	curr = a0;
	for (int i = 1; i <= n; i++) {
		a_i = curr;
		curr = 3 * a_i - 5;
		
	}
	return curr;
}
int sum(int n) { //рекурсивна, рахує суму елементів рядка
	if (n == 0) {
		return not_rec(n);
	}
	return not_rec(n) + sum(n - 1);
}
void try_sum() {   //виконує перевірку роботи третього завдання
	cout << "No 3" << "\n";
	int n;
	cout << "n = ";
	cin >> n;
	cout << "sum = " << sum(n);

}

void main() {

	cout << "variant 2\n";

	try_cos();//результат першого завдання
	proste();//результат другого завдання
	try_sum();//результат третього завдання


}