#include <cstdio>
#include <algorithm>
using namespace std;

const int maxd = 1000;
int pans[maxd];

void solve()
{
	int d;
	scanf("%i", &d);
	for (int i = 0; i < d; i++) {
		scanf("%i", &pans[i]);
	}
	sort(&pans[0], &pans[d],
		std::greater<int>());
	int result = pans[0];
	for (int h = pans[0]; h; --h) {
		int cnt = 0;
		for (int i = 0; i < d; i++) {
			if (pans[i] -1 < h)
				break;
			cnt += (pans[i] -1) / h;
		}
		result = min(result, cnt + h);
	}
	printf("%i", result);
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

