#include <bits/stdc++.h>

using namespace std;

int N;
int A[10001];

void _main()
{
    scanf("%d", &N);
    int mx=0;
    for(int i=0; i<N; i++)
        scanf("%d", A+i), mx=max(mx, A[i]);
    int ans=0x3f3f3f3f;
    for(int i=1; i<=mx; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int tmp=j;
            for(int k=0; k<N; k++)
                tmp+=(A[k]+j-1)/j-1;
            ans=min(ans, tmp);
        }
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}
