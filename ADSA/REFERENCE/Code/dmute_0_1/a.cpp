#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

int t, n;
char str[2005];
int main()  {
	scanf("%d", &t);
	for (int tst=1;tst<=t;tst++)  {
		scanf("%d %s", &n, str);
		int sum = 0, ans = 0;
		for (int i = 0; i <= n; i ++)  
			if (str[i] != '0')  {
				if (sum < i)  ans += i - sum, sum = i;
				sum += str[i] - '0';
			}
		printf("Case #%d: %d\n", tst, ans);
	}
	return 0;
}