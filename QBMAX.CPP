#include <bits/stdc++.h>

using namespace std;

#define TASK "QBMAX"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define ST first
#define ND second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();i++)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();i++)
#define MAX_HEAP(t) priority_queue<t>
#define MIN_HEAP(t) priority_queue<t,vector<t>,greater<t> >
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FORS(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
#define abs(x) ((x)>=0?(x):-(x))
#define sqr(x) (x)*(x)
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

const int oo = INT_MAX;
const int N = 1e2 + 2;

int dx[3] = {0, -1, 1};
int dy[3] = {1, 1, 1}; 

int m, n;
int a[N][N];
int F[N][N];

void Init() {
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
        FOR(j, 1, n) {
            scanf("%d", &a[i][j]); 
            F[i][j] = -oo;
        }
}

inline bool Valid(int i, int j) {
    return(i && i <= m && j <= n);
}

void DP() {
    FOR(i, 1, m) F[i][1] = a[i][1];
    int u, v;
    FOR(j, 1, n - 1)
        FOR(i, 1, m) 
            FOR(d, 0, 2) {
                u = i + dx[d];
                v = j + dy[d];
                if(Valid(u, v)) F[u][v] = max(F[u][v], F[i][j] + a[u][v]); 
            }
}

void Output() {
    int res = -oo;
    FOR(i, 1, m) res = max(res, F[i][n]);
    printf("%d", res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    DP();
    Output();
}