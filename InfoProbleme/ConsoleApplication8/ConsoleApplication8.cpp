#include <iostream>
#include <string.h>
using namespace std;
char x[255];
int a[10];
void function()
{
	for (int i = 0; i <= 9; i++)
		a[i] = 0;
}
void scrabble()
{
	for (int i = 0; i <= strlen(x) - 1; i++)
		a[i]++;
}
int main
{

    cin >> x;
	function();
	scrabble();
	return 0;
}