#include <cstdio>
using namespace std;

const int maxl = 10000;
char str[maxl +1];

enum quat {
	QUAT_1 = 0,
	QUAT_I = 1,
	QUAT_J = 2,
	QUAT_K = 3,
	QUAT_1_NEG = 4,
	QUAT_I_NEG = 5,
	QUAT_J_NEG = 6,
	QUAT_K_NEG = 7,
};

enum quat quat_letter(char c)
{
	switch (c) {
		break;case '1': return QUAT_1;
		break;case 'i': return QUAT_I;
		break;case 'j': return QUAT_J;
		break;case 'k': return QUAT_K;
	}
}

enum quat quat_rmul(enum quat *q, enum quat r)
{
	bool neg = false;
	if (*q >= 4) {
		neg = !neg;
		*q = (enum quat) (*q - 4);
	}
	if (r >= 4) {
		neg = !neg;
		r = (enum quat) (r - 4);
	}
	switch (*q) {
		break;case QUAT_1: switch (r) {
			break;case QUAT_1: *q = QUAT_1;
			break;case QUAT_I: *q = QUAT_I;
			break;case QUAT_J: *q = QUAT_J;
			break;case QUAT_K: *q = QUAT_K;
		}
		break;case QUAT_I: switch (r) {
			break;case QUAT_1: *q = QUAT_I;
			break;case QUAT_I: *q = QUAT_1_NEG;
			break;case QUAT_J: *q = QUAT_K;
			break;case QUAT_K: *q = QUAT_J_NEG;
		}
		break;case QUAT_J: switch (r) {
			break;case QUAT_1: *q = QUAT_J;
			break;case QUAT_I: *q = QUAT_K_NEG;
			break;case QUAT_J: *q = QUAT_1_NEG;
			break;case QUAT_K: *q = QUAT_I;
		}
		break;case QUAT_K: switch (r) {
			break;case QUAT_1: *q = QUAT_K;
			break;case QUAT_I: *q = QUAT_J;
			break;case QUAT_J: *q = QUAT_I_NEG;
			break;case QUAT_K: *q = QUAT_1_NEG;
		}
	}
	if (neg) {
		neg = !neg;
		*q = (enum quat) ((*q + 4) % 8);
	}
}

enum quat quat_lmul(enum quat *q, enum quat l)
{
	bool neg = false;
	if (*q >= 4) {
		neg = !neg;
		*q = (enum quat) (*q - 4);
	}
	if (l >= 4) {
		neg = !neg;
		l = (enum quat) (l - 4);
	}
	switch (l) {
		break;case QUAT_1: switch (*q) {
			break;case QUAT_1: *q = QUAT_1;
			break;case QUAT_I: *q = QUAT_I;
			break;case QUAT_J: *q = QUAT_J;
			break;case QUAT_K: *q = QUAT_K;
		}
		break;case QUAT_I: switch (*q) {
			break;case QUAT_1: *q = QUAT_I;
			break;case QUAT_I: *q = QUAT_1_NEG;
			break;case QUAT_J: *q = QUAT_K;
			break;case QUAT_K: *q = QUAT_J_NEG;
		}
		break;case QUAT_J: switch (*q) {
			break;case QUAT_1: *q = QUAT_J;
			break;case QUAT_I: *q = QUAT_K_NEG;
			break;case QUAT_J: *q = QUAT_1_NEG;
			break;case QUAT_K: *q = QUAT_I;
		}
		break;case QUAT_K: switch (*q) {
			break;case QUAT_1: *q = QUAT_K;
			break;case QUAT_I: *q = QUAT_J;
			break;case QUAT_J: *q = QUAT_I_NEG;
			break;case QUAT_K: *q = QUAT_1_NEG;
		}
	}
	if (neg) {
		neg = !neg;
		*q = (enum quat) ((*q + 4) % 8);
	}
}

bool solve()
{
	int l;
	long long x;
	scanf("%i%lli%s", &l, &x, str);
	int y = (int) (x % 4);
	enum quat total = QUAT_1;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < l; j++) {
			quat_rmul(&total, quat_letter(str[j]));
		}
	}
	if (QUAT_1_NEG == total)
		goto a;
	//printf("Wrong total. ");
	return false;
a:
	enum quat left = QUAT_1;
	int left_pos = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < l; j++) {
			left_pos++;
			quat_rmul(&left, quat_letter(str[j]));
			if (QUAT_I == left)
				goto b;
		}
	}
	//printf("Wrong left. ");
	return false;
b:
	enum quat right = QUAT_1;
	int right_pos = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < l; j++) {
			right_pos++;
			quat_lmul(&right, quat_letter(str[l - j -1]));
			if (QUAT_K == right)
				goto c;
		}
	}
	//printf("Wrong right. ");
	return false;
c:
	//printf("[%i %i] ", left_pos, right_pos);
	return left_pos + right_pos < l * x;
}

int main()
{
	int t;
	scanf("%i", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%i: ", i +1);
		printf("%s", solve()? "YES": "NO");
		printf("\n");
	}
	return 0;
}

