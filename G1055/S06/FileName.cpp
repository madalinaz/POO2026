#include<iostream>
using namespace std;

//HOME
//1. Clasa, dar in versiune statica pentru listaArme
// string listaArme[20];

class Personaj {
	int nivelViata = 100;
	string* listaArme = nullptr;
	int nrArme = 0;

public:
	//daca arma este goala, atunci NU se introduce
	Personaj(string* _listaArme, int _nrArme) {
		if (_listaArme != nullptr && _nrArme > 0) {
			int contor = 0;
			for (int i = 0; i < _nrArme; i++) {
				if (_listaArme[i].size() > 0) {
					contor++;
				}
			}
			this->nrArme = contor;
			this->listaArme = new string[this->nrArme];
			int k = 0;
			for (int i = 0; i < _nrArme; i++) {
				if (_listaArme[i].size() > 0) {
					this->listaArme[k++] = _listaArme[i];
				}
			}
		}
	}

	void afisare() const{
		//compacta, pe o singura linie
		cout << "\nPersonaj, nivel viata " << this->nivelViata;
		cout << ", are " << this->nrArme << " arme: ";
		for (int i = 0; i < this->nrArme; i++) {
			cout << this->listaArme[i] << " ";
		}
	}

	//metoda care intoarce o arma de pe o anume pozitie
	//return prin valoare
	string getArma(int _index) const{
		if (_index >= 0 && _index < this->nrArme) {
			return this->listaArme[_index];
		}
	}

	//metoda care adauga o noua arma doar daca personajul nu o are deja
	void adaugaArma(string _armaNoua) {
		for (int i = 0; i < this->nrArme; i++)
		{
			if (this->listaArme[i] == _armaNoua)
			{
				return;
			}

		}
		string* aux = new string[this->nrArme + 1];
		for (int i = 0; i < this->nrArme; i++)
			aux[i] = this->listaArme[i];
		aux[this->nrArme] = _armaNoua;
		delete[] this->listaArme;
		this->listaArme = aux;
		this->nrArme++;

	}

	//metoda care returneaza lista de arme
	string* getArme() {
		//return this->listaArme;
		//returnam o copie a listei de arme
		string* aux = new string[this->nrArme];
		for (int i = 0; i < this->nrArme; i++) {
			aux[i] = this->listaArme[i];
		}
		return aux;
	}

};

int main() {
	string listaArme[] = { "pistol","sabie","","pusca" };
	Personaj p1(listaArme, 4);
	p1.afisare();
	cout << p1.getArma(0);
	p1.getArma(0) = "portocala";
	p1.afisare();
	p1.adaugaArma("ArmaNoua");
	p1.afisare();
	string* arme = p1.getArme();
	for (int i = 0; i < 4; i++) {
		cout << endl << arme[i];
	}
	//verificare proprietate incapsulare
	arme[0] = "banana";
	p1.afisare();
	
	return 0;
}