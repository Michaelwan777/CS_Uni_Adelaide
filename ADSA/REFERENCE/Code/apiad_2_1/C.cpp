#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int bb[4][4]={{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};
int b[10][10];
int n,t[10100],_,__;
char s[10100];
ll k;
bool gao() {
	int r=0,pt=0;
	while (pt<k*n&&r!=1) r=b[r][t[(pt++)%n]];
	if (pt==k*n) return 0;
	while (pt<k*n&&r!=3) r=b[r][t[(pt++)%n]];
	if (pt==k*n) return 0;
	while (pt<k*n) r=b[r][t[(pt++)%n]];	
	if (r!=4) return 0;
	return 1;
}
int main() {
	rep(i,0,8) rep(j,0,8) if ((i<4)^(j<4)) b[i][j]=bb[i%4][j%4]^4;
		else b[i][j]=bb[i%4][j%4];
	for (scanf("%d",&_);_;_--) {
		scanf("%d%I64d",&n,&k);
		k=min(k,20+k%4);
		scanf("%s",s);
		rep(i,0,n) if (s[i]=='i') t[i]=1; else if (s[i]=='j') t[i]=2; else t[i]=3;
		printf("Case #%d: %s\n",++__,gao()?"YES":"NO");
	}
}
