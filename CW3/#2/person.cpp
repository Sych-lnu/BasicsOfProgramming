#include"person.h"
#define SIZE 50
Person::Person(const char* firstname, const char* lastname, int year, bool isAMan) {
	strcpy_s(FirstName, SIZE, firstname);
	strcpy_s(LastName, SIZE, lastname);
	Year = year;
	IsAMan = isAMan;
}

