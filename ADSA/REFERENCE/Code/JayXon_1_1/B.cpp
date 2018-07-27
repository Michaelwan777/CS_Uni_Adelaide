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


void solve_case(ifstream &fin, ofstream &fout, int case_num)
{
    int d, r = INT_MAX;
    fin >> d;
    int p[d];
    for (int i = 0; i < d; i++)
        fin >> p[i];
    sort(p, p + d);

    vector<vector<int> > dp(d, vector<int>(p[d-1]));

    for (int j = 0; j < p[d-1]; j++) {
        dp[0][j] = (p[0] + j) / (j + 1);
        for (int i = 1; i < d; i++) {
            int m = p[i];
            for (int k = 1; k <= j; k++)
                m = min(m, max(dp[i-1][j-k], (p[i] + k) / (k + 1)));
            dp[i][j] = m;
        }

        r = min(r, j + dp[d-1][j]);
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