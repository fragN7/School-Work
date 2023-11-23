#include <stdlib.h>
#include <stdio.h>

int main()
{
    int x;

    FILE *fp;
    fp = fopen_s("TextFile4.txt");

    if (fp == NULL)
    {
        printf("ERROR");
        exit(1);
    }

    while((fscanf_s(fp, "%d", x)) != EOF)
    {
        if (!(x % 2))
            printf("%d", x);
    }
    fclose(fp);
}
