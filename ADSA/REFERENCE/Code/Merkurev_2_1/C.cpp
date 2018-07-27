#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const int maxk = 40;
const int maxn = (int) 1e4 + 100;
char str[maxn];
int a[maxn * maxk];

char code[] = "1ijk";

int mul[4][4] = 
{
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};
int sgn[4][4] = 
{
	{0, 0, 0, 0},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{0, 0, 1, 1}
};

bool dp[maxn * maxk][4][4][2];


void solve()
{
	memset(dp, false, sizeof dp);
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	k = min(k, 20 + k % 20);

	scanf("%s", str);
	for (int i = 0; i < n; i++)
		a[i] = find(code, code + 4, str[i] ) - code;
	for (int i = 0; i < n * k; i++)
		a[i] = a[i % n];
	n *= k;
	dp[0][0][0][0] = true;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 3; j++)
			for (int cur = 0; cur < 4; cur++)
				for (int s = 0; s < 2; s++)
				{
					if (!dp[i][j][cur][s] )
						continue;
					if (s == 0 && cur == j + 1)
					{
						dp[i][j + 1][0][0] = true;
					}
					if (i == n)
						continue;
					int ns = s ^ sgn[cur][a[i] ];
					int nxt = mul[cur][a[i] ];
					dp[i + 1][j][nxt][ns] = true;
				}
	printf(dp[n][3][0][0] ? "YES" : "NO");
}


int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		eprintf("Case %d..%d", i, t);
		printf("Case #%d: ", i);
		solve();
		printf("\n");
		eprintf("  done\n");
	}

	return 0;
}


