#include <bits/stdc++.h>

using namespace std;

#define TASK "PWRFAIL"
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
typedef pair<ll, ll> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

const float oo = FLT_MAX;
const int N = 1e3 + 3;

int n, w;
double m;
ll x[N], y[N];
double F[N];
bool OK[N][N];

vector<dd> ad[N];

MIN_HEAP(dd) Heap;

inline double Distance(int u, int v) {
    return(sqr(x[u] - x[v]) + sqr(y[u] - y[v]));
}

void Init() {
    scanf("%d%d", &n, &w);
    scanf("%lf", &m);
    FOR(u, 1, n) scanf("%lld%lld", &x[u], &y[u]);
    SET_ARR(OK, true);
    int u, v;
    while(w--) {
        scanf("%d%d", &u, &v);
        ad[u].push_back(ii(v, 0));
        ad[v].push_back(ii(u, 0));
        OK[u][v] = false;
    }
    double d;
    FOR(u, 1, n) 
        FOR(v, 1, n) 
            if(u != v && ((d = Distance(u,v)) <= m * m) && OK[u][v])
                ad[u].push_back(dd(v, d)), ad[v].push_back(dd(u, sqrt(d)));
    F[1] = 0;
    FOR(u, 2, n) F[u] = +oo;
}

void Dijkstra() {
    int u, v;
    double Fu;
    Heap.push(dd(F[1], 1));
    while(Heap.size()) {
        Fu = Heap.top().ST, u = Heap.top().ND;
        Heap.pop();
        if(Fu != F[u]) continue;
        if(u == n) break;
        itr(dd) it;
        IT(it, ad[u])
            if(F[v = it->ST] > F[u] + it->ND) {
                F[v] = F[u] + it->ND;
                Heap.push(dd(F[v], v));
            }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Dijkstra();
    if(F[n] == +oo) printf("-1");
    else printf("%lld", (ll)(F[n]*1000));
}