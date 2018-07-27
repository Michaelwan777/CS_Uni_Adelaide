#include<bits/stdc++.h>
using namespace std;
int s[1005];
int main(){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int i,j,k,n,m,t,x,y,C=0;
    scanf("%d",&t);
    while(t--){
        m=0;
        int ans=1000000000,tmp;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&s[i]);
            m=max(m,s[i]);
        }
        for(k=1;k<=m;k++){
            tmp=k;
            for(i=0;i<n;i++) tmp+=(s[i]-1)/k;
            ans=min(ans,tmp);
        }
        printf("Case #%d: %d\n",++C,ans);
    }
}
