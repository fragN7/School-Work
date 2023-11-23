
#include <stdio.h>

int functie(int varsta, int numar_bilete, int pret)
{
	int cost;
	if (varsta < 18 || varsta > 65)
	{
		pret = pret - (25 / 100) * pret;
		cost = numar_bilete * pret;
		return cost;
	}
	if (varsta >= 18 && varsta <= 25)
	{
		pret = pret - (10 / 100) * pret;
		cost = numar_bilete * pret;
		return cost;
	}
	cost = numar_bilete * pret;
	return cost;
}

int calcul(int n)
{
	int s = 0, p = 1, e;
	for (int i = 0; i <= n; i = i + 2)
		s = s + i;
	for (int i = 2; i <= n; i = i + 2)
		p = p * i;
	e = 2 * s + p;
	return e;
}

int main() {
	printf("%d",calcul(7));
	return 0;
}