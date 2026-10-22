#include<iostream>
#include<string>
using namespace std;

//TO DO
//struct -> class
//domenii de vizibilitate
//incapsulare + meth de evidentiat
//fct globale / fct statice
//string

//TO DO HOME
//1. Alegeti o alta clasa (dar care sa contina si un camp de tipul sir de caractere alocat static ( char ceva[100]) si o enumeratie

//public
struct Stud {
	//char* nume;
	//char nume[25];
	string nume;
	int anStudiu;
	int nrPctCredit;
};

enum Facultate {
	CSIE, MK, MN, DREPT
};

//implicit private
class Student {
private:
	string nume; //sir de caractere de lg intre [10,100]
	int anStudiu; //[1,4]
	int nrPctCredit; //[0,240]
	float soldDisponibil; //reala [0,...)
	//Facultate facultate;

public:
	//metode -> comportamentul unui obj de tipul clasei
	//metoda = fct non-statica a unei clase

	//metode accesor (get si set)
	float getSoldDisponibil() {
		return soldDisponibil;
	}

	void setSoldDisponibil(float soldNou) {
		if (soldNou >= 0) {
			soldDisponibil = soldNou;
		}
	}

	string getNume() {
		return nume;
	}

	int getAnStudiu() {
		return anStudiu;
	}

	int getNrPctCredit() {
		return nrPctCredit;
	}

	void alimentareCont(float soldSuplimentar) {
		if (soldSuplimentar > 0) {
			soldDisponibil += soldSuplimentar;
		}
	}

	void init() {
		nume = "-";
		anStudiu = 1;
		nrPctCredit = 0;
		soldDisponibil = 0;
	}

	//metoda a clasei
	//metoda care se apeleaza plecand de la un obj al clasei
	void afisare() {
		cout << "\n**************************";
		cout << "\nNume: " << nume;
		cout << "\nAn studiu: " << anStudiu;
		cout << "\nNr pct credit: " << nrPctCredit;
		cout << "\nSold disponibil: " << soldDisponibil;
		cout << "\n**************************";
	}
};

//fct globala
void afisareStudent(Student s) {
	cout << "\n***********Afis stud fct globala************";
	cout << "\nNume: " << s.getNume();
	cout << "\nAn studiu: " << s.getAnStudiu();
	cout << "\nNr pct credit: " << s.getNrPctCredit();
	cout << "\nSold disponibil: " << s.getSoldDisponibil();
	cout << "\n**************************";
}

float getSoldMaxim(Student s1, Student s2) {
	//sa se returneze cel mai mare sold din cei 2 studenti
	return 0;
}

int countStudenti(Student v[], int n, int anStudiu) {
	//returneaza nr de studenti din anul de studiu anStudiu primit ca param
	return 0;
}

void afisareStudenti(Student v[100], int n, int anStudiu) {
	//afiseaza numele tuturor studentilor din anul de studiu anStudiu primit ca param
}

void fctGlobala() {

}

int main() {
	Stud s;
	// cin >> s.nrPctCredit;
	//cout << s.nrPctCredit;
	Student st; //st este obiect iar Student este clasa //declarat un obj de tipul Student
	st.afisare();
	int x;

	cout << "\n--------------String-------------------";
	string sir;
	for (int i = 0; i < 100; i++) {
		sir += "A";
	}
	cout << endl << sir;
	cout << endl<<sizeof(sir);
	sir = "ABC";
	cout << endl << sir;
	cout << endl << sizeof(sir);
	cout << endl << sir.length();

	cout << "\n--------------Meth accesor-------------------";
	cout<<endl<<st.getSoldDisponibil();
	st.setSoldDisponibil(100);
	cout << endl << st.getSoldDisponibil();
	st.setSoldDisponibil(-200);
	cout << endl << st.getSoldDisponibil();
	st.alimentareCont(50);
	cout << endl << st.getSoldDisponibil();
	Student st2;
	st2.init();
	st2.alimentareCont(500);
	cout << endl << st2.getSoldDisponibil();
	st2.afisare();

	cout << "\n--------------Fct globale-------------------";
	afisareStudent(st2);

	//totul este in sectiune non-statica, toate metode sunt apelate prin intermediul unui obj de tipul clasei
	return 0;
}