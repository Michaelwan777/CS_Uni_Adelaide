#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>
#include <cstdint>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))
#define T1 first
#define T2 second.first
#define T3 second.second

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007

char str[10001];
int mul[8][8];

void init(){
	memset(mul, -1, sizeof(mul));
	mul[0][0] = 0;
	mul[0][1] = 1;
	mul[0][2] = 2;
	mul[0][3] = 3;
	mul[1][0] = 1;
	mul[1][1] = 4;
	mul[1][2] = 3;
	mul[1][3] = 6;
	mul[2][0] = 2;
	mul[2][1] = 7;
	mul[2][2] = 4;
	mul[2][3] = 1;
	mul[3][0] = 3;
	mul[3][1] = 2;
	mul[3][2] = 5;
	mul[3][3] = 4;
	REP(i,4)FOR(j,4,8)mul[i][j] = (mul[i][j-4]+4)%8;
	FOR(i,4,8)REP(j,8)mul[i][j] = (mul[i-4][j]+4)%8;
}

void solve(){
	int l;
	LL x;
	scanf("%d%lld", &l, &x);
	cin >> str;
	int dp = 0;
	REP(i,l)str[i] = str[i]-'i'+1;
	REP(i,l)dp = mul[dp][str[i]];
	if(x%4==0){
		printf("NO\n");
		return;
	}if(x%4==1||x%4==3){
		if(dp!=4){
			printf("NO\n");
			return;
		}
	}else{//x%4==2
		if(dp==0 || dp==4){
			printf("NO\n");
			return;
		}
	}
	if(x>=16)x=x%4+12;
	dp = 0;
	int check = 1;
	REP(i,x){
		REP(j,l){
			dp = mul[dp][str[j]];
			if(dp == check){
				if(check==3){
					printf("YES\n");
					return;
				}else{
					check = 3;
				}
			}
		}
	}
	printf("NO\n");
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	init();
	scanf("%d", &T);
	REP(t,T){
		printf("Case #%d: ", t+1);
		solve();
	}
	return 0;
}