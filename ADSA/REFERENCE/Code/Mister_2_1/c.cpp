#include <bits/stdc++.h>
using namespace std;
char str[110005];
int seq[110005], lmult[110005], rmult[110005], conv[256];
int MULT[5][5] = {
	{0, 0, 0, 0, 0},
	{0, 1, 2, 3, 4},
	{0, 2, -1, 4, -3},
	{0, 3, -4, -1, 2},
	{0, 4, 3, -2, -1}
};
int L;
long long X;
int mult(int a, int b) {
	int sign = a < 0 ? -1 : 1;
	sign *= (b < 0 ? -1 : 1);
	return sign * MULT[abs(a)][abs(b)];
}
bool can() {
	if (X >= 12) {
		X = 8 + (X % 4);
	}
	int N = X * L;
	for (int i = 0; i < N; ++i) {
		seq[i + 1] = conv[str[i % L]];
	}
	int ipos = 0, kpos = 0;
	lmult[0] = 1;
	for (int i = 1; i <= N; ++i) {
		lmult[i] = mult(lmult[i - 1], seq[i]);
		if (lmult[i] == 2 && !ipos) ipos = i;
	}
	rmult[N + 1] = 1;
	for (int i = N; i >= 1; --i) {
		rmult[i] = mult(seq[i], rmult[i + 1]);
		if (rmult[i] == 4 && !kpos) kpos = i;
	}
	if (lmult[N] != -1) return false;
	if (!ipos || !kpos || ipos >= kpos) return false;
	return true;
}
int main() {
	conv['1'] = 1;
	conv['i'] = 2;
	conv['j'] = 3;
	conv['k'] = 4;
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		scanf("%d%lld%s", &L, &X, str);
		printf("Case #%d: ", cn);
		printf(can() ? "YES\n" : "NO\n");
	}
}

