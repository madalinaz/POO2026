#include<iostream>
using namespace std;

int suma(int* v, int n) { //vector + dimensiunea 
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
	}
	return s;
}

void suma(int* v, int n, int& s) { //vector + dimensiunea , parametri, numarul si tipul lor- asa SE DIFERENTIAZA DOUA FUNCTII, prin SIGNATURA, transfer prin referinta int& s
	s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
	}
}


//se modificia prin realocare adresa
void eliminare(int*& v, int& n) { //n se momodifica //vector se modificia prin ref , adresa 5 , 5 devine 7 nu aici, prin ref, trimitem containerul si devine 7 si cand ma uit in main ma uit tot la acelasi container 
	//p1, se clac noua dimensiuen 
	int m = n - 1;
	//p2. se aloca zm pentru noua dimensiune 
	int* aux = new int[m]; //de dim 4 
	//p3. se copiaza in noua zm ce trebuie 
	for (int i = 0; i < m; i++)
		aux[i] = v[i];
	//p4. se dezaloca fosta zm 
	delete[] v;
	//ps5. pointer vechi pointeza spre zona noua 
	v = aux;
	n = m; //actulizam dimnensiunea 
}




int main() {
	//..
	int x = 5, y = 2;
	cout << x / y;

	//si static si dinamic se DEZALOCA, una pe stiva , una pe heap 
	//int v1[20]; //static pe stiva, sizeof lui v1 - 4*20, adresa lui v1 - 4 octeti ca suntem pe 86
	//il dezalocam la sf blocului pe care l-am creat
	// utilizarea var globale - nu se pot dezaloca, acelasi spatiu pt mult timp, tot atata spatiu, astea in afara main-ului, TOATA LUMEA IL VEDE
	// INCAPSULAREA - proteajearea obiectelor pe care le scriem
	//spre ex 
	{
		int v1[20];
	}


	int* v2; //nu e vector dinamic, il vom facem noi sa fie , int** nu e matrice, aici PUENM IN BREAK POINT SI F10, ulterior in watch scriem &v2, expandam si punem in memory v2 si va da cd cd 
	int n = 5; //nu pierdeti timpul citit de la tastatura 
	v2 = new int[n]; //dc nu se recomanda harcodat, gen aici in loc de n , alt numar 
	for (int i = 0; i < n; i++) //vreau sa-l incarcam cu elem
	{
		v2[i] = i + 10; //incarcam 
	}
	//to do pe v2
	delete[] v2; //eliberam zona de memorie , l-am alocat in context de vector []
	v2 = nullptr;

	if (v2 != nullptr) {
	}




	return 0;
}