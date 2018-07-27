#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdint>

using namespace std;

void solve_case(ifstream &fin, ofstream &fout, int case_num)
{
    int smax, r = 0, sum = 0;
    string s;
    fin >> smax >> s;

    sum = s[0] - '0';
    for (int i = 1; i <= smax; i++) {
        if (sum < i) {
            r += i - sum;
            sum = i;
        }
        sum += s[i] - '0';
    }

    fout << "Case #" << case_num << ": ";
    fout << r << endl;

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