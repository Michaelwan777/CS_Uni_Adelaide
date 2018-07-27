#include<iostream>
using namespace std;
void tri(int n);
int main()
{
	int  n;
	cout << "enter the n" << endl;
	cin >> n;
	tri(n);
	return 0;
}
void tri(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
	for (i = n + 1; i <= 2 * n - 1; i++)
	{
		for (j = 1; j <= 2 * n - i; j++)
		{
			cout << "*" << " ";
		}
		cout << endl;
	}
}