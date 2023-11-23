#include <iostream>
#include <string.h>
using namespace std;
/*
void produs(unsigned int n, unsigned int &p)
{
    unsigned int i, x;
    for (i = 0; i <= 8; i=i+2)
    {
        x = n;
        while (x)
        {
            if (x % 10 == i)
            {
                p = p * i;
                x = 0;
            }
            x = x / 10;
        }
    }
}
*/
char s[101],s1[51][101],*p;
int main()
{
    unsigned int i, n = 0;
    cin.get(s, 101);
    cin.get();
    p = strtok(s," ");
    while (p!=NULL)
    {
        n++;
        strcpy(s1[n], p);
        p = strtok(NULL, " ");
    }
    strcpy(s, s1[1]);
    strcat(s, " ");
    if (s1[1][strlen(s1[1]) - 1] == s1[2][strlen(s1[2]) - 1])
        strcat(s, "succes ");
    for (i = 2; i <= n - 1; i++)
    {
        strcat(s, s1[i]);
        strcat(s, " ");
        if (s1[i][strlen(s1[i]) - 1] == s1[i + 1][strlen(s1[i + 1]) - 1])
            strcat(s, "succes ");
    }
    strcat(s, s1[n]);
    cout << s;
    return 0;
}
