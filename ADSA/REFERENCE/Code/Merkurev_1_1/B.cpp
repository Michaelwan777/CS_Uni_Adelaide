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
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


const int maxn = 1005;
int a[maxn];
int n;

bool solve(int st, int x)
{
	int need = 0;
	for (int i = 0; i < n; i++)
	{
		need += (a[i] + x - 1) / x - 1;
	}
	return need <= st;
}

int solve(int st)
{
	int l = 0, r = maxn;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (solve(st, m) )
			r = m;
		else
			l = m;
	}
	return st + r;
}

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	sort(a, a + n);
	reverse(a, a + n);
	int ans = maxn;
	for (int st = 0; st < maxn; st++)
	{
		ans = min(ans, solve(st) );
	}
	printf("%d", ans);
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
		eprintf("Case %d of %d", i, t);
		printf("Case #%d: ", i);
		solve();
		printf("\n");
		eprintf("  done\n");
	}

	return 0;
}


