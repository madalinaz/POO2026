#include <iostream>
using namespace std;

class Parcare
{
	string adresa = "-";
	const int capacitate;
	int nrOre = 0;
	int* locuriOcupate = nullptr;//pt fiecare ora monitorizata
	float tarifOra = 0;
	static int maxCapacitate;//aici doar am conectat variabila globala de clasa

public:
	Parcare(string _adresa, int _capacitate, int _nrOre, int* _locuriOcupate, float _tarifOra) :capacitate(_capacitate)
	{
		this->adresa = _adresa;
		if (_nrOre > 0 && _locuriOcupate != nullptr)
		{
			this->nrOre = _nrOre;
			this->locuriOcupate = new int[this->nrOre];
			for (int i = 0; i < this->nrOre; i++)
			{
				this->locuriOcupate[i] = _locuriOcupate[i];
			}
		}
		this->tarifOra = _tarifOra;
		if (this->capacitate > Parcare::maxCapacitate)
		{
			Parcare::maxCapacitate = capacitate;
		}
	}


	void afisare()
	{
		cout << "Adresa: " << adresa << endl;
		cout << "Capacitate: " << capacitate << endl;
		cout << "Numar ore: " << nrOre << endl;
		cout << "Locuri ocupate: ";
		for (int i = 0; i < nrOre; i++)
		{
			cout << locuriOcupate[i] << " ";
		}
		cout << endl;
		cout << "Tarif pe ora: " << tarifOra << endl;
	}

	/*Parcare(const Parcare& p):Parcare(p.adresa,p.capacitate, p.nrOre, p.locuriOcupate, p.tarifOra)
	{

	}*/

	Parcare(const Parcare& p) :capacitate(p.capacitate)
	{
		this->adresa = p.adresa;
		if (p.nrOre > 0 && p.locuriOcupate != nullptr)
		{
			this->nrOre = p.nrOre;
			this->locuriOcupate = new int[this->nrOre];
			for (int i = 0; i < this->nrOre; i++)
			{
				this->locuriOcupate[i] = p.locuriOcupate[i];
			}
		}
		this->tarifOra = p.tarifOra;
	}

	void operator=(const Parcare& p)
	{
		//to do 
	}

	void setLocuriOcupate(int _index, int _valoareNoua)
	{
		this->locuriOcupate[_index] = _valoareNoua;
	}

	static int getCapacitateMax()
	{
		return Parcare::maxCapacitate;
	}

	~Parcare()
	{
		delete[] this->locuriOcupate;
		this->locuriOcupate = nullptr;
	}
};

int Parcare::maxCapacitate = 0;

int main()
{
	int v[] = { 10,15,5,30 };
	Parcare p("Strada", 40, 4, v, 1);
	p.afisare();
	Parcare p2(p);//vom construi un obiect nou pe baza unui obiect existent
	Parcare p3 = p;
	int x = 3;
	int y(x);
	cout << endl;
	p2.afisare();

	//modalitate de a demonstra ca am implementat deep copy in constructori
	v[0] = 3;
	cout << endl << "------------------Demonstram ca am implementat deep copy-------------------------" << endl;
	p.afisare();
	p.setLocuriOcupate(0, 20);
	cout << endl;
	p.afisare();
	cout << endl;
	p2.afisare();
	cout << "-----------------------------------------------------------------------------------";

	//modalitate de a stoca parcarea cu cea mai mare capacitate
	cout << "\nCapacitatea maxima este: " << Parcare::getCapacitateMax();
	Parcare p4("-", 100, 0, nullptr, 5);
	cout << "\nCapacitatea maxima este: " << Parcare::getCapacitateMax();
	cout << endl;
	p4.afisare();

	//supraincarcarea operatorilor
	//specializarea operatorilor
	// p1=p2; -modifica obiectele deja existente
	//cout<<p2;
	//p2++;
	//p2+=10;
	//if (p1 > p2)
	//{
	//	cout<<"\np1 are capacitatea mai mare decat p2";
	//}
	//if (!p1)
	//{
	//	cout<<"\nNu exista locuri ocupate in ultima ora"
	//}

	int z;
	z = 2;//atribuire

	return 0;
}