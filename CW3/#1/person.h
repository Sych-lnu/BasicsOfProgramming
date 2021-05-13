#pragma once
#include<iostream>
using namespace std;
#define SIZE 50
struct Person {
	char FirstName[SIZE];
	char LastName[SIZE];
	int Year;
	bool IsAMan;
	Person(const char* firstname = "", const char* lastname = "", int year = 2000, bool isAMan = true);
};