#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <malloc.h>

//fct care returneaza / calculeaza suma elem din v
int suma(int v[5], const int& n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
	}
	return s;
}

void suma(int v[5], int n, int& s) {
	s = 0;
	for (int i = 0; i < n; i++) {
		s += v[i];
	}
}

//fct care inlocuieste cu  -1 valorile pare din vector
void modif1(int* v, int n) {
	for (int i = 0; i < n; i++)
		if (v[i] % 2 == 0) v[i] = -1;

}

//fct care sterge primele k elem din vector
//se stie ca k < n
void modifVectorStatic(int* v, int& n, int k) {
	for (int i = 0; i < n - k; i++) {
		v[i] = v[i + k];
	}
	n -= k;
}

void modifVectorDinamic(int*& v, int& n, int k) {
	//1. se calc noua dimensiune
	int dimNoua = n - k;

	//2. se aloca zona de memorie pentru noua dimensiune
	int* aux = (int*)malloc(dimNoua * sizeof(int));

	//3. copiez in noua zm ce imi trebuie
	for (int i = k; i < n; i++) {
		aux[i - k] = v[i];
	}

	//4. se dezaloca zm veche
	free(v);

	//5. vector vechi pointeaza spre vector nou
	v = aux;
	n = dimNoua;
}

int main() {

	int v[10]; //alocat static pe stiva
	{ //x nu exista cat timp este in acest "bloc" ({int x})
		int x; //pe stiva
	}
	int* v2; //pointer (adresa) (4 (x32) sau 8 (x64) octeti) pe stiva
	v2 = (int*)malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++) {
		v2[i] = i + 10;
	}
	int s = suma(v2, 5);
	suma(v, 5, s);
	free(v2); //pentru no memory leaks
	v2 = NULL; //pentru no dangling pointers
	return 0;
}