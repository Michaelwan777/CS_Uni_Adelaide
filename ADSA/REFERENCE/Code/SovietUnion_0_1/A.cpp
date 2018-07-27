#include <cstdio>
#include <cstring>
const int N = 2000;
int T, n;
char s[N];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d%s", &n, s);
		int tot = 0, ans = 0;
		for (int i = 0; i <= n; ++i) s[i] -= '0';
		for (int i = 0; i <= n; ++i) if (s[i] != 0){
			if (tot < i) ans += i - tot, tot = i;
			tot += s[i];
		}
		printf("Case #%d: %d\n", Ti, ans);
	}
	return 0;
}
