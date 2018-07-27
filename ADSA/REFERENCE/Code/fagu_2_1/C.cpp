#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MODD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,a,n) for (int i = (a); i < (n); i++)

int T;

int milt[][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int misg[][4] = {{0,0,0,0},{0,1,0,1},{0,1,1,0},{0,0,1,1}};

int mult(int a, int b) { // 0<=a<8, 0<=b<4
	return milt[a%4][b]+4*((a/4 + misg[a%4][b])%2);
}

int L;
ll X;
char line[20000];
bool dp[30*20000][4][8];

void se(int i, int w, int l) {
	dp[i][w][l] = true;
	if (l == w+1)
		dp[i][w+1][0] = true;
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d %lld %s ", &L, &X, line);
		X = min(X, 16+X%4);
		fprintf(stderr, "%d %lld\n", L, X);
		REP(i,0,L*X+1) REP(w,0,4) REP(l,0,8)
			dp[i][w][l] = false;
		dp[0][0][0] = true;
		REP(i,0,L*X) {
			REP(w,0,3) REP(l,0,8)
				if (dp[i][w][l])
					se(i+1,w,mult(l,line[i%L]-'i'+1));
		}
		if (dp[L*X][3][0])
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
