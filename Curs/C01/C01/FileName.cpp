#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;


//tipuri de transfer (C -> C++)

//functii de prelucrare
//agregare
//de modificare (pe elem, pe dimensiunea vectorului)

void f1(const int x) {
	//x = 10;
}

void afisareVector(int v[], const int n) {
	/*for (int i = 0; n = i; i++) {
		printf("%d ", v[i]);
	}*/
}

//specific c++
//transfer prin referinta ca sa nu fac copie
//declar const ca sa protejez obj
void f2(const int& x) {
	//x = 2;
	printf("%d", x);
}

//transfer prin referinta ca sa modific 
//direct variabila din "main"
void f3(int& x) {
	scanf("%d", &x);
}



int main() {
	//declara un vector static 
	//declara un vector alocat dinamic
	//popula cu valori
	//aplica operatii pe vectori
	//dezaloca zm acolo unde se cere

	//eroare de compilare
	int x; //pe stiva
	int y;
	x = 2;
	y = 10;
	//y = x;
	x = y;
	//&x = &y; //de ce nu? pentru ca adresa unei variabile nu poate fi modificata

	int* p;//un pointer => o adresa (ocupa 4/8 octeti)

	//p = 10;
	p = &x;
	p = &y;
	//p = x;
	//&p = &x; //adresa unei variabile NU poate fi modificata
	*p = x;
	*p = 20;

	//2 variabile de tipuri diferite
	int var1;
	float var2 = 15.2f;
	var1 = var2; //de la float la int (conversie/cast implicit la int)
	var2 = var1; //int to float

	p = (int*)malloc(sizeof(int));//vector alocat dinamic cu 1 singur elem SAU pointer la un elem de tip int (pe heap)
	//aici ar trebui free(p)
	p = &x;//pointer de pe stiva care pointeaza tot pe stiva
	*p = 10;
	//free(p);

	char* pChar; //pointer = adresa = 4 sau 8
	pChar = (char*)malloc(sizeof(char));
	//vreau sa modific acel I cu caracterul a
	//pChar[0] = 'a'; //operatorul index
	*pChar = 'a';
	free(pChar);
	pChar = NULL;//0 ca sa nu dangling pointers

	//C02
	//C
	int* pVector;
	int n = 10;
	pVector = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		pVector[i] = i; //*(v+i)
	}
	free(pVector);
	pVector = NULL;

	//C++
	pVector = new int[n];//pe heap
	for (int i = 0; i < n; i++) {
		pVector[i] = i; //*(v+i)
	}
	delete[] pVector;
	pVector = nullptr;

	pVector = new int(n);//aloc un singur int pe care il si initializez-> se apeleaza constructorul int-ului
	*pVector = 20;
	delete pVector;

	int b;
	b = 7;
	const int a = 123;
	//a = 12;
	int const a2 = 123;

	const int* p1;//pointer spre continut constant
	p1 = &b;
	//*p1 = 15;
	int const* p2;//pointer spre continut constant
	p2 = &b;
	//*p2 = 15;
	int* const p3 = &b;//pointer constant
	//p3 = &a;
	*p3 = 15;
	const int* const p4 = &b;
	//p4 = &a;
	//*p4 = 10;

	//CIN si COUT ->sunt obiecte
	printf("%d", b);

	//std::cout << b << std::endl;
	cout << b << endl;
	cout << "text" << 5;
	return 0;
}