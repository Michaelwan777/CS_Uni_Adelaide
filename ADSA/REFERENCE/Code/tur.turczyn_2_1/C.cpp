// Round 1A 2012
// Problem X.

#ifdef _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

typedef unsigned long long llong;
typedef long double ldouble;
typedef pair<int, int> pint;
typedef pair<double, double> pdouble;
typedef vector<int> vint;
typedef vint::iterator vit;
typedef vector<double> vdouble;
typedef vdouble::iterator vdit;
typedef vector<ldouble> vldouble;
typedef vector<string> vstring;
typedef vector<llong> vllong;
typedef vector<vint> graph;

#define FOR(v,p,k) for(int v=p;v<=k;++v)
#define FORD(v,p,k) for(int v=p;v>=k;--v)
#define REP(i,n) for(int i=0;i<(n);++i)
#ifdef _MSC_VER
	#define VAR(v,i) auto v=(i)
#else
	#define VAR(v,i) __typeof(i) v=(i)
#endif
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define SIZE(x) (int)x.size()
#define ALL(c) c.begin(),c.end()

#define ADD_EDGE(g,u,v) g[u].push_back(v),g[v].push_back(u)

#define ST first
#define ND second
#define INF 1000000000
#define INFL 1000000000000000000LL
#define EPS 1e-5

int V[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };

int value(int X, char c)
{
	int Y = c == 'i' ? 1 : (c == 'j' ? 2 : 3);
	return X > 0 ? V[X - 1][Y] : -V[-X - 1][Y];
}

bool solve(const string &W, int L)
{
	int a = 2, q = 1;
	REP(i, SIZE(W))
	{
		q = value(q, W[i]);
		if(a == q)
			a++, q = 1;
	}
	
	return a == 5 && q == 1;
}

int main()
{
	int T;
	
	cin >> T;
	REP(t, T)
	{
		int L;
		long long X;
		string word = "", W;
		
		cin >> L >> X >> W;
		if(X >= 12)
			X = X % 4LL + 12LL;
		REP(i, X)
			word += W;
		
		printf("Case #%d: %s\n", t + 1, solve(word, L) ? "YES" : "NO");
	}
	
	return 0;
}
