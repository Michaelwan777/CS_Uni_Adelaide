#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		int N; cin >> N;
		string s; cin >> s;
		int res = 0;
		int sum = 0;
		for (int k=0; k<=N; k++) {
			res = max(res,k-sum);
			sum += (s[k]-'0');
		}
		printf("Case #%d: %d\n",t,res);
	}
}
