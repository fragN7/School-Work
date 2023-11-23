#include <iostream>
using namespace std;

int main()
{
    unsigned int x,y,nr;
    cin >> x;
    while (x != -1)
    {
        y = x;
        cin >> x;
        nr = 0;
        while (y == x)
        {
            nr++;
            cin >> x;
        }
        if(nr)
        cout << y << " " << nr+1 << " ";
        cin >> x;
    }
    return 0;
}
