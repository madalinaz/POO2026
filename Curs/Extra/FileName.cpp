#include<iostream>
using namespace std;

class Proiect {
	string denumire ="-";
	int nrMembri =0;
	int nrEtape =0;
	float* bugetEtape =nullptr;
	bool esteActiv = true;

public:
	Proiect(string _denumire){
		this->denumire = _denumire;
	}

	//home, se pastreaza doar etapele care au buget pozitiv
	//home 2, se inlocuiesc valorile negative cu media celor pozitive
	Proiect(string _denumire, int _nrMembri, int _nrEtape, float* _bugetEtape, bool _esteActiv) {
		this->denumire = _denumire;
		if (_nrMembri > 0) {
			this->nrMembri = _nrMembri;
		}
		if (_nrEtape > 0 && _bugetEtape != nullptr) {
			this->nrEtape = _nrEtape;
			this->bugetEtape = new float[this->nrEtape];
			for (int i = 0; i < this->nrEtape; i++) {
				if (_bugetEtape[i] < 0) {
					this->bugetEtape[i] = 1;//daca bugetul este negativ, se inlocuieste cu 1
				}
				else {
					this->bugetEtape[i] = _bugetEtape[i];
				}
			}
		}
		this->esteActiv = _esteActiv;
	}

	int getNrMembri() const{
		return this->nrMembri;
	}

	void setNrMembri(int _nrMembri) {
		if (_nrMembri > 0) {
			this->nrMembri = _nrMembri;
		}
	}

	float getTotalBuget() const{
		float total = 0;
		for (int i = 0; i < this->nrEtape; i++) {
			total += this->bugetEtape[i];
		}
		return total;
	}

	//la afisare trebuie bugetul total doar
	//const inseamna ca this NU trebuie sa se modifice in aceasta metoda
	void afisare() const{
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr membri: " << this->nrMembri;
		cout << "\nNr etape: " << this->nrEtape;
		cout << "\nTotal buget: " << this->getTotalBuget();
		cout << "\nEste activ?: " << this->esteActiv;
	}
};

void adaugaEtapa(float*& _bugetEtape, int& _nrEtape, float _bugetEtapaNoua) {
	if (_bugetEtapaNoua > 0) {
		float* aux = new float[_nrEtape + 1];
		for (int i = 0; i < _nrEtape; i++) {
			aux[i] = _bugetEtape[i];
		}
		aux[_nrEtape] = _bugetEtapaNoua;
		delete[] _bugetEtape;
		_bugetEtape = aux;
		_nrEtape++;
	}
	else {
		cout << "\nBugetul etapei este negativ, nu s-a adaugat!";
	}
}

int  main() {
	Proiect p1("Simur 3.0 Ase");
	p1.afisare();
	cout << endl << "\nNr membri proiect: " << p1.getNrMembri();
	p1.setNrMembri(-3);
	cout << endl << "\nNr membri proiect dupa set val negativa: " << p1.getNrMembri();
	p1.setNrMembri(3);
	cout << endl << "\nNr membri proiect dupa set care respecta validarea: " << p1.getNrMembri();
	float bugete[] = { 100,200,150 };
	Proiect p2("Proiect nou", 10, 3, bugete, true);
	p2.afisare();
	cout << endl << p2.getTotalBuget();
	float* bugete2 = new float[3];
	bugete2[0] = 100;
	bugete2[1] = 200;
	bugete2[2] = 300;
	int nrEtape = 3;
	adaugaEtapa(bugete2, nrEtape, -400);
	cout << endl << "\nNr etape: " << nrEtape;
	cout << endl << "\nBugete etape dupa adaugare: ";
	for (int i = 0; i < nrEtape; i++) {
		cout << bugete2[i] << " ";
	}
	return 0;
}