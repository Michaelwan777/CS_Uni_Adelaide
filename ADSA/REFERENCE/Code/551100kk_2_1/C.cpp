#include<bits/stdc++.h>
using namespace std;
char in[100005];
int tra[5][5]={
{0,0,0,0,0},
{0,1,2,3,4},
{0,2,-1,4,-3},
{0,3,-4,-1,2},
{0,4,3,-2,-1}
};
vector<int> arr,s;
int main(){
    freopen("C-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n,x,y,i,j,k,C=0;
    long long int m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&m);
        if(m>11) m=8+m%4;
        scanf("%s",in);
        arr.clear(),s.clear();
        for(i=0;i<n;i++){
            if(in[i]=='i') s.push_back(2);
            if(in[i]=='j') s.push_back(3);
            if(in[i]=='k') s.push_back(4);
        }
        while(m--){
            for(i=0;i<n;i++){
                arr.push_back(s[i]);
            }
        }
        int tmp=1,flag=0,f1=0,f2=0,f3=0;
        for(i=0;i<arr.size();i++){
            tmp=tra[tmp][arr[i]];
            if(tmp<0) tmp*=-1,flag^=1;
            if(tmp==2 && flag==0) f1=1;
            if(tmp==4 && flag==0 && f1) f2=1;
            if(tmp==1 && flag==1 && f2 && i==arr.size()-1) f3=1;
        }
        printf("Case #%d: %s\n",++C,f3?"YES":"NO");

    }
}
