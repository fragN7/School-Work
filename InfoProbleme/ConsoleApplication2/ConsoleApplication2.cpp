#include <iostream>
#include <cmath>
int numar(unsigned int y)
{
    int p = 0;
    while (y>9)
    {
        p++;
        y = y / 10;
    }
    for (int i = 1; i <= y; i++)
        cout << 10^p << " ";
}
using namespace std;
int main()
{
    unsigned int n, inv = 0, m=0,x=0,v[100];
    cin >> n;
    while (n)
    {
        inv = inv * 10 + n % 10;
        x++;
        n = n / 10;
    }
    while (inv)
    {
        m++;
        v[m]=(inv % 10) * (pow(10, x));
        x--;
        inv = inv / 10;
    }
    for (int i = 1; i <= m; i++)
             numar(v[i]);
    return 0;
}