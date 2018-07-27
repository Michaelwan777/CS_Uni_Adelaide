#include <bits/stdc++.h>
using namespace std;
char shy[1005];
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int S, csum = 0, ans = 0;
		scanf("%d%s", &S, shy);
		for (int i = 0; i <= S; ++i) {
			int num = shy[i] - '0';
			if (num) ans = max(ans, i - csum);
			csum += num;
		}
		printf("Case #%d: %d\n", cn, ans);
	}
}

