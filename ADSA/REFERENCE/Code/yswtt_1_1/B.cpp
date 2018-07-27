#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int p[1005];

int main()
{
	int tt;
	
	cin >> tt;
	for (int t = 1; t <= tt; ++t)
	{
		int d, res = 0;
		cin >> d;
		for (int i = 0; i < d; ++i)
		{
			cin >> p[i];
			res = max(res, p[i]);
		}
		for (int i = 1; i < res; ++i)
		{
			int cur = i;
			for (int j = 0; j < d; ++j)
				if (p[j] > i)
					cur += (p[j] - 1) / i;
			res = min(res, cur);
		}
		
		cout << "Case #" << t << ": " << res << endl;
	}

    return 0;
}
