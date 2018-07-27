#include <bits/stdc++.h>

using namespace std;

int A[1005];

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int N;
		cin >> N;
		for(int i = 1; i <= N; i++) cin >> A[i];
		int best = 1000;
		for(int h = 1; h <= 1000; h++)
		{
			int add = 0;
			for(int i = 1; i <= N; i++)
				add += (A[i] - 1) / h;
			best = min(best, h + add);
		}
		printf("Case #%d: %d\n", t, best);
	}
}
