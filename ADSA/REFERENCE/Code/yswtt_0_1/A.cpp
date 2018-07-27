#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int s;
		cin >> s;
		char c;
		int res = 0, cur = 0;
		for (int i = 0; i <= s; ++i)
		{
			cin >> c;
			if (cur < i)
			{
				res += i - cur;
				cur = i;
			}
			cur += c - '0';
		}
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
