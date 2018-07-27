#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<int(n); ++i)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef long long ll;

int TC;

/*
×	1	i	j	k
1	1	i	j	k
i	i	−1	k	−j
j	j	−k	−1	i
k	k	j	−i	−1
*/
int M[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1},
};
int mult(int a, int b) {
	return M[abs(a)-1][abs(b)-1] * (a*b > 0 ? 1 : -1);
}
void solve() {
	ll L, X;
	string s;
	cin >> L >> X >> s;
	ll ipos = -1, kpos = -1;
	ll cur = 1;
	string t;
	rep(i, 4) t += s;

	cur = 1;
	rep(i, L) cur = mult(cur, t[i]-'i'+2);
	bool ok = false;
	if (abs(cur) == 1) {
		if (cur == -1 && X % 2 == 1) ok = true;
	} else {
		if (X % 4 == 2) ok = true;
	}
	if (!ok) {
		cout << "NO" << endl;
		return;
	}

	cur = 1;
	rep(i, 4*L) {
		cur = mult(cur, t[i]-'i'+2);
		if (cur == 2 && ipos == -1) ipos = i;
	}
	cur = 1;
	rep(i, 4*L) {
		cur = mult(t[4*L-1-i]-'i'+2, cur);
		if (cur == 4 && kpos == -1) kpos = i;
	}
	if (ipos != -1 && kpos != -1 && ipos < L*X-1-kpos) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main() {
	int T; cin >> T;
	for(TC=1; TC<=T; TC++) {
		cout << "Case #" << TC << ": ";
		solve();
	}
}

