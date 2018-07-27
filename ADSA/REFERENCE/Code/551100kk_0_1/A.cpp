#include<bits/stdc++.h>
using namespace std;
char s[1005];
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,i,j,x,y,C=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s);
        int tmp=0,ans=0;
        for(i=0;i<=n;i++){
            if(tmp<i){
                ans+=i-tmp;
                tmp=i;
            }
            tmp+=s[i]-'0';
        }
        printf("Case #%d: %d\n",++C,ans);
    }
}
