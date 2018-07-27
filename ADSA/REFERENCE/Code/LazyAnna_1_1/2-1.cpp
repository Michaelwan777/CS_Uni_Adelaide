#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int tests;
	int d;
	int ans;
	int a[3000];
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> d;
		for (int i = 0; i < d; ++i) {
			cin >> a[i];
			//cout << a[i] << " ";
		}
		sort(a, a + d);
		//cout << endl; 
		ans = a[d - 1];
		for (int i = 1; i <= a[d - 1]; ++i) {
			int count = 0;
			for (int j = 0; j < d; ++j) {
				int x = a[j] / i;
				if (x * i < a[j]) ++x;
				count += (x - 1);
			}
			if (count + i < ans) ans = count + i;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}