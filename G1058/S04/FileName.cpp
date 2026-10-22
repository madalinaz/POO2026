#include<iostream>
#include<string>
using namespace std;
//TO DO
//struct -> class
//domenii de vizibilitate
//incapsulare + meth de evidentiat
//fct globale / fct statice
//string

//public
struct Stud {
	//char* nume;
	//char nume[25];
	string nume;
	int anStudiu;
	int nrPctCredit;
};

//implicit private
class Student {
private:
	string nume;
	int anStudiu;
	int nrPctCredit;
	float soldDisponibil;

public:
	//metode -> comportamentul unui obj de tipul clasei
	//metoda = fct non-statica a unei clase
	void afisare() {
		cout << "\nS-a afisat un obj de tipul Student";
	}

	//metode accesor (get si set)
	float getSoldDisponibil() {
		return soldDisponibil;
	}
};

int main() {
	Stud s;
	// cin >> s.nrPctCredit;
	//cout << s.nrPctCredit;
	Student st; //st este obiect iar Student este clasa //declarat un obj de tipul Student
	st.afisare();
	int x;

	cout << "\n--------------String-------------------";
	string sir;
	for (int i = 0; i < 100; i++) {
		sir += "A";
	}
	cout << endl << sir;
	cout << endl<<sizeof(sir);
	sir = "ABC";
	cout << endl << sir;
	cout << endl << sizeof(sir);
	cout << endl << sir.length();

	cout << "\n--------------Meth accesor-------------------";
	st.getSoldDisponibil();
	return 0;
}