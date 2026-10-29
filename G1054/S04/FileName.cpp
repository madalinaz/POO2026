#include<iostream>
#include<string>
using namespace std;

//clasa + exemple alege atribute
//incapsulare ( metode accesor)
//constructor + situatii de apel + sizeof
//char -> string
//meth de prelucrare
//meth de afisare

struct Data {
	int zi;
	int luna;
	int an;
};

enum Disciplina{
	POO, BAZE_DE_DATE, MICROECONOMIE
};

//atribute + metode
class Proiect {
private:
	//int deadlineZi;
	//int deadlineLuna;
	//int deadlineAn;
	Data deadline;
	//char titlu[20];
	//char* titlu;
	string titlu;
	//char disciplina[20];
	Disciplina disciplina;
	int nrPuncte;
	//lista de cerinte
	//V1
	//char listaCerinte[200]; //"fara STL; cu alocare dinamica; fara memory leaks"
	//vector de siruri de caractere
	//V2
	//char listaCerinte[10][20];
	//int nrCerinte;
	
	//V3
	//char** listaCerinte;
	//int nrCerinte;
	
	//V4
	//string listaCerinte[10];//vector alocat static de siruri de caractere
	//int nrCerinte;

	string* listaCerinte;
	int nrCerinte;

	bool esteObligatoriu;

public:
	Proiect() {
		cout << "\nApel constructor fara param";
		//...
	}

	void afisare() {
		cout << "\nDeadline: ";
		cout << deadline.zi << "/" << deadline.luna << "/" << deadline.an;
		cout << "\nTitlu: " << titlu;
		cout << "\nDisciplina: " << disciplina;
		cout << "\nNr puncte: " << nrPuncte;
		cout << "\nNr cerinte: " << nrCerinte;
		for (int i = 0; i < nrCerinte; i++) {
			cout << "\nCerinta " << i + 1 << ": " << listaCerinte[i];
		}
		cout << "\nEste obligatoriu?: " << esteObligatoriu;
	}

	//metodelor accesor (get si set)
	string getTitlu() {
		return titlu;
	}

	void setTitlu(string titluNou) {
		if (titluNou.size() > 0) {
			titlu = titluNou;
		}
	}

	int getNrPuncte() {
		return nrPuncte;
	}

	void setNrPuncte(int nrPuncteNou) {
		if (nrPuncteNou > 0) {
			nrPuncte = nrPuncteNou;
		}
	}
};

int main() {
	Proiect p;
	string sir;
	sir = "Alb";
	cout << sir << endl;
	//cin >> sir;
	cout << endl << sir;
	sir += "-Negru";
	cout << endl << sir;
	p.afisare();
	cout << "\n--------------Meth accesor--------------";
	cout<<endl<<p.getNrPuncte();
	cout << endl << p.getTitlu();
	p.setTitlu("Tema 1 la POO din constructori");
	cout << endl<<p.getTitlu();

	cout << "\n------------Verificare incapsulare-------------";
	cout << endl << p.getTitlu();
	p.setTitlu("Titlu nou");
	cout << endl << p.getTitlu();
	string titlu = p.getTitlu();//DACA s-ar face un shallow copy
	cout << "\nTitlu prin variabila string: " << titlu;
	titlu = "Am schimbat titlul";
	cout << "\nTitlu prin variabila string dupa schimbare: " << titlu;
	cout << "\nTitlu prin meth get: " << p.getTitlu();

	cout << "\n------------Apel constructori-------------";
	//Proiect pr;
	//Proiect vp[10];
	//Proiect* ppr;
	//ppr = new Proiect();
	//Proiect** ppr2;
	//ppr2 = new Proiect * ();
	Proiect* vp2[10];
	return 0;
}