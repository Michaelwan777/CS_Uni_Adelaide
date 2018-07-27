#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;

int TC;
void solve() {
	int D;
	cin >> D;
	int P[D];
	rep(i, D) cin >> P[i];
	int ans = 1000;
	for(int m=1; m<=1000; m++) {
		int sp = 0;
		rep(i, D) sp += (P[i] - 1) / m;
		ans = min(ans, sp + m);
	}
	cout << ans << endl;
}
int main() {
	int T; cin >> T;
	for(int TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

