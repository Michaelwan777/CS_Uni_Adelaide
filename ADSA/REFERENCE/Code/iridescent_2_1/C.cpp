#include <bits/stdc++.h>

using namespace std;

char mult[4][4] = { {0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0} };
int neg[4][4] = { {0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1} };

string S;
int A[1231231];

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		int L;
		long long X;
		cin >> L >> X >> S;
		if(X > 16) X = 16 + X % 4;
		for(int i = 0; i < X; i++)
			for(int j = 0; j < L; j++)
				A[i * L + j] = (S[j] - 'h');
		int next = 1;
		int sgn = 0;
		int cur = 0;
		for(int i = 0; i < L * X; i++)
		{
			//cout << A[i];
			sgn ^= neg[cur][A[i]];
			cur = mult[cur][A[i]];
			if(next <= 3 && cur == next && !sgn)
			{
				next++;
				cur = 0;
			}
		}
		printf("Case #%d: ", t);
		cout << ((next == 4 && !cur && !sgn) ? "YES\n" : "NO\n");
	}
}
