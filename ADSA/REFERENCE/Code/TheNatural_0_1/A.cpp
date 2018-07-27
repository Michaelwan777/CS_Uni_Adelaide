// A - Standing Ovation

#include <iostream>
#include <fstream>
using namespace std;

int n;
int aud[1005];

int main()
{
    ifstream fin ( "A-large.in" );
    ofstream fout ( "A-large.txt" );
    int t;
    fin >> t;
    for ( int h = 1; h <= t; h++ )
    {
        fin >> n;
        char c;
        for ( int i = 0; i <= n; i++ )
        {
            fin >> c;
            aud[i] = (int) ( c - '0' );
        }
        int running = 0;
        int cnt = 0;
        for ( int i = 0; i <= n; i++ )
        {
            if ( running < i )
            {
                cnt += i - running;
                running = i;
            }
            running += aud[i];
        }
        fout << "Case #" << h << ": " << cnt << endl;
    }
    return 0;
}
