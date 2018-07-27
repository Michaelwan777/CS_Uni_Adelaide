#include <bits/stdc++.h>
using namespace std;
int A[1005];
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int D, ans = INT_MAX;
		scanf("%d", &D);
		for (int i = 0; i < D; ++i) scanf("%d", &A[i]);
		for (int mx = 1; mx <= 1000; ++mx) {
			int req = mx;
			for (int i = 0; i < D; ++i)
				req += (A[i] + mx - 1) / mx - 1;
			ans = min(ans, req);
		}
		printf("Case #%d: %d\n", cn, ans);
	}
}

