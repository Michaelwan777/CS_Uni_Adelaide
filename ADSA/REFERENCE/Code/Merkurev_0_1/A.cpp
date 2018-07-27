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
char str[maxn];
int a[maxn];


int solve()
{
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i <= n; i++)
		a[i] = str[i] - '0';

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i <= n; i++)
	{
		if (a[i] == 0)
			continue;
		while (cnt < i)
		{
			ans++;
			cnt++;
		}
		cnt += a[i];
	}
	return ans;
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
		printf("Case #%d: %d\n", i, solve() );
	}

	return 0;
}


