#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char next(char c) {
    if(c == 'i')
        return 'j';
    else if(c == 'j')
        return 'k';
    else
        return 'i';
}

char update(char c, char nx, int &sgn) {
    if(c == '1')
        return nx;
    else if(nx == '1')
        return c;
    else if(next(c) == nx) {
        return next(nx);
    } else if(c == next(nx)) { 
        sgn = -sgn; 
        return next(c);
    } else {
        sgn = -sgn;
        return '1';
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        ll n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        int sgn = 1;
        char c = '1';
        for(int i = 0; i < n; i++)
            c = update(c, s[i], sgn); 
        if(!(c == '1' && sgn == -1 && x % 2 == 1) && !(c != '1' && x % 4 == 2)) {    
            cout << "NO" << endl;
            continue;
        }
        int cnt = 1;
        c = '1';
        sgn = 1;
        for(int _ = 0; _ < 10; _++)
            for(int i = 0; i < n; i++, cnt++) {
                c = update(c, s[i], sgn);
                if(c == 'i' && sgn == 1)
                    goto ext;
            }
ext:    if(c != 'i' || sgn != 1) {
            cout << "NO" << endl;
            continue;
        }
        int cnt2 = 1;
        c = '1';
        sgn = 1;
        for(int _ = 0; _ < 10; _++)
            for(int i = n-1; i >= 0; i--, cnt2++) {
                c = update(s[i], c, sgn);
                if(c == 'k' && sgn == 1)
                    goto ext2;
            }
ext2:   if(c != 'k' || sgn != 1) {
            cout << "NO" << endl;
            continue;
        }
        if(cnt + cnt2 < x*n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
