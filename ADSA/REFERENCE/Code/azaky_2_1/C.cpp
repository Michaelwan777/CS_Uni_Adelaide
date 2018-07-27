#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <limits>
using namespace std;

#ifdef DEBUG
	#define debug(...) printf(__VA_ARGS__)
	#define GetTime() fprintf(stderr,"Running time: %.3lf second\n",((double)clock())/CLOCKS_PER_SEC)
#else
	#define debug(...) 
	#define GetTime() 
#endif

//type definitions
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vint;

//abbreviations
#define A first
#define B second
#define MP make_pair
#define PB push_back

//macros
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define REPD(i,n) for (int i = (n)-1; 0 <= i; --i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (int i = (a); (b) <= i; --i)
#define FORIT(it,c) for (__typeof ((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define RESET(a,x) memset(a,x,sizeof(a))
#define EXIST(a,s) ((s).find(a) != (s).end())
#define MX(a,b) a = max((a),(b));
#define MN(a,b) a = min((a),(b));

inline void OPEN(const string &s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

/* -------------- end of azaky's template -------------- */

const int qvalue[4][4] = {
	{0, 1, 2, 3},
	{1, 0, 3, 2},
	{2, 3, 0, 1},
	{3, 2, 1, 0}
};
const int qsign[4][4] = {
	{1, 1, 1, 1},
	{1, -1, 1, -1},
	{1, -1, -1, 1},
	{1, 1, -1, -1}
};

struct Quaternion {
	Quaternion(int sign = 1, int value = 0) {
		this->sign = sign;
		this->value = value;
	}
	int sign;	// 1 = +
				// -1 = -
	int value;	// 0 = 1
				// 1 = i
				// 2 = j
				// 3 = k
};

void print(Quaternion q) {
	if (q.sign == -1) printf("-");
	switch (q.value) {
		case 0: printf("1"); break;
		case 1: printf("i"); break;
		case 2: printf("j"); break;
		case 3: printf("k"); break;
	}
}

Quaternion operator*(const Quaternion &a, const Quaternion &b) {
	int sign = qsign[a.value][b.value] * a.sign * b.sign;
	int value = qvalue[a.value][b.value];
	Quaternion result(qsign[a.value][b.value] * a.sign * b.sign, qvalue[a.value][b.value]);
	// print(a); printf(" * "); print(b); printf("\n");
	// printf("sign: %d * %d * %d = %d\n", qsign[a.value][b.value], a.sign, b.sign, sign);
	// printf("value: qvalue[%d][%d] = %d\n", a.value, b.value, qvalue[a.value][b.value]);
	// printf("result: ");	print(a); printf(" * "); print(b); printf(" = "); print(result); printf("\n");
	return result;
	return Quaternion(qsign[a.value][b.value] * a.sign * b.sign, qvalue[a.value][b.value]);
}

Quaternion power(Quaternion a, ll p) {
	if (!p) {
		return Quaternion();
	} else {
		Quaternion result = power(a * a, p >> 1LL);
		if (p & 1LL) result = result * a;
		return result;
	}
}

#define MAXN 100100

int ntc;
ll l, x;
Quaternion m[MAXN];
char s[MAXN];

int main(int argc, char** argv) {
	if (argc != 1) {
		OPEN(argv[1]);
	}

	scanf("%d", &ntc);
	FOR(itc, 1, ntc) {
		scanf("%lld%lld", &l, &x);
		scanf("%s", s);

		// calculate the prefix multiplication
		m[0] = Quaternion();
		FOR(i, 1, l) {
			Quaternion temp;
			switch (s[i-1]) {
				case 'i': temp.value = 1; break;
				case 'j': temp.value = 2; break;
				case 'k': temp.value = 3; break;
			}
			m[i] = m[i-1] * temp;
			// printf("m[%d] = ", i); print(m[i]); printf("\n");
		}

		// check the result immediately
		Quaternion all = power(m[l], x);
		// printf("all = "); print(all); printf("\n");
		if (all.sign != -1 || all.value != 0) {
			printf("Case #%d: NO\n", itc);
			continue;
		}

		// construct the map that helps me trace your steps
		Quaternion map[4];
		FOR(i, 1, 3) {
			map[i] = map[i-1] * m[l];
		}

		// find the first occurence of i
		pii occi, occj;
		occi = MP(4, 0);
		FOR(i, 1, l) {
			REP(d, 4) {
				Quaternion temp = map[d] * m[i];
				if (temp.sign == 1 && temp.value == 1) {
					MN(occi, MP(d, i));
				}
			}
		}

		// no i :(
		if (occi.A == 4 || (ll)occi.A >= x) {
			printf("Case #%d: NO\n", itc);
			continue;
		}

		// find the first occurence of ij = k
		occj = MP(8, 0);
		FOR(i, 1, l) {
			REP(d, 4) {
				Quaternion temp = map[d] * m[i];
				if (temp.sign == 1 && temp.value == 3) {
					pii now = MP(d, i);
					if (now < occi) now = MP(d + 4, i);
					MN(occj, now);
				}
			}
		}

		// no ij :(
		if (occj.A == 8 || (ll)occj.A >= x) {
			printf("Case #%d: NO\n", itc);
			continue;
		}

		// otherwise, yes of course!
		printf("Case #%d: YES\n", itc);
	}

	return 0;
}