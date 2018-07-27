#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int a[4][4][2] =   {{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
				  	{{1, 0}, {0, 1}, {3, 0}, {2, 1}},
				  	{{2, 0}, {3, 1}, {0, 1}, {1, 0}},
				  	{{3, 0}, {2, 0}, {1, 1}, {0, 1}}};

struct Foo
{
     int q1;
     int q2;
};

Foo mult(int x1, int x2, long long x) {
	Foo ans;
	if (x == 1) {
		ans.q1 = x1;
		ans.q2 = x2;
		return ans;
	}
	ans.q1 = 0;
	ans.q2 = 0;
	if (x % 2 == 1) {
		ans.q1 = x1;
		ans.q2 = x2;
	}
	long long w = x / 2;
	Foo sub = mult(x1, x2, w);
	ans.q2 = (a[sub.q1][ans.q1][1] + sub.q2 + ans.q2) % 2;
	ans.q1 = a[sub.q1][ans.q1][0];
	ans.q2 = (a[sub.q1][ans.q1][1] + sub.q2 + ans.q2) % 2;
	ans.q1 = a[sub.q1][ans.q1][0];
	return ans;
}

int main() {
	int tests;
	cin >> tests;
	long long x, l;
	string str;

	for (int t = 1; t <= tests; ++t) {
		cin >> l >> x;
		cin >> str;
		if (str.length() == 1) {
			cout << "Case #" << t << ": NO" << endl;
			continue;
		}

		if (x <= 8) {
			string str1 = str;
			for (int i = 0; i < x - 1; ++i)
				str += str1;
			int count = str.length() + 1;
			int x1 = 0;
			int x2 = 0;		
			for (int i = 0; i < str.length(); ++i) {
				x2 = (a[x1][str[i] - 'a' - 7][1] + x2) % 2;
				x1 = a[x1][str[i] - 'a' - 7][0];
				if ((x1 == 1) &&  (x2 == 0)) {
					count = i + 1;
					break;
				}
			}
			int y1 = 0;
			int y2 = 0;		
			for (int i = str.length(); i >= 1; --i) {
				y2 = (a[str[i - 1] - 'a' - 7][y1][1] + x2) % 2;
				y1 = a[str[i - 1] - 'a' - 7][y1][0];
				if ((y1 == 3) &&  (y2 == 0)) {
					count += (str.length() - i + 1);
					break;
				}
			}

			x1 = a[str[0] - 'a' - 7][str[1] - 'a' - 7][0];
			x2 = a[str[0] - 'a' - 7][str[1] - 'a' - 7][1];		
			for (int i = 2; i < str.length(); ++i) {
				x2 = (a[x1][str[i] - 'a' - 7][1] + x2) % 2;
				x1 = a[x1][str[i] - 'a' - 7][0];
			}

			if ((count < str.length()) && (x1 == 0) && (x2 == 1)) {
				cout << "Case #" << t << ": YES" << endl;
			} else {
				cout << "Case #" << t << ": NO" << endl;
			}

		} else {
			int x1 = a[str[0] - 'a' - 7][str[1] - 'a' - 7][0];
			int x2 = a[str[0] - 'a' - 7][str[1] - 'a' - 7][1];		
			for (int i = 2; i < str.length(); ++i) {
				x2 = (a[x1][str[i] - 'a' - 7][1] + x2) % 2;
				x1 = a[x1][str[i] - 'a' - 7][0];
			}

			int i1 = 0;
			int i2 = 0;
			bool flagi = false;
			for (int i = 0; i < 4; ++i) {
				int j1 = i1;
				int j2 = i2;
				for (int j = 0; j < str.length(); ++j) {
					if ((j1 == 1) && (j2 == 0)) {
						flagi = true;
						break;
					}
					j2 = (a[j1][str[j] - 'a' - 7][1] + j2) % 2;
					j1 = a[j1][str[j] - 'a' - 7][0];
				}
				if (flagi) break;
				i2 = (a[i1][x1][1] + x2 + i2) % 2;
				i1 = a[i1][x1][0];
			}

			int k1 = 0;
			int k2 = 0;
			bool flagk = false;
			for (int i = 0; i < 4; ++i) {
				int j1 = k1;
				int j2 = k2;
				for (int j = str.length(); j >= 1; --j) {
					if ((j1 == 3) && (j2 == 0)) {
						flagk = true;
						break;
					}
					j2 = (a[str[j - 1] - 'a' - 7][j1][1] + j2) % 2;
					j1 = a[str[j - 1] - 'a' - 7][j1][0];
				}
				if (flagk) break;
				k2 = (a[x1][k1][1] + x2 + k2) % 2;
				k1 = a[x1][k1][0];
			}

			Foo q = mult(x1, x2, x);
			if ((flagi) && (flagk) && (q.q1 == 0) && (q.q2 == 1)) {
				cout << "Case #" << t << ": YES" << endl;
			} else {
				cout << "Case #" << t << ": NO" << endl;
			}

		}

	}
	return 0;
}