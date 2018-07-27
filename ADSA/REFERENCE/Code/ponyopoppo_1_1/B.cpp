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

template<class X>
ostream& operator<<(ostream& os, const vector<X> &v) {
  repit(itr, v) cout << *itr << " ";
  cout << " size : " << v.size();;
  return os;
}

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    int n;
    cin >> n;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll maxy = 0;
    rep(i, n) maxy = max(maxy, x[i]);
    ll ans = maxy;
    repi(y, 1, maxy+1) {
      ll sum = y;
      rep(i, n) sum += (x[i]-1)/y;
      ans = min(ans, sum);
    }
    cout << "Case #" << _+1 << ": ";
    cout << ans << endl;
  }
  
  return 0;
}
