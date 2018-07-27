#include <exception>
#include <iostream>
#include <iomanip>

template<typename T>
void validate(T parameter, T min, T max) {
	if(parameter < min && parameter > max)
		throw std::exception("invalid parameter");
}

class Problem {
	int* s;
	int smax;
	int extra;
public:
	Problem() {
		s = nullptr;
	}
	~Problem() {
		if(nullptr != s) delete[] s;
	}
	void read(std::istream& in) {
		in >> smax;
		s = new int[smax+1];
		for(int i = 0; i <= smax;) {
			char c;
			in >> c;
			if(c >= '0' && c <= '9') s[i++] = c - '0';
		}
	}
	void solve() {
		extra = 0;
		int total = 0;
		for(int i = 0; i <= smax; ++i) {
			int delta_extra = (total < i) ?  (i-total): 0;
			total += s[i];
			total += delta_extra;
			extra += delta_extra;
		}
	}
	void print(std::ostream& out) {
		out << extra << std::endl;
	}
};


int main(int argc, char** argv) {
	try {
		int T;
		std::cin >> T;
		validate(T, 1, 100);
		std::cout << std::setprecision(7) << std::fixed;

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