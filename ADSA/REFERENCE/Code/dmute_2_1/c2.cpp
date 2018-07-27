#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
using namespace std;

const int maxn = 10005;

int n, mat[9][9];
char str[maxn * 18];
void prep()  {
	memset(mat, 0, sizeof mat);
	mat[0][0] = 0, mat[0][1] = 1, mat[0][2] = 2, mat[0][3] = 3;
	mat[1][0] = 1, mat[1][1] = 0 + 4, mat[1][2] = 3, mat[1][3] = 2 + 4;
	mat[2][0] = 2, mat[2][1] = 3 + 4, mat[2][2] = 0 + 4, mat[2][3] = 1;
	mat[3][0] = 3, mat[3][1] = 2, mat[3][2] = 1 + 4, mat[3][3] = 0 + 4;
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
			if (i >= 4 || j >= 4)  {
				mat[i][j] = mat[i % 4][j % 4];
				if ((i >= 4) ^ (j >= 4))  mat[i][j] ^= 4;
			}
}

int num(char c)  {
	if (c == '1') return 0;
	if (c == 'i')  return 1;
	if (c == 'j')  return 2;
	return 3;
}

int go(int st, int goal)  {
	int cur = 0, i = st;
	for (i = st; i < n; i ++)  {
		cur = mat[cur][num(str[i])];
		if (cur == goal)  return i + 1;
	}
	return -1;
}

int calc(int l, int r)  {
	int cur = 0;
	for (int i = l; i < r; i ++)
		cur = mat[cur][num(str[i])];
	return cur;
}
long long cnt;
int main()  {
	int tst;
	prep();
	scanf("%d", &tst);
	for (int t = 1; t <= tst; t ++)  {
		scanf("%d%lld", &n, &cnt);
		scanf("%s", str);
	
		int len = 0;
		for (len = 12; ; len ++)
			if (len % 4 == cnt % 4)  break;
		if (cnt < len)  len = (int)cnt;
		for (int i = 1; i <= len; i ++)  {
			for (int j = 0; j < n; j ++)  str[j + i * n] = str[j];
		}
		n = len * n;
		//printf("len=%d\n",len);
		int md1 = go(0, 1);
	//	printf("md1=%d\n",md1);
		if (md1 == -1 || md1 == n)  {
				printf("Case #%d: NO\n",t);
			continue;
		}
		
		int md2 = go(md1, 2);
		if (md2 == -1 || md2 == n)  {
				printf("Case #%d: NO\n",t);
			continue;
		}
		if (calc(md2, n) == 3)  {
			printf("Case #%d: YES\n",t);
		}else printf("Case #%d: NO\n",t);

	}
}