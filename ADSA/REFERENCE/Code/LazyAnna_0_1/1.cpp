#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	int tests;
	int sMax;
	int a[2000];
	string str;
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> sMax >> str;
		int s = 0;
		int ans = 0;
		for (int j = 0; j <= sMax; ++j) {
			a[j] = str[j] - 48;
			if (s < j) {
				ans += (j - s);
				s = j;
			}
			s += a[j];
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}