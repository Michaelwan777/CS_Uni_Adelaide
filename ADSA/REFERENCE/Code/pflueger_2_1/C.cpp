#include <string>
#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

/*
 * Represent quaternions as follows:
 * 1 -> 0
 * i -> 1
 * j -> 2
 * k -> 3
 * -1 -> 4
 *  -i -> 5
 *  -j -> 6
 *  -k -> 7
 */

//Multiply quaternions
int mult(int a, int b) {
	if (a >= 4) {
		return (mult(a-4,b)+4)%8;
	}
	if (b >= 4) {
		return (mult(a,b-4)+4)%8;
	}
	if (a==0 || b == 0) return (a + b);
	if (a == b) return 4;
	if (a > b) return (mult(b,a)+4)%8;
	//Now can assume: 1<=a<b<=3. Three cases left.
	if (a==1 && b == 2) return 3;
	if (a==1 && b == 3) return 6;
	if (a==2 && b == 3) return 1;
}	

//Cache of multiplication, for speed
int mc[8][8];

int pow(int a, ll e) {
	if (e >= 4) return pow(a,e%4);
	if (e==0) return 0;
	else return mc[a][pow(a,e-1)];
}

string toString(int i) {
	if (i==0) return "+1";
	if (i==1) return "+i";
	if (i==2) return "+j";
	if (i==3) return "+k";
	if (i==4) return "-1";
	if (i==5) return "-i";
	if (i==6) return "-j";
	if (i==7) return "-k";
}

int toInt(char c) {
	return (c-'i'+1);
}

//Products of prefixes
//pref[i] is the product of the first i symbols (not including index i)
int pref[10000];

string doCase() {
	int prod = 0;
	ll L,X; cin >> L >> X;
	string s; cin >> s;
	for (int l=0; l<L; l++) {
		pref[l] = prod;
		prod = mc[prod][toInt(s[l])];
	}

	int total = pow(prod,X);
	if (total != 4) return "NO"; //Product must come out to -1.
	
	ll firstI = (L*X);
	ll lastK = 0;

	for (int l=0; l<L; l++) {
		int val = pref[l];
		for (int m=0; m<4 && m<X; m++) {
			if (val == 1) firstI = min(firstI,(ll)l+L*m);

			if (val == 3) {
				ll m1 = (ll)m+4*( (X-m-1)/4 );
				lastK = max(lastK,l+L*m1);
			}

			val = mc[prod][val];
		}
	}
	if (firstI < lastK) return "YES";
	else return "NO";
}

int main() {
	for (int a=0; a<8; a++) for (int b=0; b<8; b++) mc[a][b] = mult(a,b);
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		printf("Case #%d: %s\n",t,doCase().c_str());
	}
}
