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

struct quart {
  char type;
  int sign;
  quart(char type) : type(type) {
    sign = 1;
  }
  quart(char type, int sign) : type(type), sign(sign) {}
  quart right(quart o) {
    if(type == '1') return quart(o.type, sign * o.sign);
    if(o.type == '1') return quart(type, sign * o.sign);
    if(type == 'i') {
      if(o.type == 'i') return quart('1', -sign * o.sign);
      if(o.type == 'j') return quart('k',  sign * o.sign);
      if(o.type == 'k') return quart('j', -sign * o.sign);
    }
    if(type == 'j') {
      if(o.type == 'i') return quart('k', -sign * o.sign);
      if(o.type == 'j') return quart('1', -sign * o.sign);
      if(o.type == 'k') return quart('i',  sign * o.sign);
    }
    if(type == 'k') {
      if(o.type == 'i') return quart('j',  sign * o.sign);
      if(o.type == 'j') return quart('i', -sign * o.sign);
      if(o.type == 'k') return quart('1', -sign * o.sign);
    }
    cerr << "error!" << endl;
    return quart('1');
  }

  quart left(quart o) {
    if(type == '1') return quart(o.type, sign * o.sign);
    if(o.type == '1') return quart(type, sign * o.sign);
    if(type == 'i') {
      if(o.type == 'i') return quart('1', -sign * o.sign);
      if(o.type == 'j') return quart('k', -sign * o.sign);
      if(o.type == 'k') return quart('j',  sign * o.sign);
    }
    if(type == 'j') {
      if(o.type == 'i') return quart('k',  sign * o.sign);
      if(o.type == 'j') return quart('1', -sign * o.sign);
      if(o.type == 'k') return quart('i', -sign * o.sign);
    }
    if(type == 'k') {
      if(o.type == 'i') return quart('j', -sign * o.sign);
      if(o.type == 'j') return quart('i',  sign * o.sign);
      if(o.type == 'k') return quart('1', -sign * o.sign);
    }
    cerr << "error!" << endl;
    return quart('1');
  }
};

int main() {
  int T;
  cin >> T;
  rep(_, T) {
    bool ans = true;
    ll x, l;
    cin >> l >> x;
    string ori;
    cin >> ori;
    string s;
    rep(i, min(x, 6LL)) s += ori;
    
    // check
    quart unit_val('1');
    rep(i, ori.size()) {
      unit_val = unit_val.right(ori[i]);
    }
    quart val('1');
    rep(i, x%4) {
      val = val.right(unit_val);
    }
    if(val.type != '1' || val.sign != -1)
      ans = false;
    
    ll i_pos = -1;
    val = quart('1');
    // search i
    rep(i, s.size()) {
      val = val.right(quart(s[i]));
      if(val.type == 'i' && val.sign == 1) {
	i_pos = i;
	break;
      }
    }
    if(i_pos == -1) ans = false;

    ll k_pos = -1;
    val = quart('1');
    // search k
    repd(i, (int)s.size()-1, 0) {
      val = val.left(quart(s[i]));
      if(val.type == 'k' && val.sign == 1) {
	k_pos = i;
	break;
      }
    }
    if(k_pos == -1) ans = false;

    ll rk_pos = (ll)s.size() - k_pos - 1;
    if(i_pos >= x*l - rk_pos - 1)
      ans = false;
       
    cout << "Case #" << _+1 << ": ";
    if(ans) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
