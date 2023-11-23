#include <stdio.h>
#include <math.h>

bool putere(unsigned int x)
{
    while (x > 1)
    {
        if (x % 2 != 0)
            return false;
        x = x / 2;
    }
    return true;
}



int main()
{
    unsigned int n;
    scanf("%d", n);
    printf("%d", putere(n));
    return 0;
}