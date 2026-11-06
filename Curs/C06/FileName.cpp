#include<iostream>
using namespace std;

//const si static
//functii globale

class Proiect {
	const int id;
	const string denumire;
	int nrEtape=0;
	float* bugetEtape=nullptr;
	static string numeCompanie;//link

public:
	Proiect() :id(0),denumire(""){

	}

	Proiect(int _id, string _denumire, int _nrEtape, float* _bugetEtape):id(_id), denumire(_denumire) {
		if (_nrEtape > 0 && _bugetEtape != nullptr) {
			this->nrEtape = _nrEtape;
			this->bugetEtape = new float[this->nrEtape];
			for (int i = 0; i < this->nrEtape; i++) {
				this->bugetEtape[i] = _bugetEtape[i];
			}
		}
	}

	void afisare() {
		cout << "\nId: " << this->id;
		cout << "\nDenumire: " << this->denumire;
		cout << "\nNr etape: " << this->nrEtape;
		cout << "\nBuget etape: ";
		for (int i = 0; i < this->nrEtape; i++) {
			cout << this->bugetEtape[i] << " ";
		}
	}

	static string getNumeCompanie() {
		return Proiect::numeCompanie;
	}

	static void setNumeCompanie(string _numeCompanie) {
		Proiect::numeCompanie = _numeCompanie;
	}

	float getTotalBuget() const{
		float total = 0;
		for (int i = 0; i < this->nrEtape; i++) {
			total += this->bugetEtape[i];
		}
		return total;
	}

	string getDenumire()const {
		return this->denumire;
	}
};

string getDenumireProiectBugetMaxim(Proiect v[], int  n) {
	float bugetMax = 0;
	string denumireMax;
	for (int i = 0; i < n; i++) {
		if (v[i].getTotalBuget() > bugetMax) {
			bugetMax = v[i].getTotalBuget();
			denumireMax = v[i].getDenumire();
		}
	}
	return denumireMax;
}

//declarare variabila globala de tip static in clasa
string Proiect::numeCompanie = "ABC";

//declarare variabila globala
int n = 10;

int main() {
	
	float* bugete = new float[5];
	for (int i = 0; i < 5; i++) {
		bugete[i] = 1000 + i * 100;
	}
	Proiect p1(1, "Proiect", 5, bugete);
	p1.afisare();
	delete[] bugete;
	p1.afisare();

	cout << endl<<Proiect::getNumeCompanie();
	cout << endl << getDenumireProiectBugetMaxim(nullptr, 0);
	return 0;
}