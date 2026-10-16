#include<iostream>
using namespace std;

//TO DO
//de implementat mecanisme pentru ca utilizatorul sa scrie textul ROSU iar la afisare sa se afiseze textul ROSU, nu codificarea numerica din spate

//TO DO 2
//de implementat functia transformare
//care permite transformarea unui Student intr-un sir de caractere

class Student {
	//campuri/atribute

	//comportamente->metode
};

struct Student {
	char nume[25];
	int varsta;
	int grupa;
};

struct Masina {
	char* model;
	int anFabricatie;
};

union id {
	int cui;
	long cnp;
};

enum Culoare{
	ROSU, VERDE, ALBASTRU, GALBEN
};

enum GradDidactic {
	PREPARATOR, ASISTENT, LECTOR, CONF, PROF
};

//enum TEST {
//	ROSU
//};

void afisare(Student s) {
	cout << "\nNume: " << s.nume;
	cout << "\nVarsta: " << s.varsta;
	cout << "\nGrupa: " << s.grupa;
}

//char* transformare(Student s) {
//	//....
//}

int main() {
	//culori
	//structura
	//vector de caractere (sir de caractere)
	//transpunere numerica
	//matrice (fiecare linie este culoare)

	Culoare c = ROSU;
	Culoare c1 = Culoare::ROSU;

	cout << "\nCuloarea rosu are codul: " << c;

	//c = 0;
	cout << "\nIntroduceti o culoare (0-ROSU, 1-VERDE, 2-ALBASTRU, 3-GALBEN): ";
	int x;
	cin >> x;
	c = (Culoare)x;
	cout << "\nCuloare de dupa citire: " << c;

	cout << "\n--------UNION---------";
	id id;
	id.cui = 12345;
	cout << endl << id.cui;
	cout << endl << id.cnp;

	id.cnp = 123456789;
	cout << endl << id.cui;
	cout << endl << id.cnp;

	cout << "\n--------STRUCT---------";
	Student s;
	strcpy_s(s.nume, strlen("Gigel") + 1, "Gigel");
	s.grupa = 1056;
	s.varsta = 20;
	//cin >> s;
	//cout << s;
	//cout << transformare(s);
	afisare(s);
	Student s1;
	s1 = s;

	Masina m1;
	m1.model = new char[strlen("Opel") + 1];
	strcpy_s(m1.model, strlen("Opel") + 1, "Opel");
	m1.anFabricatie = 2010;

	Masina m2;
	m2 = m1;
}