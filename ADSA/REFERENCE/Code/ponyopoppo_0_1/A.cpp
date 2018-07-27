#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) repi(i, 0, a)
#define repd(i, a, b) for(int i = (a); i >= (b); i--)
#define repit(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define reprit(i, v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define UNIQUE(v) (v).erase(unique(all(v)), (v).end())
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define to_str(v) #v
using namespace std;
typedef long long ll;

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> v(n+1);
    rep(i, n+1) v[i] = s[i] - '0';

    ll sum = 0;
    ll ans = 0;
    rep(i, n+1) {
      if(sum < i) {
	ans += i-sum;
	sum = i;	
      }
      sum += v[i];
    }
    cout << "Case #" << _+1 << ": ";
    cout << ans << endl;
  }
  return 0;
}
