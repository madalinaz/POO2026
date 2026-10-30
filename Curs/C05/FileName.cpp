#include<iostream>
using namespace std;

class Student {
	const int id;
	string nume;

public:
	/*Student(int _id=0, string _nume="Anonim") {
		this->id = _id;
		this->nume = _nume;
	}*/

	Student(int _id, string _nume):id(_id) {
		//this->id = _id;//aici este atribuire
		if (_nume.size() <= 5) {
			this->nume = "Anonim";
		}
		else {
			this->nume = _nume;
		}
	}

	Student(int _id):id(_id) {
		//this->id = _id;
		this->nume = "Anonim";
	}

	Student():id(0) {
		this->nume = "Anonim";
	}
};

class Masina {
	const int id;
	string model="-";
	int anFabricatie=1900;
	float* deplasari=nullptr;
	int nrDeplasari=0;

public:
	Masina(int _id, string _model, int _anFabricatie, float* _deplasari, int _nrDeplasari):id(_id){
		if (_model.size() >= 3) {
			this->model = _model;
		}
		if (_anFabricatie >= 1900 && _anFabricatie <= 2026) {
			this->anFabricatie = _anFabricatie;
		}
		if (_deplasari != nullptr && _nrDeplasari > 0) {
			this->nrDeplasari = _nrDeplasari;
			this->deplasari = new float[this->nrDeplasari];
			for (int i = 0; i < this->nrDeplasari; i++) {
				this->deplasari[i] = _deplasari[i];
			}
		}
	}
};

int main() {
	//o colectie de studenti
	//Student v[10];
	//Student s(12);
	Student* vp[10];
	//vp[0] = new Student(12);
	Student s2(134, "Maria");

	const int x=8;
	int s;
	s = 0;

	Student s3(12);
	Student s4 = 12;

	cout << "\n------const si static------";
	return 0;
}