#include <bits/stdc++.h>

using namespace std;

int N;
char S[10001];

void _main()
{
    scanf("%d", &N);
    scanf("%s", S);
    int clap=0, ans=0;
    for(int i=0; i<=N; i++)
    {
        if(clap>=i)
            clap+=S[i]-'0';
        else
        {
            ans+=i-clap;
            clap+=S[i]-'0'+i-clap;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        _main();
    }
    return 0;
}
