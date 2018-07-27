// B - Infinite House of Pancakes

#include <iostream>
#include <fstream>
using namespace std;

int n;
int diner[1005];

int main()
{
    ifstream fin ( "B-large.in" );
    ofstream fout ( "B-large.txt" );
    int t;
    fin >> t;
    for ( int h = 1; h <= t; h++ )
    {
        fin >> n;
        int mx = 0;
        for ( int i = 0; i < n; i++ )
        {
            fin >> diner[i];
            mx = ( mx > diner[i] ) ? mx : diner[i];
        }
        int mn = 999999999;
        for ( int i = 1; i <= mx; i++ )
        {
            int cnt = 0;
            for ( int j = 0; j < n; j++ ) cnt += ( diner[j] - 1 ) / i;
            cnt += i;
            mn = ( mn < cnt ) ? mn : cnt;
        }
        fout << "Case #" << h << ": " << mn << endl;
    }
    return 0;
}
