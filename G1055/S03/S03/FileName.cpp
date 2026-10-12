#include<iostream>
using namespace std;

struct Student
{
	char nume[25];
	int anStudiu;
	bool esteBuget;
	//vector de note + dimensiunea sa
	//v1 (alocat static) + v2(alocat dinamic)
	//alte 2 atribute la alegere
} s;

Student initializare(char nume[25], int note[10], int nrNote){
	//to do the job
}

//to do home
//1.de citit de la tastatura in student (in main)
//2. afisare student in main
//3. fct care primeste valori si init un student pe baza valorilor
//4. fct care primeste un student si il afiseaza
//5. un vector de siruri de caractere (lista prietenilor mei) (static / dinamic)
//6. fct care primeste matricea de la 5 si un nume, si returneaza tru sau false faca in gaseste pe nume in matrice
//7. alta structura la alegere + redo all

int main() {
	Student student;
	char s1[25];//sir caractere alocat static
	strcpy_s(s1,strlen("Anabela")+1, "Anabela");
	cout << s1;// << operator

	char* s2=nullptr;
	s2 = new char[strlen("Ana")+1];
	strcpy_s(s2, strlen("Ana") + 1, "Ana");
	cout << s2;
	delete[] s2;

	char* ps1;
	char* ps2;
	ps1 = new char[4];
	ps2 = new char[4];
	strcpy_s(ps2, 4, "Ana");
	//ps1 = ps2;//shallow copy
	strcpy_s(ps1, 4, ps2);
	cout << endl << ps1;
	cout << endl << ps2;
	delete[] ps1;
	ps1 = nullptr;
	delete[] ps2;
	ps2 = nullptr;

	cout << "\n-------Matrice----------";
	//statica
	int m[2][4];

	//dinamica
	int** pm;
	pm = new int* [2];
	for (int i = 0; i < 2; i++) {
		pm[i] = new int[4];
	}
	//to do pe pm
	for (int i = 0; i < 2; i++) {
		delete[] pm[i];
		pm[i] = nullptr;
	}
	delete[] pm;
	pm = nullptr;

	return 0;
}
