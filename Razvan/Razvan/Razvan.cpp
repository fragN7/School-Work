/*
Fie un text format din maxim 10 nume de familie, fiecare nume având maxim 20 de caractere.
Să se facă un meniu care să conţină următoarele operaţii:
0. Ieșire
1. Citirea a n nume de la tastatură.
Observații:
· Numele este considerat citit corect dacă prima literă a numelui este literă mare, iar următoarele
sunt litere mici.
· Ultimul nume care se introduce este dat automat, fiind egal cu “Nicolae”. Nu este permisă
folosirea funcției strcpy().
2. Afișarea textului format din nume de familie în ordine alfabetică.
3. Să se copieze într-un vector de numere întregi lungimea fiecărui nume, apoi vectorul să se salveze
într-un fișier text cu numele dat de utilizator de la tastatură.
Observatii:
· Se va utiliza alocarea dinamică de memorie. La ieșire se va elibera toată memoria alocată dinamic.
· Pentru fiecare opțiune se va crea o funcție, iar variabilele se vor transmite prin adresă.
· Nu este permisă folosirea variabilelor globale.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream>
int validare(char* nume)
{
	// alin, petru , A9897, ALEN, Mihai, EleNarew
	int i;
	if (nume[0] < 'A' || nume[0] > 'Z')// (13, 25)  !(x>13 && x<25)
		return 0;
	for (i = 1; i <= strlen(nume) - 1; i++)
		if (nume[i] < 'a' || nume[i] > 'z')
			return 0;
	return 1;
}
void citire(char** s, int n)
{
	int i;
	char nume[21];
	s[n-1] = (char*)malloc(strlen("Nicolae") + 1 * sizeof(char));
	strcpy(s[n-1], "Nicolae");
	for (i = 0; i < n-1 ; i++)
	{
		printf("Numele[%d]=", i);
		scanf("%s", nume);
		s[i] = (char*)malloc(strlen(nume) + 1 * sizeof(char));
		strcpy(s[i], nume);
		if (validare(nume) == 0)
		{
			printf("Nu e bine boss, mai baga o data\n");
			i--;
		}
	}

}
void afisare(char** s, int n)
{
	int i, j;
	char aux[21];
	for(i = 0; i < n-1; i++)
		for(j = i + 1; j < n; j++)
			if (strcmp(s[i], s[j]) > 0)
			{
				strcpy(aux, s[i]);
				strcpy(s[i], s[j]);
				strcpy(s[j], aux);
			}
	for (i = 0; i < n; i++)
		printf("Cuvantul %d: %s \n", i + 1, s[i]);
}
void tablou(char **s, int n)
{
	int *tablou, i;
	tablou = (int*)malloc(n * sizeof(int));/// alen , mario, mihai, nicolae |||| 0 a
	FILE* file;
	file = fopen("TextFile1.txt", "w");

	for (i = 0; i < n; i++)
	{
		tablou[i] = strlen(s[i]);
		printf("Numarul de caractere ale sirului %s este %d \n", s[i], tablou[i]);
		fprintf(file, "Numarul de caractere ale sirului %s este %d \n", s[i], tablou[i]);
	}
	fclose(file);
}
void transformare(char** s, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= strlen(s[i]); j++)
			if (s[i][j] == 'a')
				s[i][j] = '?';
	}
	for (i = 0; i < n; i++)
		printf("Cuvantul %d: %s \n", i + 1, s[i]);
}
void litere_mici(char** s, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= strlen(s[i]); j++)
			if (s[i][j] >= 'a' && s[i][j] <= 'z')
				s[i][j] = s[i][j] - 32;
	}
	for (i = 0; i < n; i++)
		printf("Cuvantul %d: %s \n", i + 1, s[i]);
}
void cautare(char** s, int n)
{
	char* fruct, i;
	fruct = (char*)malloc(20 * sizeof(char));
	printf("cautati cuvantul:");
	scanf("%s", fruct);
	for (i = 0; i < n; i++)
	{
		if (strcmp(fruct, s[i]) == 0)
			printf("fructul se afla pe pozitia:%d\n", i + 1);
	}
}
void sortare(char** s, int n)
{
	int i, k;
	char aux[20];
	do {
		k = 1;
		for (i = 1; i < n; i++)
			if (strcmp(s[i - 1], s[i]) > 0)
			{
				strcpy(aux, s[i]);
				strcpy(s[i], s[i - 1]);
				strcpy(s[i - 1], aux);
				k = 0;
			}
	} while (!k);
	for (i = 0; i < n; i++)
		printf("Cuvantul %d: %s \n", i + 1, s[i]);
}
void fisier(char** s, int n)
{
	FILE* f;
	int i;
	char nume[20];
	printf("Nume fisier:");
	scanf("%s", nume);
	f = fopen(nume, "wt");
	if (f == NULL)
		printf("Eroare la deschiderea/crearea fisierului!\n");
	else
	{
		for (i = 0; i < n; i++)
			if (s[i][0] == 'a' || s[i][0] == 'A')
				fprintf(f, "%s \n", s[i]);
		fclose(f);
	}
}
void schimbarevocala(char** s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strlen(s[i]) == 3)
			strcpy(s[i], "NNN");
	}
	for (i = 0; i < n; i++)
		printf("Cuvantul %d: %s \n", i + 1, s[i]);
}
void putere(char** s, int n)
{
	int k, i, j;
	int ok;
	for (i = 0; i < n; i++)
	{
		ok = 1;
		j = 0;
		do
		{
			j++;
			k = strlen(s[i]) >> j;
		} while (k & 1);
		while (j != 31)
		{
			k = strlen(s[i]) >> j;
			j++;
			if (k & 1)
				ok = 0;
		}
		if (ok == 1 && strlen(s[i]) % 2 == 1)
			printf("cuvantul %d: %s\n", i + 1, s[i]);
	}
}
void matrice(char** s, int n)
{
	int** matrice, i, j, maxim = 0;
	for (i = 0; i < n; i++)
		if (maxim < strlen(s[i]))
			maxim = strlen(s[i]);
	matrice = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
	{
		matrice[i] = (int*)malloc(n * sizeof(int));
		for (j = 0; j < n; j++)
			if (i + j == n - 1)
				matrice[i][j] = maxim;
			else
				matrice[i][j] = 0;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
}
int main()
{
	char** s = 0;
	int opt, n = 0;
	do
	{
		printf("0.Iesire.\n");
		printf("1.Citirea a n nume de la tastatură.\n");
		printf("2.Afișarea textului format din nume de familie în ordine alfabetică\n");
		printf("3.Sa se puna intr - un vector sau intr - un tablou de pointeri lungimile fructelordin text.\n");
		printf("4.Sa se inlocuiasca caracterul 'a' cu ' ? '.\n");
		printf("5.Sa se transforme literele mici in litere mari.\n");
		printf("6.Cautarea unui fruct in text.\n");
		printf("7.Sortarea fructelor in ordine alfabetica.\n");
		printf("8.Salvarea fructelor care incep cu 'A' sau 'a' intr - un fisier text.\n");
		printf("9.inlocuirea fructelor care au lungimea = cu 3 cu 'NNN'.\n");
		printf("10.Sa se afiseze toate fructele care au lungimea mai mica cu 1 decat a lui 2 .\n");
		printf("11.Sa se afiseze sub forma unei matrice patratice de ordin dat de nr de fructe, omatrice ce are pe diag sec.lungimea maxima a fructelor din text iar pe restul el. 0.\n");
		printf("opt=");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			free(s);
			printf("Numarul de nume:");
			scanf("%d", &n);
			s = (char**)malloc(n * sizeof(char*));
			citire(s, n);
			break;
		case 2:
			afisare(s, n);
			break;
		case 3:
			tablou(s, n);
			break;
		case 4:
			transformare(s, n);
			break;
		case 5:
			litere_mici(s, n);
			break;
		case 6:
			cautare(s, n);
			break;
		case 7:
			sortare(s, n);
			break;
		case 8:
			fisier(s, n);
			break;
		case 9:
			schimbarevocala(s, n);
			break;
		case 10:
			putere(s, n);
			break;
		case 11:
			matrice(s, n);
			break;
		default:
			printf("Salam cumetre ca nu e buna optiunea\n");
			break;
		}
	} while (opt != 0);
	_getch();
	return 0;
}