#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;

int TC;
void solve() {
	int n;
	string a;
	cin >> n >> a;
	int s = 0;
	int ans = 0;
	rep(i, n+1) {
		int k = a[i]-'0';
		if (s < i) {
			ans += i - s;
			s = i;
		}

		s += k;
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

