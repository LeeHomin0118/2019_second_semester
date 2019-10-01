#include <iostream>
#include <string>
using namespace std;

void student_management_menu() {
	int choice_menu = 0;

}

class Student_info {
private:
	string name;
	char department;
	int studentid = 0;
	int age = 0;
	int tel = 0;
public:
	void Insertion() {
		cout << "Name:";
		getline(cin, name);
		cout << "___" << name << "___";
	}

};

int main() {
	Student_info S=Student_info();
	S.Insertion();

}


/*
#pragma warning(disable:4996)
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class student_Information {
private:
	string name;
	string department;
	int student_id = 0;
	int age = 0;
	int tel = 0;
public:
	void insertion();
	void search();
	void name_Check();
};

void student_Information::search() {

}

void student_Information::name_Check() {

}

void student_Information::insertion() {
	cout << "Name :";
	getline(cin, name);

	cout << "Student ID :";
	cin >> student_id;

	cout << "Age :";
	cin >> age;

	cout << "Department :";
	getline(cin, department);

	cout << "Tel :";
	cin >> tel;
}

void student_Management_Menu() {
	int choice_Menu = 0;
	student_Information a = student_Information();

	cout << "******** MENU ********" << endl;
	cout << " 1. INSERTION" << endl;
	cout << " 2. SEARCH" << endl;
	cout << " 3. EXIT" << endl;
	cout << "**********************" << endl << endl;
	cout << ">";

	cin >> choice_Menu;

	switch (choice_Menu) {
	case 1:
		a.insertion();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		cout << "wrong input" << endl;
		break;
	}


}
*/