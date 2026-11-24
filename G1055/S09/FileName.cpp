#include <iostream>
using namespace std;

class Produs
{
	string denumire = "-";
	float pret = 0;
	int stoc = 0;

public:
	Produs()
	{

	}

	Produs(string _denumire, float _pret, int _stoc)
	{
		this->denumire = _denumire;
		this->pret = _pret;
		this->stoc = _stoc;
	}

	void afisare()
	{
		cout << "\nProdus " << this->denumire << ", pret " << this->pret << ", stoc " << this->stoc;
	}

	Produs& operator+=(int x)
	{
		this->stoc += x;
		return *this;
	}

	Produs& operator+= (float x)
	{
		this->pret += x;
		return *this;
	}

	bool operator>(const Produs& p) const
	{
		/*if (this->pret > p.pret)
			return true;
		return false;*/

		return this->pret > p.pret;
	}

	bool operator! () const
	{
		/*if (this->stoc == 0)
			return true;
		return false;*/

		return this->stoc == 0;
	}

	//forma pre incrementare
	Produs& operator++()
	{
		this->stoc++;
		return *this;//obj de dupa modificare
	}

	//forma post incrementare
	Produs operator++(int)//nu se poate transfera prin referinta pt ca obj copiei e o variabila locala si se va distruge
	{
		Produs copie = *this;
		this->stoc++;
		//this->operator++();
		return copie;//obj de dinainte modificarii
	}
};

int main()
{
	Produs p1;
	Produs p2("stilou", 450, 10);
	Produs p3 = p2;
	p1 = p2;
	p1.afisare();

	p1 += 10;//Produs += int -> p1.operator+=(10)
	p1.afisare();
	int a = 2, b = 5, c = 7;
	a = b += c;
	p1 = p2 += 10;

	p1 += 10.5f;//prima oara cauta conversie nedegradanta, iar daca nu gaseste aplica conversia degradanta
	p1.afisare();
	//p1+=10.5;- eroare de ambiguitate
	p1 += 'a';//conversie nedegradanta
	//p1+= "albastru";

	if (p1 > p2)//Produs > Produs
		cout << "\np1 este mai scump ca p2";
	else
		cout << "\np1 este mai ieftin ca p2";

	a = 10;
	if (!a)
		cout << "\nA";
	else
		cout << "\nB";

	if (!p1)
		cout << "\nNU exista p1 pe stoc";
	else
		cout << "\nExista p1 pe stoc";
	a = 2;
	b = 10;
	a = !b;
	cout << endl << a << " " << b;

	a = ++b;//returneaza valoarea de dupa incrementare
	a = b++;// returneaza valoarea de dinaintea incrementarii
	cout << "\n---------------------------Pre incrementare--------------------------";
	p1.afisare();
	p2.afisare();
	p2 = ++p1;
	p2.operator=(p1.operator++());
	p1.afisare();
	p2.afisare();
	cout << "\n------------------------Post incrementare----------------------------";
	p1.afisare();
	p2.afisare();
	p2 = p1++;
	p2.operator=(p1.operator++(2));
	p1.afisare();
	p2.afisare();
	cout << "\n---------------------------------------------------------------------";

	//p2=p1+10;
	//int rezultat;
	//rezultat=10+p1;
	//rezultat=10+p1;

	//rezultat=p1;
	//string denumire;
	//denumire=(string)p1;
	return 0;
}
