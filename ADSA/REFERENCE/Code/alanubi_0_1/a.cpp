#include <cstdio>
#include <algorithm>
using namespace std;

const int maxs = 1000;
char level[maxs +1 +1];

void solve()
{
	int s;
	scanf("%i%s", &s, level);
	int app = 0;
	int cnt = 0;
	for (int i = 0; i <= s; i++) {
		int cur = level[i] -'0';
		app += max(0, i - (cnt + app));
		cnt += cur;
	}
	printf("%i", app);
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		solve();
		printf("\n");
	}
	return 0;
}

