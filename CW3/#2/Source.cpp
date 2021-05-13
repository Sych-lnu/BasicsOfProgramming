#include"person.h"
#include<fstream>
#include<iostream>
using namespace std;

#define SIZE 50
void read_info(const char* file_name, int& size, Person*& persons) {
	ifstream input(file_name);
	input >> size;

	persons = new Person[size];

	char name[SIZE];
	char surname[SIZE];
	int year;
	char isAMan[6];

	for (int i = 0; i < size; ++i) {

			input.get();
			input.get(name, SIZE, ',');
			input.get();
			input.get(surname, SIZE, ',');
			input.get();
			input.get(isAMan,6,',');
			input.get();
			input >> year;
			if (isAMan == "man\0") {
				persons[i] = Person(name, surname, year, true);


			}else
				persons[i] = Person(name, surname, year, false);



	}
	input.close();
}


void write_to_file(const char* file_name, int size, Person* persons) {
	ofstream fout(file_name);
	for (int i = 0; i < size; i++) {
		fout << persons[i].FirstName << ", " << persons[i].LastName << ", " << persons[i].Year <<","<<persons[i].IsAMan << endl;

	}
	fout.close();
}

void find_persons(Person* persons1, Person* persons2, Person*& persons, int size1, int size2) {
	int k = 0;
	for (int i = 0; i < size1; i++) {
		for (int j = 0; j < size2; j++) {
			if (persons1[i].FirstName == persons2[j].FirstName) {
		
				persons[k] = Person(persons1[i].FirstName, persons1[i].LastName, persons1[i].Year, persons1[i].IsAMan);
				k++;
				break;
			}
		}
	}
}
void main() {
	Person*persons1, *persons2;
	int size1;
	int size2;
	read_info("in1.txt", size1, persons1);
	read_info("in2.txt", size2, persons2);
	
	Person*	persons = new Person[size1];
	find_persons(persons1, persons2, persons, size1, size2);

	//write_to_file("out.txt", size1, persons);
	
	
}