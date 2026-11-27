#include<iostream>
using namespace std;

class Produs {
	string denumire="";
	int stoc=0;
	float pret=0.0f;

public:
	Produs(){ }

	Produs(string _denumire, int _stoc, float _pret) {
		this->denumire = _denumire;
		this->stoc = _stoc;
		this->pret = _pret;
	}

	void afisare() {
		cout << "\nDenumire: " << this->denumire
			<< ", stoc: " << this->stoc
			<< ", pret: " << this->pret;
	}
};

int main() {
//comparatii ==; <=
// ! (negatie)
// += / -=
// +
// ++ (pre si post)
// >> si <<
// []
// cast/conversie
//friend
}