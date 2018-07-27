#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((int) (x).size())

template<class T>
vector<T> splitstr(const string &s)
{
    istringstream in(s);
    vector<T> out;
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
    return out;
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        int fd = open(argv[1], O_RDONLY);
        if (fd == -1) { perror(argv[1]); exit(1); }
        if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
        if (-1 == close(fd)) { perror(argv[1]); exit(1); }
    }

    if (argc > 2)
    {
        int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
        if (fd == -1) { perror(argv[2]); exit(1); }
        if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
        if (-1 == close(fd)) { perror(argv[2]); exit(1); }
    }

    ios::sync_with_stdio(false);
    cin.exceptions(ios::failbit | ios::badbit);
}

/*** END OF TEMPLATE CODE ***/

int ptable[4][4] =
{
    {0, 1, 2, 3},
    {1, 4, 3, 6},
    {2, 7, 4, 1},
    {3, 2, 5, 4}
};

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int table[8][8];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            table[i][j] = ptable[i][j];
            table[i + 4][j] = ptable[i][j] ^ 4;
            table[i][j + 4] = ptable[i][j] ^ 4;
            table[i + 4][j + 4] = ptable[i][j];
        }

    int cases;
    cin >> cases;
    for (int cas = 0; cas < cases; cas++)
    {
        int L;
        ll X;
        string word;
        cin >> L >> X >> word;
        if (X >= 36)
            X = X % 4 + 32;

        int need = 1;
        int cur = 0;
        int tcur = 0;
        for (ll i = 0; i < X; i++)
            for (char c : word)
            {
                int idx = c - 'h';
                cur = table[cur][idx];
                tcur = table[tcur][idx];
                if (cur == need)
                {
                    cur = 0;
                    need++;
                }
            }
        bool ans = need > 3 && tcur == 4;
        cout << "Case #" << cas + 1 << ": " << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}
