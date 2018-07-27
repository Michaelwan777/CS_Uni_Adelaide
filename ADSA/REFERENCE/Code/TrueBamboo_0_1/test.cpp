#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
using namespace std;

FILE *fin=freopen("in.txt","r",stdin);
FILE *fout=freopen("out.txt","w",stdout);

int main() {
    int T,t,n,i,s,m,p;
    char a[1100];
    cin>>T;
    for (t=1;t<=T;t++) {
        scanf("%d%s",&n,a);
        s=a[0]-'0';
        m=0;
        for (i=1;i<=n;i++) {
            p=max(0,i-s);
            m+=p;
            s+=a[i]-'0'+p;
        }
        printf("Case #%d: %d\n",t,m);
    }
    return 0;
}
