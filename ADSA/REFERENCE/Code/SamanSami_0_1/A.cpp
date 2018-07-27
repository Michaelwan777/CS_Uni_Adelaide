#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {    
        int n;
        string s;
        cin >> n >> s;
        int cnt = 0;
        int req = 0;
        for(int i = 0; i < n+1; i++) {
            if(cnt < i) {
                req += i-cnt;
                cnt = i;
            }
            cnt += s[i]-'0';
        }
        cout << "Case #" << t << ": " << req << endl; 
    }
    return 0;
}
