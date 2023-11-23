#include <iostream>
using namespace std;

int pDoi(unsigned int n)
{
    for (int i = n; i >= 1; i--)
    {
        if(i)
        return i;
    }
}
int main()
{
    cout<<pDoi(20);
    return 0;
}
