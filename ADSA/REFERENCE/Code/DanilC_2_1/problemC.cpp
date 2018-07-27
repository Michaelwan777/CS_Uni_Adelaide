#include <exception>
#include <iostream>
#include <iomanip>

template<typename T>
void validate(T parameter, T min, T max) {
	if(parameter < min && parameter > max)
		throw std::exception("invalid parameter");
}

enum Qmin {
	plus_one  = 0,
	plus_i    = 1,
	plus_j    = 2,
	plus_k    = 3,
	minus_one = 4,
	minus_i   = 5,
	minus_j   = 6,
	minus_k   = 7
};

class Problem {
	Qmin* str;
	long long X;
	int L;
	Qmin sumStr;

	static Qmin multbuff[8*3];//need to multiply by i,j or k only
	inline static int Qindex(Qmin f, Qmin s) { return (int)f + 8 * ((int)s - 1); }
public:
	static void prepare() {
		multbuff[Qindex(plus_one,plus_i)] = plus_i;
		multbuff[Qindex(plus_i  ,plus_i)] = minus_one;
		multbuff[Qindex(plus_j  ,plus_i)] = minus_k;
		multbuff[Qindex(plus_k  ,plus_i)] = plus_j;
		multbuff[Qindex(minus_one,plus_i)] = minus_i;
		multbuff[Qindex(minus_i  ,plus_i)] = plus_one;
		multbuff[Qindex(minus_j  ,plus_i)] = plus_k;
		multbuff[Qindex(minus_k  ,plus_i)] = minus_j;

		multbuff[Qindex(plus_one,plus_j)] = plus_j;
		multbuff[Qindex(plus_i  ,plus_j)] = plus_k;
		multbuff[Qindex(plus_j  ,plus_j)] = minus_one;
		multbuff[Qindex(plus_k  ,plus_j)] = minus_i;
		multbuff[Qindex(minus_one,plus_j)] = minus_j;
		multbuff[Qindex(minus_i  ,plus_j)] = minus_k;
		multbuff[Qindex(minus_j  ,plus_j)] = plus_one;
		multbuff[Qindex(minus_k  ,plus_j)] = plus_i;

		multbuff[Qindex(plus_one,plus_k)] = plus_k;
		multbuff[Qindex(plus_i  ,plus_k)] = minus_j;
		multbuff[Qindex(plus_j  ,plus_k)] = plus_i;
		multbuff[Qindex(plus_k  ,plus_k)] = minus_one;
		multbuff[Qindex(minus_one,plus_k)] = minus_k;
		multbuff[Qindex(minus_i  ,plus_k)] = plus_j;
		multbuff[Qindex(minus_j  ,plus_k)] = minus_i;
		multbuff[Qindex(minus_k  ,plus_k)] = plus_one;
	}
	static inline Qmin mult(Qmin f, Qmin s) {
		return multbuff[Qindex(f,s)];
	}
	static inline Qmin power(Qmin f, int x) {
		switch(x%4) {
		case 0: 
			return plus_one;
		case 1: 
			return f;
		case 2: 
			switch(f) {
			case plus_one:
			case minus_one:
				return plus_one;
			default:
				return minus_one;
			}
		case 3: 
			switch(f) {
			case plus_one:
			case minus_one:
				return f;
			default:
				return (Qmin) (( (int)f + 4)%8); //-f
			}
		default:
			throw new std::exception("should be impossible to have another reminder");
		}
	}

	void read(std::istream& in) {
		in >> L >> X;
		validate(L, 1, 10000);
		validate(X, 1ll, 1000000000000ll);
		validate(X*L, 1ll, 10000000000000000ll);
		str = new Qmin[L];
		//stupid way to read a given length string, but should work
		char space;
		for(int i = 0; i < L; ++i) {
			in >> space;
			switch(space) {
			case 'i': str[i] = plus_i; break;
			case 'j': str[i] = plus_j; break;
			case 'k': str[i] = plus_k; break;
			default: --i; break;
			}
		}
		sumStr = plus_one;
		for(int i = 0; i < L; ++i)
			sumStr = mult(sumStr, str[i]);
	}
private:
	int iL, iX;
	bool result;
public:
	bool find(Qmin target) {
		if(iX == X)
			return false;

		int check_total_max = L * 4; //anything power to 4 is equal to one. so if not found in 4 cyckes => not found at all
		Qmin now = plus_one;
		for(; check_total_max > 0; --check_total_max) {
			now = mult(now, str[iL]);
			if(++iL == L) {
				++iX;
				iL = 0;
			}
			if(now == target)
				return true;
			if(iX == X)
				return false;
		}
		return false;
	}
	void solve() {
		//step one, search i;
		iL = iX = 0;
		//total result should be -1;
		if( power(sumStr, X%4) != minus_one) {
			result = false;
		}
		else {
			result = find(plus_i) &&
				     find(plus_j) &&
					 find(plus_k); 
			//rest should be one (and added to last j) because already checked that total is minus one
		}
	}
	void print(std::ostream& out) {
		out << (result ? "YES": "NO") << std::endl;
	}
};

Qmin Problem::multbuff[8*3];


int main(int argc, char** argv) {
	try {
		Problem::prepare();
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