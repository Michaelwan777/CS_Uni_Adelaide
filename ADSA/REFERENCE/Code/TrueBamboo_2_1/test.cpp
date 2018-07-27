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

struct ee{
       char c;
       int p;
};
char s[11000];

inline ee mul(ee a,char ch) {
       if (a.c=='1')
       a.c=ch;
       else if (a.c==ch) {
            a.c='1';
            a.p*=-1;
       }
       else {
            int k=a.c-'i'+ch-'i';
            if (k==1) {
                a.c='k';
                if (ch=='i')
                a.p*=-1;
            }
            if (k==2) {
                a.c='j';
                if (ch=='k')
                a.p*=-1;
            }
            if (k==3) {
                a.c='i';
                if (ch=='j')
                a.p*=-1;
            }
       }
       return a;
}

int main() {
    int T,t,n,i,j,k,l,x;
    long long xx;
    cin>>T;
    for (t=1;t<=T;t++) {
        cin>>l>>xx;
        x=(int)(min(xx%4+12,xx));
        scanf("%s",s);
        ee ans;
        ans.c='1';
        ans.p=1;
        i=j=0;
        for (;x;x--)
        for (k=0;k<l;k++) {
            ans=mul(ans,s[k]);
            if (ans.p==1 && ans.c=='i')
            i=1;
            else if (ans.p==1 && ans.c=='k' && i)
            j=1;
        }
        if (i && j && ans.p==-1 && ans.c=='1')
        printf("Case #%d: YES\n",t);
        else printf("Case #%d: NO\n",t);
    }
    return 0;
}
