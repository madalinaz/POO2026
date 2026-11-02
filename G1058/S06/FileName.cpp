#include<iostream>
using namespace std;

class Personaj {
	string denumire="-";
	int nrArme = 0;
	string* listaArme = nullptr;

public:
	Personaj(string _denumire) {
		this->denumire = _denumire;
	}

	Personaj(string _denumire, int _nrArme, string* _listaArme):Personaj(_denumire) {
		for (int i = 0; i < _nrArme; i++) {
			this->adaugaArma(_listaArme[i]);
		}
	}

	void adaugaArma(string _arma) {
		for (int i = 0; i < this->nrArme; i++) {
			if (_arma == this->listaArme[i])
				return;
		}
		string* aux = new string[this->nrArme + 1];
		for (int i = 0; i < this->nrArme; i++) {
			aux[i] = this->listaArme[i];
		}
		aux[this->nrArme] = _arma;
		delete[] this->listaArme;
		this->listaArme = aux;
		this->nrArme++;
	}
};

enum TipCompanie {
	SA, SRL, PFA
};

class Companie {
	string denumireCompanie;
	int nrAngajati;
	float* salariuLunar;
	float salariuMaxim;
	float fondTotalSalarii;
	TipCompanie tipCompanie;

public:
	Companie(string _denumireCompanie, int _nrAngajati, float* _salariuLunar, float _salariuMaxim, float _fondTotalSalarii, TipCompanie _tipCompanie) {
		this->denumireCompanie = _denumireCompanie;
		if (_nrAngajati > 0 && _salariuLunar != nullptr) {
			this->nrAngajati = _nrAngajati;
			this->salariuLunar = new float[this->nrAngajati];
			for (int i = 0; i < this->nrAngajati; i++) {
				if (_salariuLunar[i] < 0) {
					_salariuLunar[i] *= -1;
				}
				if (_salariuLunar[i] >= _salariuMaxim) {
					_salariuLunar[i] = _salariuMaxim;
				}
				this->salariuLunar[i] = _salariuLunar[i];
			}
		}
		this->salariuMaxim = _salariuMaxim;
		this->fondTotalSalarii = _fondTotalSalarii;
		this->tipCompanie = _tipCompanie;
	}
	
	void setTipCompanie(TipCompanie _tipCompanie) {
		this->tipCompanie = _tipCompanie;
	}

	void afisare() {
		cout << "\nCompania " << this->denumireCompanie;
		cout << "\n are " << this->nrAngajati << " angajati, cu salariile: ";
		for (int i = 0; i < this->nrAngajati; i++)
			cout << this->salariuLunar[i] << " ";
		cout << ", salariu maxim: " << this->salariuMaxim;
		cout << ", fond salarii: " << this->fondTotalSalarii;
		cout << ", tip: " << this->tipCompanie;
	}
	int calculAngajatiMax() {
		float suma=0;
		for (int i = 0; i < nrAngajati; i++) {
			suma += salariuLunar[i];
		}
		return (fondTotalSalarii - suma) / salariuMaxim;

	}
};

void stergereAngajatMax(float*& v, int& dim) {
	float max=0;
	for (int i = 0; i < dim; i++)
		if (v[i] > max) max = v[i];
	int poz;
	for(int i=dim-1;i>=0;i--)
		if (v[i] == max) {
			poz = i;
			break;
		}
	float* aux = new float [dim-1];
	for (int i = 0; i < poz; i++) {
		aux[i] = v[i];
	}
	for (int i = poz + 1; i < dim; i++)
		aux[i-1] = v[i];
	delete[] v;
	v = aux;
	dim--;
}

int main() {
	float salarii[] = { 1300,900, -400, -1200 };
	Companie c1("ABC", 4, salarii, 1000, 10000, TipCompanie::SRL);
	c1.afisare();
	c1.setTipCompanie(TipCompanie::PFA);
	c1.afisare();
	cout<<endl<<c1.calculAngajatiMax();
	float* salarii2=new float [4];
	for (int i = 0; i < 4; i++) salarii2[i] = salarii[i];
	int a = 4;
	stergereAngajatMax(salarii2, a);
	cout << endl << "Vector dupa stergere: " << endl;
	for (int i = 0; i < a; i++)
		cout << salarii2[i] << " ";

	return 0;
}