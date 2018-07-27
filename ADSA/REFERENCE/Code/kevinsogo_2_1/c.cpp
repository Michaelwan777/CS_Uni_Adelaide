#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")

#define I 10
#define J 20
#define K 30
int mul[111][111];
bool good[111];
bool chk = false;
struct Q {
    int v;
    Q(int v = 1) : v(v) {
        if (chk && (v < 0 ? !good[-v] : !good[v])) pf("BAD!!!\n"), exit(0);
    }
    Q operator*(Q& other) {
        int v1 = v;
        int v2 = other.v;
        int sgn = 1;
        if (v1 < 0) v1 = -v1, sgn *= -1;
        if (v2 < 0) v2 = -v2, sgn *= -1;
        return Q(sgn * mul[v1][v2]);
    }
};

Q seq[1111111];
char s[111111];

char toval[256];
bool pcan[4][8];
bool ccan[4][8];
int _sqs[8] = {1, I, J, K, -1, -I, -J, -K};
Q sqs[8];

int main() {
    chk = true;
    good[1] = good[I] = good[J] = good[K] = true;
    fr(i,8) sqs[i] = Q(_sqs[i]);

    toval['1'] = 1;
    toval['i'] = I;
    toval['j'] = J;
    toval['k'] = K;
    mul[1][1] = 1, mul[1][I] = I, mul[1][J] = J, mul[1][K] = K;
    mul[I][1] = I, mul[I][I] =-1, mul[I][J] = K, mul[I][K] =-J;
    mul[J][1] = J, mul[J][I] =-K, mul[J][J] =-1, mul[J][K] = I;
    mul[K][1] = K, mul[K][I] = J, mul[K][J] =-I, mul[K][K] =-1;
    int z;
    sf("%d", &z);
    fq(cas,z) {
        int n;
        ll x;
        sf("%d%lld%s", &n, &x, s);
        if (x > 32) x -= x - 32 >> 2 << 2;
        fr(i,n) seq[i] = Q(toval[s[i]]);
        int on = n;
        while (--x) {
            fr(i,on) {
                seq[n] = seq[n-on];
                n++;
            }
        }
        // pf("n = %d\n", n);
        // fr(i,n) {
        //     #define flu(i) (seq[i].v == 1 ? '1' : seq[i].v == I ? 'i' : seq[i].v == J ? 'j' : seq[i].v == K ? 'k' : '!')
        //     pf("%c", flu(i));
        // }
        // pln;
        fr(t,4) fr(v,8) ccan[t][v] = false;
        ccan[0][0] = true;
        fr(i,n) {
            // pf("now at %d: %c\n", i, flu(i));
            fr(t,4) fr(v,8) pcan[t][v] = ccan[t][v];
            fr(t,4) fr(v,8) {
                // pf("state %d %d\n", t, v);
                ccan[t][v] = false;
                if (t && !v && ccan[t-1][t]) {
                    ccan[t][v] = true;
                } else {
                    Q trg = sqs[v];
                    fr(ov,8) if (pcan[t][ov]) {
                        // pf("trying ov=%d: %d %d\n", ov, (sqs[ov] * seq[i]).v, sqs[v].v);
                        if ((sqs[ov] * seq[i]).v == sqs[v].v) {
                            ccan[t][v] = true;
                            break;
                        }
                    }
                }
                // if (ccan[t][v]) pf("can %d %d\n", t, v);
            }

        }
        pf("Case #%d: %s\n", cas, ccan[3][0] ? "YES" : "NO");
    }
}
