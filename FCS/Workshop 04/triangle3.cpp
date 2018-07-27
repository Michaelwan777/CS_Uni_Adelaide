#include<iostream>
using namespace std;
void tri (int n);
int main()
{
	int n;
	cout << "enter the number n";
	cin >> n;
	tri(n);
	return 0;
}
void tri(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
		{
			cout << " ";
		}
		for (j = 1; j <= 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}