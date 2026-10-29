#include<iostream>
using namespace std;

//HOME
//1. clasa Student cu char* nume si int note[100]
//2. alta clasa, alegeti si un camp enum 
//3. forme agregate de afisare( doar media notelor)

class Student {
private:
	string nume;
	int nrNote;
	int* note;


public:
	//metode tip constructor
	Student() {
		cout << "\nApel constr fara param";
		nume = "Anonim";
		nrNote = 0;
		note = nullptr;
	}

	Student(string _nume) {
		this->nume = _nume;
		this->nrNote = 0;
		this->note = nullptr;
	}

	Student(string _nume, int _nrNote, int* _note) {
		this->nume = _nume;
		if (_nrNote > 0 && _note != nullptr) {
			this->nrNote = _nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++) {
				this->note[i] = _note[i];
			}
		}
		else {
			this->nrNote = 0;
			this->note = nullptr;
		}
	}

	//metode accesor (get si set)

	//metode prelucrare
	void afisare() {
		cout << "\nStud " << nume << " are " << nrNote << " note: ";
		if (note!=nullptr) {
			for (int i = 0; i < nrNote; i++) {
				cout << note[i] << " ";
			}
		}
		else {
			cout << "-";
		}
	}
};

int main() {
	cout << "\n------------1------------";
	Student s;
	s.afisare();
	Student vs[5];
	Student* ps;
	ps = new Student;
	delete ps;
	ps = nullptr;
	ps = new Student[5];
	delete[] ps;
	ps = nullptr;

	cout << "\n------------2------------";
	Student s3;
	Student s4("Gigel", 0, nullptr);
	s4.afisare();
	int* note = new int[4] {10, 4, 6, 7};
	Student s5("Costel", 4, note);
	delete[] note;
	s5.afisare();
	//Student s6();


	return 0;
}