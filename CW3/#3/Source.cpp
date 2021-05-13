#include"point.h"
#include<iostream>
using namespace std;

void main() {
	Point A = Point(1, 1);
	Point B = Point(0, 3);
	cout << "len = " << A.len(B) << endl;
	cout << "len = " << B.len(A) << endl;
}