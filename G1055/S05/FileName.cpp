#include<iostream>
using namespace std;

class Student {
private:
	int id;
	string nume;//char* nume;
	int nrNote;
	int* note;

public:
	//----metode speciale----
	//1.metode tip constructor
	Student() {
		cout << "\nApel constructor fara param";
		id = 0;
		nume = "Anonim";
		nrNote = 0;
		note = nullptr;
	}

	Student(int _id, string _nume, int _nrNote, int* _note) {
		cout << "\nApel constructor cu toti param";
		this->id = _id;
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

	Student(int _id, string _nume) {
		cout << "\nApel constructor cu cativa param";
		this->id = _id;
		this->nume = _nume;
		this->nrNote = 0;
		this->note = nullptr;
	}

	Student(int _id) {
		this->id = _id;
		this->nume = "Anonim";
		this->nrNote = 0;
		this->note = nullptr;
	}

	//2.metode accesor

	//3.metode prelucrare
	void afisare() {
		cout << "\nStudentul " << nume;
		cout << ", are " << nrNote;
		cout << ", note: ";
		if (note != nullptr) {
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
	Student s;
	s.afisare();
	Student v[10];
	cout << "\n----";
	Student* ps;
	ps = new Student;
	delete ps;
	ps = nullptr;
	ps = new Student[10];
	delete[] ps;
	ps = nullptr;

	cout << "\n-----------constructor cu param----------";
	Student s2(12, "Gigel", 0, nullptr);
	s2.afisare();
	int* note = new int[3] {10, 9, 5};
	Student s3(13, "Costel", 3, note);
	delete[] note;
	note = nullptr;
	s3.afisare();
	Student s4(14, "Maria");
	s4.afisare();

	cout << "\n-----Constructor cu 1 param-----";
	Student s5(10);
	s5.afisare();
	Student s6();//s6 NU este obj de tip Student, NU se apeleaza constructor
	Student s7;
	s7.afisare();

	Student s8(13);
	Student s9[13];
	ps = new Student(3);
	ps = new Student[3];

	int x[2];
	int y(2);

	

	return 0;
}