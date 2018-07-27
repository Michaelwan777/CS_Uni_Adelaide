#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <queue>
#include <assert.h>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <complex>
#include <numeric>
#include <map>
#include <time.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,ull> piu;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
typedef pair<pii,ll> ppl;
typedef pair<ll,pii> plp;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;
typedef pair<double,pii> pdp;
typedef pair<double,double> pdd;
typedef pair<pdd,double> pd3;
typedef vector<int> vec;
typedef vector<vec> mat;
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define repn(i,a,n) for (int (i) = (a); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define SORT(x) sort((x).begin(),(x).end())
#define SORTN(x,n) sort((x),(x)+(n))
#define ERASE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define COUNT(x,c) count((x).begin(),(x).end(),(c))
#define REMOVE(x,c) (x).erase(remove((x).begin(),(x).end(),(c)),(x).end())
#define REVERSE(x) reverse((x).begin(),(x).end())
#define FORIT(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))-(x).begin()
#define lb(x,a) lower_bound((x).begin(),(x).end(),(a))
#define LBN(x,a,n) lower_bound((x),(x)+(n),(a))-(x)
#define lbN(x,a,n) lower_bound((x),(x)+(n),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))-(x).begin()
#define ub(x,a) upper_bound((x).begin(),(x).end(),(a))
#define BS(x,a) binary_search((x).begin(),(x).end(),(a))
#define BS2(x,n,a) binary_search((x),(x)+(n),(a))
#define NB(x) (((x)&~((x)+((x)&-(x))))/((x)&-(x))>>1)|((x)+((x)&-(x)))
#define NP(x) next_permutation((x).begin(),(x).end())
#define MM(x,p) memset((x),(p),sizeof(x))
#define SQ(x) (x)*(x)
#define SC(c1,c2) strcmp(c1,c2)==0
#define mp make_pair
#define INF (1<<29)
#define INFL (1LL<<61)
#define fi first
#define se second
#define MOD 1000000009
#define EPS 1e-9
#define MIN(x,a) x=min(x,a)
#define MAX(x,a) x=max(x,a)
#define madd(x,a) x=(x+a)%MOD
#define msub(x,a) x=(x+MOD-a)%MOD
#define OUTPUT(x) rep(i,x.size())printf("%d%c",x[i],i+1==x.size()?'\n':' ');

int T,n,K;
ll K_in;
char s[10001];
int id[10001];
int dp[641001][3];

int kk[8][8];

int main()
{
	kk[0][0]=0,kk[0][1]=1,kk[0][2]=2,kk[0][3]=3;
	kk[1][0]=1,kk[1][1]=4,kk[1][2]=3,kk[1][3]=6;
	kk[2][0]=2,kk[2][1]=7,kk[2][2]=4,kk[2][3]=1;
	kk[3][0]=3,kk[3][1]=2,kk[3][2]=5,kk[3][3]=4;
	rep(i,8)rep(j,8)if(i>=4||j>=4)
	{
		if(i<4)kk[i][j]=kk[i][j-4]^4;
		else if(j<4)kk[i][j]=kk[i-4][j]^4;
		else kk[i][j]=kk[i-4][j-4];
	}
	scanf("%d",&T);
	repn(__,1,T+1)
	{
		scanf("%d%lld",&n,&K_in);
		scanf("%s",&s);
		rep(i,n)
		{
			if(s[i]=='1')id[i]=0;
			if(s[i]=='i')id[i]=1;
			if(s[i]=='j')id[i]=2;
			if(s[i]=='k')id[i]=3;
		}
		bool ans=false;
		
		if(K_in>=32)K=K_in%32+32;
		else K=K_in;
		MM(dp,0);
		dp[0][0]=1;
		rep(i,n*K)rep(ver,3)rep(b,8)if(dp[i][ver]>>b&1)
		{
			int now=kk[b][id[i%n]];
			dp[i+1][ver]|=(1<<now);
			if(ver==0&&now==1)dp[i+1][1]|=1;
			if(ver==1&&now==2)dp[i+1][2]|=1;
			if(ver==2&&now==3&&i+1==n*K)ans=true;
		}
		printf("Case #%d: %s\n",__,ans?"YES":"NO");
	}
}