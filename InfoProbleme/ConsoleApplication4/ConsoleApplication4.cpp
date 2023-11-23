#include <iostream>
#include <string.h>
using namespace std;
char s[100], aux[100][100], * p;

int main()
{
    int x = 0;
    cin.get(s, 101);
    cin.get();
    p = strtok(s, " ");
    while (p != NULL)
    {
        x++;
        strcpy(aux[x], p);
        p = strtok(NULL, " ");
    }
    for (int i = 1; i <= x; ++i)
        if (aux[i][0] >= 'A' && aux[i][0] <= 'Z')
        {
            for (int j = 1; j <= strlen(aux[i]) - 1; j++)
                if (aux[i][j] >= 'A' && aux[i][j] <= 'Z')
                    aux[i][j] = aux[i][j] + 32;
        }
        else
        {
            aux[i][0] = aux[i][0] - 32;
            for (int j = 1; j <= strlen(aux[i]) - 1; j++)
                if (aux[i][j] >= 'A' && aux[i][j] <= 'Z')
                    aux[i][j] = aux[i][j] + 32;
        }
    for (int i = 1; i <= x; ++i)
        cout << aux[i] << " ";
    return 0;
}
