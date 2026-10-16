#include<iostream>
using namespace std;

struct Student {
	char nume[25];
	//adaugati o enumeratie
	int varsta;
	//alte campuri
	//vector de note + cate note
};

//HOME
//fct care citeste un Student
//fct care afis un Student

int main() {
	//siruri de caractere
	//tipuri de copieri
	//matrice

	char s1[25];
	cout << s1;
	int x=5;
	cout << x;
	//s1 = "Ana";
	strcpy_s(s1, strlen("Ana" ) + 1, "Ana");
	//strcpy_s(s1, strlen("Ana"+1), "Ana");
	cout << endl << s1;

	char* ps;
	//cout << endl << ps;//oxcccc
	cout << endl << &ps;//o adresa pe stiva
	cout << endl << sizeof(ps);//4
	cout << endl << sizeof(&ps);//4
	cout << endl << sizeof(ps[0]);//1

	ps = s1;//shallow copy
	cout << endl << ps;
	cout << endl << s1;
	s1[1] = 'm';
	s1[2] = 'i';
	cout << endl << ps;
	cout << endl << s1;
	//delete[] ps;

	ps = new char[strlen("Gigel") + 1];
	strcpy_s(ps, strlen("Gigel") + 1, "Gigel");
	cout << endl<<ps;
	delete[] ps;

	//TEMA din siruri
	//avem o lista de prieteni, cate un prieten pe fiecare linie a unei matrice
	//sa se citeasca prietenii si sa se verifice daca un anume prieten este in lista

	int m1[2][4];

	int** m2;
	m2 = new int* [2];
	for (int i = 0; i < 2; i++) {
		m2[i] = new int[4];
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			m2[i][j] = i + j + 10;

	for (int i = 0; i < 2; i++) {
		delete[] m2[i];
		//m2[i] = nullptr;
	}
	delete[] m2;
	m2 = nullptr;

	return 0;
}