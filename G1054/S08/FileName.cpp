#include<iostream>
using namespace std;

class Produs {
	string denumire="-";
	float pret=0;
	int stoc=0;

public:
	Produs(string _denumire, float _pret, int _stoc) {
		this->denumire = _denumire;
		if (_pret > 0) {
			this->pret = _pret;
		}
		if (_stoc > 0) {
			this->stoc = _stoc;
		}
	}

	Produs() {

	}

	void afisare() {
		cout << "\nProdus " << this->denumire << ", pret " << this->pret << ", stoc " << this->stoc;
	}

	bool operator>(int x) const{
		/*if (this->pret > x) {
			return true;
		}
		else {
			return false;
		}*/
		return this->pret > x;
	}
	

	Produs& operator+=(int x) {
		this->stoc += x; // modific stocul
		return *this;
	}
	
	Produs& operator+=(const Produs& p) {
		//this->stoc += p.stoc;
		//this->operator+=(p.stoc);
		*this += p.stoc;
		return *this;
	}

	//forma de preincrementare
	Produs& operator++() {
		this->stoc++;
		return *this;
	}

	//forma de postincrementare
	Produs operator++(int) {
		Produs copie = *this;
		this->stoc++;
		return copie;
	}

	bool operator!() const{
		return this->stoc == 0;
	}
};

int main() {
	Produs p1("stilou", 450, 10);
	p1.afisare();
	Produs p2 = p1;
	p2.afisare();
	Produs p3;
	p3 = p2;
	p3.afisare();

	p1 = p3 = p2;
	p1.afisare();

	if (p1 > 10) {
		cout << "\nPretul este mai mare ca 10";
	}
	else {
		cout << "\nAltceva";
	}
	// o sa aduag 5 la stoc 
	p1 += 5; 
	p1.afisare();

	p1 = p2 += 10;
	p1 += p2 += 10;// Produs += Produs

	p1.afisare();
	++p1;//se adauga o unitate la stoc
	p1.afisare();
	cout << "\n-----------++--------";
	p2 = ++p1;//voidul nu se poate combina
	p2.afisare();
	p1.afisare();
	p2 = p1++;
	p2.afisare();
	p1.afisare();

	//float pret = p1;
	//int stoc = (int)p1;
	
	//p1 = p2 + 10;


	//int x = 2, y = 10;
	//x = !y; //x = false => x=0
	//if(!y)
	//	cout<<"\ndaca y NU exista (adica daca este zero)"

	if (!p1) {
		cout << "\nCeva";
	}
	else {
		cout << "\nAltceva";
	}
	return 0;
}
