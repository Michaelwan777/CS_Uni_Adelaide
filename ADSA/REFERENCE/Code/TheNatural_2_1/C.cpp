// C - Dijkstra

#include <iostream>
#include <fstream>
using namespace std;

long long l;
long long x;
long long abb;
int s[10005];
int mult[4][4] =
{
    { 0, 1, 2, 3 },
    { 1, 4, 3, 6 },
    { 2, 7, 4, 1 },
    { 3, 2, 5, 4 }
};

int prod ( int a, int b )
{
    int m = mult[a % 4][b % 4];
    if ( ( a > 3 ) ^ ( b > 3 ) ) m = ( m + 4 ) % 8;
    return m;
}

int main()
{
    ifstream fin ( "C-large.in" );
    ofstream fout ( "C-large.txt" );
    int t;
    fin >> t;
    for ( int h = 1; h <= t; h++ )
    {
        fin >> l >> x;
        char c;
        for ( long long i = 0; i < l; i++ )
        {
            fin >> c;
            if ( c == 'i' ) s[i] = 1;
            else if ( c == 'j' ) s[i] = 2;
            else s[i] = 3;
        }
        abb = ( x < ( x % 4 + 12 ) ) ? x : ( x % 4 + 12 );
        int p = 0;
        int pos = 0;
        while ( pos < abb * l && p != 1 )
        {
            p = prod ( p, s[pos % l] );
            pos++;
        }
        if ( p != 1 )
        {
            fout << "Case #" << h << ": NO" << endl;
            continue;
        }
        p = 0;
        while ( pos < abb * l && p != 2 )
        {
            p = prod ( p, s[pos % l] );
            pos++;
        }
        if ( p != 2 )
        {
            fout << "Case #" << h << ": NO" << endl;
            continue;
        }
        p = 0;
        while ( pos < abb * l )
        {
            p = prod ( p, s[pos % l] );
            pos++;
        }
        if ( p != 3 )
        {
            fout << "Case #" << h << ": NO" << endl;
            continue;
        }
        fout << "Case #" << h << ": YES" << endl;
    }
    return 0;
}
