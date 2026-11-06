#include<iostream>
using namespace std;

//const si static
//functii globale

class Proiect {
	int id=0;
	string denumire="-";
	int nrEtape=0;
	float* bugetEtape=nullptr;

public:
	Proiect(int _id, string _denumire, int _nrEtape, float* _bugetEtape) {
		this->id = _id;
		this->denumire = _denumire;
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
};

int main() {
	Proiect p1(1,"Proiect",)
	return 0;
}