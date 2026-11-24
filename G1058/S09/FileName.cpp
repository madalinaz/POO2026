#include <iostream>
using namespace std;
class Produs { //nu avem nimic alocat dinamic, nu avem nevoie de destructor
	string denumire = "-";
	float pret = 0;
	int stoc = 0;
public:
	Produs(string _denumire, float _pret, int _stoc)
	{
		this->denumire = _denumire;
		this->pret = _pret;
		this->stoc = _stoc;
	}
	Produs() {

	}
	void afisare() {
		cout << "\n Denumire: " << this->denumire;
		cout << "\n Pret: " << this->pret;
		cout << "\n Stoc: " << this->stoc;

	}

	Produs& operator+=(int x) {//ca sa nu facem copie returnam prin referinta(&)
		this->stoc += x;
		return *this; //this este un pointer, il dereferentiem
	}

	Produs& operator-=(float x) {
		this->pret -= x;
		return *this;
	}

	Produs& operator-=(int x) {
		this->stoc -= 10;
		/*this->Produs::operator+=(-x);
		this->operator+=(-x);
		(*this) += -x;*/ //toate 3 fac acelasi lucru
		return *this;
	}

	bool operator==(const Produs& p) const {
		return this->stoc == p.stoc;
	}

	bool operator!() const {
		return this->stoc == 0;
	}

	//forma de pre-incrementare,e mai optimizata,nu face copie
	Produs& operator++() {
		this->stoc++;
		return *this;//return obj de dupa modificare
	}

	//forma de post-incrementare
	//conventie-> primeste ca variabila un int
	Produs operator++(int) { //nu prin referinta(&), ptc distruge din obiect, in general daca stim ca distruge din obiect, nu &
		Produs copie = *this;
		this->stoc++;
		return copie;//return obiect de dinaintea modificarii
	}
};
int main() {
	Produs p1("pix", 100, 15);
	Produs p2;
	Produs p3(p1);
	p3.afisare();
	p2 = p3;
	p2.afisare();
	//sa se verifice ca prin atribuire NU depind de un obiect ulterior eliberat
	{
		Produs p4("penar", 50, 10);
		p2 = p4;
	}
	p2.afisare();
	//metoda 2
	Produs* ps = new Produs("guma", 10, 5);
	p2 = *ps;
	p2.afisare();
	delete ps;
	p2.afisare();

	p2 += 10; //Produs += int
	p2.operator+=(10);
	p2.afisare();
	int a = 5, b = 12, c = 1;
	a = b += c;
	p1 = p2 += 10;
	p2.afisare();
	p1.afisare();
	//int rez = p2 += 10;
	//p1 = p2 += p3; nu are sens
	p2 -= 5.2f;
	p2.afisare();
	p2 -= 10;//scade stocul cu 10 unitati
	p2.afisare();
	if (p2 == p1) {
		cout << "\Produsele au acelasi stoc";
	}
	else {
		cout << "\n altceva";
	}

	if (!p2) {
		cout << "\p2 NU este in stoc";

	}
	else {
		cout << "\n altceva";
	}

	a = 10;
	b = 2;
	a = !b;
	if (!a) {
		cout << "\nA";
	}
	else {
		cout << "\nB";
	}

	p2 = ++p1;//mareste cu 1 stocul
	p1.afisare();
	p2.afisare();
	p2.operator=(p1.operator++());

	p2 = p1++;
	p1.afisare();
	p2.afisare();
	//p1++;
	/*float rezultat;
	rezultat = p2 + 10;
	rezultat = p2;
	string denumire = (string)p2;*/

	return 0;
}