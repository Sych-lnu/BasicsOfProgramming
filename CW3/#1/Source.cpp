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
void bubble(int size, Person*& persons) {
	int x = 0;
	Person tmp;
	for (int i = size - 1; i > x; i--)
	{
		for (int j = size - 1; j > x; j--) {
			if (persons[j].Year < persons[j - 1].Year) {
				tmp = persons[j];
				persons[j] = persons[j - 1];
				persons[j - 1] = tmp;
			}

		}
		//x++;
	}

}

void write_to_file(const char* file_name, int size, Person* persons) {
	ofstream fout(file_name);
	for (int i = 0; i < size; i++) {
		fout << persons[i].FirstName << ", " << persons[i].LastName << ", " << persons[i].Year <<","<<persons[i].IsAMan << endl;

	}
	fout.close();
}

Person& find_max(Person* persons, int size) {
	int max_i = 0;
	int max_age = persons[0].Year;
	for (int i = 1; i < size; i++) {
		if (persons[i].Year < max_age) {
			max_age = persons[i].Year;
			max_i = i;
		}
	}
	return persons[max_i];
}
void main() {
	Person* persons;
	int size;
	read_info("in.txt", size, persons);
	bubble(size, persons);
	write_to_file("out.txt", size, persons);
	
	Person maxPerson = find_max(persons,size);
	cout << "person: " << maxPerson.Year << " " << maxPerson.FirstName << " " << maxPerson.LastName << " " << maxPerson.IsAMan << endl;
	
}