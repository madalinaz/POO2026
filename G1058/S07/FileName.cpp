#include <iostream>
using namespace std;

class Cititor {
	string nume="-";
	int nrImprumuturi=0;
	int* zileImprumut = nullptr;
	float penalizareZi=0;
	static int zileGratuite;
public:
	Cititor(string _nume, int _nrImprumuturi, int* _zileImprumut, float _penalizareZi) {
		this->nume = _nume;
		if (_nrImprumuturi > 0 && _zileImprumut != nullptr) {
			this->nrImprumuturi = _nrImprumuturi;
			this->zileImprumut = new int[_nrImprumuturi];
			for (int i = 0; i < this->nrImprumuturi; i++)
				this->zileImprumut[i] = _zileImprumut[i];
		}
		this->penalizareZi = _penalizareZi;
	}

	void setZileImprumut(int _nrImprumuturi, int* _zileImprumut) {
		if (this->zileImprumut != nullptr) {
			delete[] this->zileImprumut;
			this->zileImprumut = nullptr;
		}
		if (_nrImprumuturi > 0 && _zileImprumut != nullptr) {
			this->nrImprumuturi = _nrImprumuturi;
			this->zileImprumut = new int[_nrImprumuturi];
			for (int i = 0; i < this->nrImprumuturi; i++)
				this->zileImprumut[i] = _zileImprumut[i];
		}
		else {
			this->nrImprumuturi = 0;
			this->zileImprumut = nullptr;
		}
	}

	void setZileImp(int zileNoi[], int dim)
	{
		delete[] this->zileImprumut;
		this->zileImprumut = new int[dim];
		for (int i = 0; i < dim; i++)
			this->zileImprumut[i] = zileNoi[i];
		this->nrImprumuturi = dim;

		  
	}
	void afisare() {
		cout << "\n Nume: " << this->nume;
		cout << "\n Nr imprumuturi: " << this->nrImprumuturi;
		cout << "\n Zile imprumut: ";
		for (int i = 0; i < this->nrImprumuturi; i++) {
			cout << this->zileImprumut[i] << " ";
		}
		cout << "\n Penalizare: " << this->penalizareZi;
	}

	~Cititor() {
		if (this->zileImprumut != nullptr) {
			delete[] this->zileImprumut;
			this->zileImprumut = nullptr;
			
		}
	}

	Cititor(const Cititor& c)
		:Cititor(c.nume,c.nrImprumuturi,c.zileImprumut
			,c.penalizareZi) {

	}

	/*Cititor(const Cititor& c) {
		this->nume = c.nume;
		if (c.nrImprumuturi > 0 && c.zileImprumut != nullptr) {
			this->nrImprumuturi = c.nrImprumuturi;
			this->zileImprumut = new int[c.nrImprumuturi];
			for (int i = 0; i < this->nrImprumuturi; i++)
				this->zileImprumut[i] = c.zileImprumut[i];
		}
		this->penalizareZi = c.penalizareZi;
	}*/
};
int Cititor::zileGratuite = 10;

int main() {
	int zileimp[] = { 7, 14, 9, 5, 2 };
	Cititor c1("ABC", 5, zileimp, 10);
	c1.afisare();
	zileimp[0] = 1234;
	c1.afisare();
	{
		Cititor c2("ABC", 5, zileimp, 10);
	}
	Cititor* pc;
	//pc = &c1;
	pc= new Cititor("ABC", 5, zileimp, 10);
	delete pc;
	Cititor c3 = c1;
	Cititor c4("abc", -2, zileimp, 5);
	Cititor c5("def", 5, nullptr, 9);
	Cititor c6(c5);
	c6.afisare();
	int zileNoi[] = { 1,2,3,4,5,6 };
	int dim=6;
	//modalitate de a modifica vectorul si dimensiunea sa
	c5.setZileImp(zileNoi, dim);

	c5.afisare();

	//propuneti o modalitate de a verifica daca copierea facuta este superficiala sau nu
	return 0;
	
}