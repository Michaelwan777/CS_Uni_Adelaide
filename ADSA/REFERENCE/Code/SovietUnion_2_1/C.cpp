#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
class Q{
public:
	char c;
	bool flag;
	Q(){
		c = '1';
		flag = false;
	}
	void clear(){
		c = '1';
		flag = false;
	}
	inline Q operator*(const Q &rhs){
		Q ans;
		//cout << flag << " " << rhs.flag;
		ans.flag = (flag ^ rhs.flag);
		if (c == '1') ans.c = rhs.c;
		else if (c == 'i'){
			if (rhs.c == '1') ans.c = 'i';
			else if (rhs.c == 'i') ans.c = '1', ans.flag = !ans.flag;
			else if (rhs.c == 'j') ans.c = 'k';
			else ans.c = 'j', ans.flag = !ans.flag;
		}
		else if (c == 'j'){
			if (rhs.c == '1') ans.c = 'j';
			else if (rhs.c == 'i') ans.c = 'k', ans.flag = !ans.flag;
			else if (rhs.c == 'j') ans.c = '1', ans.flag = !ans.flag;
			else ans.c = 'i';
		}
		else{
			if (rhs.c == '1') ans.c = 'k';
			else if (rhs.c == 'i') ans.c = 'j';
			else if (rhs.c == 'j') ans.c = 'i', ans.flag = !ans.flag;
			else ans.c = '1', ans.flag = !ans.flag;
		}
		return ans;
	}
};
const long long N = 11000;
long long T, n, x;
Q a[N], mul;
string s;
int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	cin >> T;
	for (long long Ti = 1; Ti <= T; ++Ti){
		cin >> n >> x;
		cin >> s;
		for (long long i = 0; i < s.size(); ++i){
			a[i + 1].c = s[i];
			a[i + 1].flag = false;
		}
		mul.clear();
		for (long long i = 1; i <= n; ++i) mul = mul * a[i];
		Q tmp;
		long long nx = x % 4 + 4;
		for (long long i = 1; i <= nx; ++i) tmp = tmp * mul;
		if (tmp.c != '1' || tmp.flag != true){
			cout << "Case #" << Ti << ": NO\n";
			continue;
		}
		if (x > 100) x = 100;
		tmp.clear();
		long long min = 1000000000000000ll, max = 0;
		for (long long i = 1; i <= x; ++i)
			for (long long j = 1; j <= n; ++j){
				tmp = tmp * a[j];
				//cout << tmp.c << " " << tmp.flag << "\n";
				if (tmp.c == 'i' && tmp.flag == false)
					if ((i - 1) * n + j < min) min = (i - 1) * n + j;
				if (tmp.c == 'k' && tmp.flag == false)
					if ((i - 1) * n + j > max) max = (i - 1) * n + j;
			}
		if (min < 1000000000000000ll && max > 0 && min < max)
			cout << "Case #" << Ti << ": YES\n";
		else
			cout << "Case #" << Ti << ": NO\n";
	}
	return 0;
}
