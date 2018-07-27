#include <cstdio>
const int N = 1010;
int T, n, a[N];
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d", &n);
		int lim = 0, ans = 1000000000;
		for (int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			if (a[i] > lim) lim = a[i];
		}
		for (int i = 1; i <= lim; ++i){
			int now = 0;
			for (int j = 1; j <= n; ++j) if (a[j] > i) now += (a[j] - 1) / i;
			now += i;
			if (now < ans) ans = now;
		}
		printf("Case #%d: %d\n", Ti, ans);
	}
	return 0;
}
