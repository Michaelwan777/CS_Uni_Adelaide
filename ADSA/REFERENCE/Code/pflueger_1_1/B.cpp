#include <iostream>
#include <cstdio>

using namespace std;

int P[1000];

int ciel(int a, int b) {
	return (a+b-1)/b;
}

int solve(int D) { //d = #of diners. Plate sizes stored in P.
	int best = 1000;
	//Plan: all special minutes come first.
	//Will take as many special minutes as possible to split all piles into at most k.
	//Find the best possible k.
	for (int k=1; k<=1000; k++) {
		int sum = k;
		for (int i=0; i<D; i++) {
			sum += (ciel(P[i],k)-1);
		}
		best = min(best,sum);
	}
	return best;
}

int main() {
	int T; cin >> T;
	for (int t=1; t<=T; t++) {
		int D; cin >> D;
		for (int d=0; d<D; d++) cin >> P[d];
		printf("Case #%d: %d\n",t,solve(D));
	}
}
