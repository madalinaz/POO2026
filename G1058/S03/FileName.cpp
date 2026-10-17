#include <iostream>
using namespace std;

struct Student {
	char nume[25];
	int anStudiu;
	char serie;
	bool esteIntegralist;
	//de completat cu info despre note
	//in context static sau dinamic 
	//plus alte 2 atribute la alegere
} s;

//Student init(char nume[25], int nrNote, )

/*
TEMA

1. in main, de citit un student + afisare
2. fct care initializeaza un student (primeste ca param campurile/atributele)
3. fct care afiseaza un student
4. un vct de siruri de caractere care stocheaza numele tuturor prietenilor nostri
5. fct care cauta daca un anume prieten e al nostru
6.
*/
int main() {

	Student s;
	cout << "\n--------SIRURI DE CARACTERE--------- ";
	char s1[10];
	//s1 = "Ana";
	strcpy_s(s1, strlen("Ana") + 1, "Ana");
	cout << endl << s1;


	char* s2 = nullptr;
	s2 = new char[strlen("Ana") + 1];
	strcpy_s(s2, strlen("Ana") + 1, "Ana");
	cout << endl << s2;
	delete[] s2;
	s2 = nullptr;

	cout << "\n-------Copieri-------";
	char* ps1;
	char* ps2;
	ps1 = new char[4];
	ps2 = new char[4];
	strcpy_s(ps2, strlen("Ana") + 1, "Ana");
	//ps1 = ps2;
	strcpy_s(ps1, strlen(ps2) + 1, ps2);
	cout << endl << ps1;
	cout << endl << ps2;
	delete[] ps1;
	delete[] ps2;

	cout << "\n-------Matrice-------";
	//alocare statica
	int m1[2][4];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 4; j++)
			m1[i][j] = i + j + 10;

	//aloc dinamica
	int** m2;
	m2 = new int* [2];
	for (int i = 0; i < 2; i++)
		m2[i] = new int[4];
	//to your job pe m2
	for (int i = 0; i < 2; i++) {
		delete[] m2[i];
		m2[i] = nullptr;
	}
	delete[] m2;
	m2 = nullptr;
	return 0;
}