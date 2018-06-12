#include <bits/stdc++.h>

using namespace std;

#define TASK "SEQ198"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();i++)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define FOR(i,a,b) for (long long i=(a); i<=(b); i++)
#define FORD(i,a,b) for (long long i=(a); i>=(b); i--)
#define abs(x) ((x)>0?(x):-(x))
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 2017;
const int M = 1 << 9;
const int oo = 2 * N * N;

int m, n = 1;
int b[N];
int res = N;
ii a[N];
int F[N][M];

void Init() {
    scanf("%d", &m);
    FOR(i, 1, m) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + m);
    a[1].X = b[1], a[1].Y = 1;
    FOR(i, 2, m) {
        if(b[i] != b[i-1]) a[++n].Y = 0;
        a[n].X = b[i];
        a[n].Y++;
    }
}

inline bool Get_bit(int n, int i) {
    return (n >> (i - 1)) & 1;
}

inline bool Check(int i, int j) {
    if(j <= 0) return true;
    return(a[i].X - a[j].X == 1 || a[i].X - a[j].X == 8 || a[i].X - a[j].X == 9);
}

void DP() {
    FOR(i, 0, n)
        FOR(j, 0, M - 1) F[i][j] = -oo;
    F[0][0] = 0;
    FOR(i, 0, n - 1)
        FOR(j, 0, M - 1) {
            int jj = (j * 2) % M;
            F[i + 1][jj] = max(F[i + 1][jj], F[i][j]);
            jj++;
            bool ok = true;
            FORD(k, 9, 1)
                if (Get_bit(j, k)) {
                    if (Check(i + 1,i - k + 1)) {
                        ok = false;
                        break;
                    }
                }
            if(ok) F[i + 1][jj] = max(F[i + 1][jj], F[i][j] + a[i + 1].Y);
        }
    FOR(j, 0, M - 1) res = min(res, m - F[n][j]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    DP();
    printf("%d", res);
}
