#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#endif

using namespace std;


namespace{

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int tbl[8][8] = {
	{0, 1, 2, 3},
	{1, 4, 3, 6},
	{2, 7, 4, 1},
	{3, 2, 5, 4},
};

void prepare(){
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			tbl[i][j + 4] = (tbl[i][j] + 4) & 7;
		}
		for(int j = 0; j < 8; ++j){
			tbl[i + 4][j] = (tbl[i][j] + 4) & 7;
		}
	}
}


string solve(){
	bool ok = false;
	
	LL len, x;
	string s;
	cin >> len >> x >> s;
	x -= max(x - 20, 0LL) / 4 * 4;
	vint v;
	v.reserve(len * x);
	int t = 0;
	for(LL i = 0; i < x; ++i)
	for(LL j = 0; j < len; ++j){
		v.push_back(s[j] - 'h');
		t = tbl[t][v.back()];
	}
	
	if(t == 4){
		int mini = 1010101010, maxk = -1;

		t = 0;
		for(int i = 0; i < (int)v.size(); ++i){
			t = tbl[t][v[i]];
			if(t == 1){
				mini = i;
				break;
			}
		}

		t = 0;
		for(int i = v.size(); i--; ){
			t = tbl[v[i]][t];
			if(t == 3){
				maxk = i;
				break;
			}
		}
		
		ok = mini + 1 < maxk;
	}
	
	return ok ? "YES" : "NO";
}


}
int main(){
	cout << fixed << setprecision(15);
	cerr << fixed << setprecision(6);
	prepare();

	int T = 0;
	cin >> T;
	for(int cnum = 1; cnum <= T; ++cnum){
		fprintf(stderr, "%4d / %d\n", cnum, T);
		cout << "Case #" << cnum << ": " << flush;
		auto ans = solve();
		cout << ans << endl;
	}
}
