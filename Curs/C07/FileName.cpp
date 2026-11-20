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
		cout << "\nApel copy constructor";
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

	Produs& operator=(const Produs& p) {
		cout << "\noperator=";
		if (this != &p) {
			//destructor + constructor de copiere
			if (this->denumire != nullptr) {
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy_s(this->denumire, strlen(p.denumire) + 1, p.denumire);
		}
		return *this;
	}

	bool operator== (const Produs & p) const{
		if (strcmp(this->denumire, p.denumire) == 0)
			return true;
		return false;
	}

	//destructor
	~Produs() {
		cout << "\nApel destructor";
		if (this->denumire != nullptr) {
			delete[] this->denumire;
			//TO DO ( de ce sa mai pun pe nullptr daca tot distrug obiectul???)
			this->denumire = nullptr;
		}
	}
};

Produs functie(Produs p) {
	return p;
}

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

	cout << "\n--------------- = ------------------";
	Produs p6 = p2;
	p2 = p1; //specializare operator de atribuire
	p2.operator=(p1);
	p2.afisare();
	p1.afisare();
	p1 = p1;//auto-asignare
	p1.afisare();
	p1 = p2 = p1;
	cout << "\n--------------- = ------------------";
	//cout << p2 = p1;
	int a=3, b=2, c=0;
	a = b + c;
	//cout << a = b; DE CE?
	a += b = c; //apel in compunere
	a = b = c;//apel in cascada
	//a.operator=(b.operator=(c));
	//p1. se identifica tipul operatorului (binar)
	//p2. se identifica tipul operanzilor (Produs = Produs)
	//p3. daca primul operand este de tipul clasei, atunci supraincarcarea op se poate face in clasa; daca nu, atunci obligatoriu in afara clasei (this=Produs)
	//p4. ce intoarce operatorul? (void/Produs)
	//p5. ce obiecte se modifica?(I operand)

	cout << "\n------------- A -----------------";
	p1 = p2;
	cout << "\n------------- A -----------------";

	cout << "\n------------- B -----------------";
	Produs p10 = p5;
	cout << "\n------------- C -----------------";
	p10 = functie(p5);
	cout << "\n------------- C -----------------";
	Produs p12 = functie(p5);//copy elision
	cout << "\n------------- D -----------------";
	if (p1 == p2) {
		cout << "\nObj au nume =";
	}
	else {
		cout << "\nInvers";
	}

	return 0;
}