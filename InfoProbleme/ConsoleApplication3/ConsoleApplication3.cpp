#include <iostream>
using namespace std;

int main()
{
    unsigned int x, y;
    int max = -1;
    cin >> x;
    while (x!=0)
    {
        if(x>max)
        {
            cout << x << " ";
            max = x;
        }
        y = x;
        cin >> x;
        while (y == x)
        {
            cout << x << " ";
            cin >> x;
        }
        if (x > max)
        {
            cout << x << " ";
            max = x;
        }
        cin >> x;
    }
    return 0;
}