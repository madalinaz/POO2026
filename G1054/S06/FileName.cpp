#include<iostream>
using namespace std;
class Angajat {
	string nume = "anonim";
	int nrLuni = 0;
	int* oreLucrate = nullptr;
	int nrMinimOreLucrate = 0;
	double tarifOraSuplimentara = 0;
	double salariuBaza = 0;

public:

	Angajat(string _nume, int _nrLuni, int* _oreLucrate, int _nrMinimOreLucrate, double _tarifOraSuplimentara, double _salariuBaza) {
		this->nume = _nume;
		this->salariuBaza = _salariuBaza;
		if (_nrLuni > 0 && _oreLucrate != nullptr) {
			this->nrLuni = _nrLuni;
			this->oreLucrate = new int[this->nrLuni];
			this->tarifOraSuplimentara = _tarifOraSuplimentara;
			this->salariuBaza = _salariuBaza;
			for (int i = 0; i < this->nrLuni; i++) {
				if (_oreLucrate[i] >= this->nrMinimOreLucrate && _oreLucrate[i] <= 360) {
					this->oreLucrate[i] = _oreLucrate[i];
				}
				else {
					if (i == 0) {
						this->oreLucrate[i] = this->nrMinimOreLucrate;
					}
					else {
						int minim = this->oreLucrate[0];
						for (int j = 0; j < i; j++) {
							if (this->oreLucrate[j] < minim)
								minim = this->oreLucrate[j];
						}
						this->oreLucrate[i] = minim;
					}

				}
			}


		}
	}

	void afisare() {
		cout << "\nNume: " << this->nume << " ";
		cout << "\nNr.Luni: " << this->nrLuni << " ";
		cout << "\nOre Lucrate: ";
		for (int i = 0; i < this->nrLuni; i++) {
			cout << this->oreLucrate[i] << " ";
		}
		cout << "\nNr. min ore lucrate: " << this->nrMinimOreLucrate;
		cout << "\nTarif: " << this->tarifOraSuplimentara;
		cout << "\nSalariu de Baza: " << this->salariuBaza;
	}

	int getSalariuSuplimentar() const {
		int oreSuplimentare = 0;
		double salariuSuplimentar = 0;
		for (int i = 0; i < this->nrLuni; i++) {
			oreSuplimentare += this->oreLucrate[i] - this->nrMinimOreLucrate;
		}
		salariuSuplimentar = oreSuplimentare * this->tarifOraSuplimentara;
		return salariuSuplimentar;
	}

	void adaugareKLuni(int k) {
		int* aux = new int[this->nrLuni + k];
		for (int i = 0; i < this->nrLuni; i++) {
			aux[i] = this->oreLucrate[i];
		}
		for (int i = this->nrLuni; i < this->nrLuni + k; i++) {
			aux[i] = this->nrMinimOreLucrate;
		}
		delete[] this->oreLucrate;
		this->oreLucrate = aux;
		this->nrLuni += k;
	}
};

int main()
{
	int ore[] = { 150, 130,160,400 };
	Angajat a1("Andrei", 4, ore, 100, 10, 2000);
	a1.afisare();
	cout << endl;
	cout << a1.getSalariuSuplimentar();
	cout << endl;
	a1.adaugareKLuni(2);
	a1.afisare();
	return 0;
}