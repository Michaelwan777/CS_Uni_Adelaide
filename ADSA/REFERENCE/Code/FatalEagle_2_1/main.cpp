#include <bits/stdc++.h>

using namespace std;

const int ONE=1;
const int I=2;
const int J=3;
const int K=4;
int mul[5][5];
int inv[5][5];

int N;
long long M;
char S[10000001];
int A[10000001];
int B[10000001];
set<pair<int, int>> dp, ndp;
bool possible[4][10][10][10][10][10];

inline int sgn(int x)
{
    if(x<0)
        return -1;
    return 1;
}

inline int multiply(int a, int b)
{
    return sgn(a)*sgn(b)*mul[abs(a)][abs(b)];
}

inline int powquat(int a, long long b)
{
    int ret=ONE;
    while(b)
    {
        if(b&1)
            ret=multiply(ret, a);
        a=multiply(a, a);
        b/=2;
    }
    return ret;
}

// y == x * ret
inline int getinv(int y, int x)
{
    return (sgn(y)/sgn(x))*inv[abs(y)][abs(x)];
}

inline int get(int l, int r)
{
    if(l>r)
        return ONE;
    if(l==0)
        return A[r];
    return getinv(A[r], A[l-1]);
}

bool brute()
{
    for(int i=1; i<M; i++)
        for(int j=0; j<N; j++)
            A[j+i*N]=A[j];
    N*=M;
    if(N<3)
        return false;
    dp.clear();
    ndp.clear();
    ndp.insert({A[0], A[1]});
    for(int i=1; i<N; i++)
        A[i]=multiply(A[i-1], A[i]);
    for(int i=2; i<N; i++)
    {
        if(ndp.count({I, J}) && get(i, N-1)==K)
            return true;
        dp.insert({get(0, i-1), get(i, i)});
        for(auto& it: ndp)
            dp.insert({it.first, multiply(it.second, get(i, i))});
        dp.swap(ndp);
        dp.clear();
    }
    return false;
}

bool solve()
{
    if(N*M<3)
        return false;
    for(int i=1; i<N; i++)
        A[i]=multiply(A[i-1], A[i]);
    for(int i=0; i<N; i++)
        B[i]=get(i, N-1);
/*
pow(X, a) * get(0, l) == I
get(l+1, N-1) * pow(X, b) * get(0, r-1) == J
get(r, N-1) * pow(X, c) == K
*/

    const int X=A[N-1];
    int target=(M-2)%4;
    for(int l=0; l<N; l++)
    {
        const int a=A[l];
        const int b=(l==N-1)?ONE:B[l+1];
        for(int r=0; r<N; r++)
        {
            const int c=r?A[r-1]:ONE;
            const int d=B[r];
            if(possible[target][X+4][a+4][b+4][c+4][d+4])
                return true;
        }
    }
    return false;
}

void _main()
{
#if 0
    N=10000;
    M=1000000000000LL;
    for(int i=0; i<N; i++)
        S[i]='i'+(i%3);
#else
    scanf("%d%lld%s", &N, &M, S);
#endif
    for(int i=0; i<N; i++)
    {
        if(S[i]=='i')
            A[i]=I;
        else if(S[i]=='j')
            A[i]=J;
        else if(S[i]=='k')
            A[i]=K;
        else
            assert(0);
    }
    if(M<=70)
    {
        if(brute())
            printf("YES\n");
        else
            printf("NO\n");
    }
    else
    {
        if(solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main()
{
    mul[ONE][ONE]=ONE, mul[ONE][I]=I, mul[ONE][J]=J, mul[ONE][K]=K;
    mul[I][ONE]=I, mul[I][I]=-ONE, mul[I][J]=K, mul[I][K]=-J;
    mul[J][ONE]=J, mul[J][I]=-K, mul[J][J]=-ONE, mul[J][K]=I;
    mul[K][ONE]=K, mul[K][I]=J, mul[K][J]=-I, mul[K][K]=-ONE;
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++)
            inv[abs(mul[i][j])][i]=sgn(mul[i][j])*j;
    for(int X=-4; X<=4; X++) if(X)
        for(int i=-4; i<=4; i++) if(i)
            for(int j=-4; j<=4; j++) if(j)
                for(int k=-4; k<=4; k++) if(k)
                    for(int l=-4; l<=4; l++) if(l)
                        for(int a=0; a<4; a++) if(multiply(powquat(X, a), i)==I)
                            for(int b=0; b<4; b++) if(multiply(j, multiply(powquat(X, b), k))==J)
                                for(int c=0; c<4; c++) if(multiply(l, powquat(X, c))==K)
                                    possible[(a+b+c)%4][X+4][i+4][j+4][k+4][l+4]=true;
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int T;
#if 0
    T=100;
#else
    scanf("%d", &T);
#endif
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}
