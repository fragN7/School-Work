#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct dispozitiv
{
    char model[20], retea[20];
    int pret, categoria;
    float diagonala;
}D;
void citire_tastatura(D* dis, int* n)
{
    (*n)++;
    printf("Modelul este : ");
    scanf("%s", (dis + *n)->model);
    printf("Pretul produsului este :");
    scanf("%d", &(dis + *n)->pret);
    printf("Categoria -> introduceti 0 pentru - TELEFOANE sau 1 pentru TABLETE: ");
    scanf("%d", &(dis + *n)->categoria);

    if ((dis + *n)->categoria == 1)
    {
        printf("Reteaua telefonului este :");
        scanf("%s", (dis + *n)->retea);
    }
    else
    {
        printf("Diagonala tabletei este :");
        scanf("%f", &(dis + *n)->diagonala);
    }
}

int main()
{
    int opt, n = -1;
    char model[20];
    D dis[30];
    citire_tastatura(dis, &n);

    return 0;
}