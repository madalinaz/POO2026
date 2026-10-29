#include<iostream>
using namespace std;

struct StudentStruct {
	char nume[20];
	int anStudiu;
};

class Student {
private: //conceptul de incapsulare
	//caracteristici ->atribute
	int id; //4
	char nume[20]; //20
	int anStudiu; //4
	int* note; //8
	int nrNote; //4

public: //pentru ca comportamentele sa poata fi expuse si utilizate in exterior
	//comportamente ->metode
	void afisare() {

	}

	//metode speciale (metode accesor)
	//get si set
	int getAnStudiu() {
		return anStudiu;
	}

	void setAnStudiu(int anStudiuNou) {
		if (anStudiuNou >= 1 && anStudiuNou <= 4) {
			anStudiu = anStudiuNou;
		}
	}

	//metode tip constructor (alocare zm + initializare)
	Student() {
		id = 0;
		strcpy_s(nume, strlen("Anonim")+1,"Anonim");
		anStudiu = 1;
		note = nullptr;
		nrNote = 0;
	}

	//implementarea curenta este fara validari, vom completa in urmatoarele cursuri
	Student(int id, const char nume[20], int anStudiu, int* note, int nrNote) {
		//this->adresa obj curent (este un pointer)
		this->id = id;
		strcpy_s(this->nume, strlen(nume) + 1, nume);
		this->anStudiu = anStudiu;
		this->nrNote = nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++) {
			this->note[i] = note[i];
		}
	}
};

//TO DO pentru vineri(30.10)
//get si set "corect" pentru char* si int*
//alte forme de constructori
//meth de prelucrare
//lista de initializatori
//depanare cu pointer this
//const si static

//class Grupa {
//	int nrGrupa;
//	Student v[30];
//	int nrStudenti;
//};

int main() {
	StudentStruct st;
	st.nume;
	Student s;
	cout<<endl<<s.getAnStudiu();
	s.setAnStudiu(-2);
	cout << endl << s.getAnStudiu();
	s.setAnStudiu(2);
	cout << endl << s.getAnStudiu();
	int note[] = { 10,4,5 };
	//Student(int id, char nume[20], int anStudiu, int* note, int nrNote)
	//Student(int id, const char nume[20], int anStudiu, int* note, int nrNote)
	char nume[] = "Gigel";
	Student s2(12, nume, 3, note, 3);
	Student s2(12, "Gigel", 3, note, 3);


	/*
	Student s1;
	Student s2("Gigel", 2);
	Student s3(s2);
	s2.setNume("Costel");
	cout << s2.getNume();
	s1.afisare();
	s1.adaugaNota(5);
	cout << s1.getMedie();

	s1 = s2;
	cout << 3;
	cout << s1;
	s1 += 10;
	cin >> s1;
	if (s2 >= s3) {
		cout << "\nS2 are o medie mai mare ca s3";
	}
	Student vs[10];
	Grupa grupa;
	cout << grupa;

	//lucrul cu fisiere text + binare
	//mostenire
	StudentBursier stB;
	//virtualizare
	//clase template
	//STL
	//vector<int> note;
	*/

	return 0;
}