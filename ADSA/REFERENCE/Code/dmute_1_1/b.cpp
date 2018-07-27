#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int n;
char str[2005];
int p[2005];
int main()  {
	int tst;
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++)  {
		scanf("%d", &n);
		bool nonemp = false;
		for (int i = 1; i <= n; i ++)  scanf("%d", &p[i]), nonemp |= p[i] != 0;
		int ans = 1000000005;
		if (!nonemp)  ans = 0;
		else {
			int sum = 0;
			for (int left = 1; left <= 1000; left ++)  {
				sum = 0;
				for (int i = 1; i <= n; i ++)  {
					sum += p[i] / left;
					if (p[i] % left == 0) sum --;
				}
				sum += left;
				ans = min(ans, sum);
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}