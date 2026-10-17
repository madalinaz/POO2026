#include <stdio.h>
#include <malloc.h>

//fct care retirneaza/calc suma elem din vector
int suma(int v[5], int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += v[i];
	}
	return s;
}

void suma(int v[5], int n, int& s)
{
	s = 0;
	for (int i = 0; i < n; i++)
	{
		s += v[i];
	}
}

//functia care inlocuieste cu 0 fiecare valoare impara dintr-un vector
void imparToZero(int v[5], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (v[i] % 2 != 0)
		{
			v[i] = 0;
		}
	}
}

//functia care elimina primul element din vector
//versiune vector alocat static
void eliminaPrimul(int* v, int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		v[i] = v[i + 1];
	}
	n--;
}

//functia care elimina primul element din vector
//versiune vector alocat dinamic
void eliminaPrimulDinamic(int*& v, int& n)
{
	//1.se calc noua dimensiune
	int dimNoua = n - 1;

	//2.se aloca zona de memorie pt noua dimensiune
	int* aux = (int*)malloc(dimNoua * sizeof(int));

	//3.se copiaza in noua zouna de memorie ce trebuie
	for (int i = 0; i < dimNoua; i++)
	{
		aux[i] = v[i + 1];
	}

	//4.se dezaloca fostul vector 
	free(v);
	v = NULL;

	//5.fostul vector pointeaza spre noul  + redimensionare
	v = aux;
	n = dimNoua;
}

int main()
{
	int v[10];//alocare statica -> stiva 
	{
		int x;
	}
	int* v2;//stiva
	v2 = (int*)malloc(5 * sizeof(int));// int* = cast explicit la pointer la int ; pe heap
	for (int i = 0; i < 5; i++)
	{
		v2[i] = i + 10;
	}

	int s1, s2;
	s1 = suma(v2, 5);
	printf("\n%d", s1);

	suma(v2, 5, s2);
	printf("\n%d", s2);


	free(v2);//ca sa nu avem memory leaks
	v2 = NULL; //ca sa nu dangling pointers

	return 0;
}