#include <bits/stdc++.h>
using namespace std;

const int MAXn = 1005;
int a[MAXn];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int mn = 1e9;
        for(int i = 1; i <= 1000; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++)
                cnt += ((a[j]+i-1) / i - 1);
            mn = min(mn, cnt+i);
        }
        cout << "Case #" << t << ": " << mn << endl;
    }
    return 0;
}
