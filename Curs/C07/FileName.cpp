#include<iostream>
using namespace std;

//TO DO
//const id generat pe baza unui static
//destructor
//constructor de copiere
//operator =

class Produs {
	const int id;
	char* denumire;
	//o lista statica de id-uri consumate
	//static int generatorId;
	static int nrProduse;


public:
	Produs(string _denumire):id(++nrProduse) {
		this->denumire = new char[_denumire.length() + 1];
		strcpy_s(this->denumire,_denumire.length()+1, _denumire.data());
	}

	//constructor de copiere
	Produs(const Produs& p) :id(++nrProduse) {
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
	}

	Produs() :id(++nrProduse) {
		this->denumire = nullptr;
	}

	char* getDenumire() {
		/*return this->denumire;*/
		char* copie = new char[strlen(this->denumire) + 1];
		strcpy_s(copie, strlen(this->denumire) + 1, this->denumire);
		return copie;
	}

	void setDenumire(char* _denumire) {
		//obj this exista, poate are denumire
		delete[] this->denumire;
		this->denumire = new char[strlen(_denumire) + 1];
		strcpy_s(this->denumire, strlen(_denumire) + 1, _denumire);
	}

	void afisare() {
		cout << "\nProdus: " << this->denumire;
		cout << "\nId: " << this->id;

	}

	//destructor
	~Produs() {
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			//TO DO ( de ce sa mai pun pe nullptr daca tot distrug obiectul???)
			this->denumire = nullptr;
		}
	}
};

//int Produs::generatorId = 1000;
int Produs::nrProduse = 0;

int main() {
	Produs p1("stilou");
	Produs p2("Pix");
	p1.afisare();
	p2.afisare();
	{
		Produs p3("altul");
	}
	Produs* ps = new Produs("radiera");
	delete ps;
	Produs ps2[5];

	Produs p4 = p2;//copiaza in context de sizeof
	p2.afisare();
	p4.afisare();
	Produs p5(p2);
	//meth accesor pentru denumire
	
	char* interceptareSir = p5.getDenumire();
	cout << interceptareSir;
	interceptareSir[0] = 'x';
	p5.afisare();
	delete[] interceptareSir;
	return 0;
}