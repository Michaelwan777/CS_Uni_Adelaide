#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int func(int a, int b)
{
	int neg = (a * b > 0) ? 1 : -1;
	int res = 0;
	a = abs(a);
	b = abs(b);
	if (a == 1)
		res = b;
	else if (b == 1)
		res = a;
	else if (a == b)
		res = -1;
	else if (b - 2 == ((a - 1) % 3))
		res = 9 - a - b;
	else
		res = a + b - 9;
	res *= neg;
	return res;
}

int p[1005];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		long long l, x;
		cin >> l >> x;
		
		string s;
		cin >> s;
		int stage = 0;
		int cur = 1;
		for (int i = 0; i < s.length(); ++i)
			cur = func(cur, s[i] - 'i' + 2);
		string res = "NO";
		if (((cur == -1) && (x % 2 == 1)) || ((abs(cur) != 1) && (x % 4 == 2)))
		{
			int ind = 0, num = 0;
			cur = 1;
			while (true)
			{
				cur = func(cur, s[ind] - 'i' + 2);
				if ((cur == 2) && (stage == 0))
				{
					stage = 1;
					cur = 1;
				}
				else if ((cur == 3) && (stage == 1))
				{
					stage = 2;
					cur = 1;
				}
				else if ((cur == 4) && (stage == 2))
				{
					res = "YES";
					break;
				}
				ind++;
				if (ind == s.length())
				{
					num++;
					ind = 0;
					if ((num >= 12) || (num >= x))
						break;
				}
			}
		}
		
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
