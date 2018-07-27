#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

FILE *fin=freopen("in.txt","r",stdin);
FILE *fout=freopen("out.txt","w",stdout);

int main() {
    int T,t,n,i,j,m,ans,a[1100];
    cin>>T;
    for (t=1;t<=T;t++) {
        cin>>n;
        for (i=0;i<n;i++)
        scanf("%d",a+i);
        sort(a,a+n);
        ans=9999;
        for (m=1;m<=a[n-1];m++) {
            j=0;
            for (i=0;i<n;i++)
            j+=(a[i]-1)/m;
            ans=min(ans,j+m);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
