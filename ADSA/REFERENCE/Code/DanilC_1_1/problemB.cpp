#include <exception>
#include <iostream>
#include <iomanip>

template<typename T>
void validate(T parameter, T min, T max) {
	if(parameter < min && parameter > max)
		throw std::exception("invalid parameter");
}

class Problem {
	int D;
	int min_minutes;
	int* P;
public:
	Problem() { P = nullptr; }
	~Problem() { if(P) delete[] P; }
	void read(std::istream& in) {
		in >> D;
		min_minutes = 0;
		validate(D, 1, 1000);

		if(P) delete[] P;
		P = new int[D];

		for(int i = 0; i < D; ++i) {
			in >> P[i];
			validate(P[i], 1, 1000);
			if(P[i] > min_minutes)
				min_minutes = P[i];
		}
	}
	void solve() {
		for(int eat = 1; eat < min_minutes; ++eat) {
			int special = 0;
			for(int i = 0; i < D; ++i) {
				special += (P[i]-1) / eat; //number of groups to devide to is one above
			}
			if(special + eat < min_minutes) {
				min_minutes = special + eat;
			}

		}
#if WRONG_SOLUTIION
		for(int special = 1; special < min_minutes; ++special) {
			int newP1 = maxP/2;
			int newP2 = maxP - newP1;
			P[maxP]--;
			P[newP1]++;
			P[newP2]++;
			while(P[maxP] == 0) --maxP;
			if(special + maxP < min_minutes) {
				min_minutes = special + maxP;
#if false
				std::cerr << special <<  '+' << maxP << ':';
				for(int i = maxP; i>0; --i)
					for(int j = 0; j < P[i]; ++j)
						std::cerr << i << ' ';
				std::cerr << std::endl;
#endif
			}
		}
#endif
	}
	void print(std::ostream& out) {
		out << min_minutes << std::endl;
	}
};


int main(int argc, char** argv) {
	try {
		int T;
		std::cin >> T;
		validate(T, 1, 100);

		for(int iT = 1; iT <= T; ++iT) {
			Problem p;
			p.read(std::cin);
			p.solve();
			std::cout << "Case #" << iT << ": ";
			p.print(std::cout);
		}

	}
	catch(std::exception& x) {
		std::cerr << "something went wrong: " << x.what();
	}
	return 0;
}