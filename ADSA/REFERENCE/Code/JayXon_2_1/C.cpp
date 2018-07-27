#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdint>
#include <vector>

using namespace std;

char multiply(char a, char b)
{
    if (a < 0)
        return -multiply(-a, b);
    if (b < 0)
        return -multiply(a, -b);
    if (a == 1)
        return b;
    if (b == 1)
        return a;
    if (a == b)
        return -1;
    if (a > b)
        return -multiply(b, a);
    if (b == 'j')
        return 'k';
    return a == 'i' ? -'j' : 'i';
}

void solve_case(ifstream &fin, ofstream &fout, int case_num)
{
    int64_t l, x;
    string s;
    fin >> l >> x >> s;

    char t = 1;
    for (auto c : s)
        t = multiply(t, c);

    int n = 0, i = 0, nothing = 0;
    char c = 1;
    while (x && n < 3) {
        while (i < s.size() && c != 'i' + n)
            c = multiply(c, s[i++]);
        if (i == s.size()) {
            i = 0;
            x--;
            nothing++;
            if (nothing > 4)
                x %= 4;
        }
        if (c == 'i' + n) {
            n++;
            c = 1;
            nothing = 0;
        }
    }
    if (n == 3) {
        c = 1;
        if (i) {
            while (i < s.size())
                c = multiply(c, s[i++]);
            x--;
        }
        x %= 4;
        while (x--) {
            c = multiply(c, t);
        }
    }
    cout << x << ' ' << c << ' ' << n << endl;
    fout << "Case #" << case_num << ": ";
    fout << ((n == 3 && c == 1) ? "YES" : "NO") << endl;

}


int main(int argc, char const *argv[])
{
    if (argc != 2)
        return 1;
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
        return 1;

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t) {
        cerr << "Solving case " << t1 << endl;
        solve_case(fin, fout, t1);
    }

    return 0;
}