#include <bits/stdc++.h>

using namespace std;

#define TASK "QBSCHOOL"
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
typedef pair<ll,ll> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

const ll oo = LLONG_MAX;
const int N = 5e3 + 3;

int n, m;
ll d[N];
ll F[N];

vector<ii> ad[N];

MIN_HEAP(ii) Heap;

void Init() {
    scanf("%d%d", &n, &m);
    int k, u, v, l;
    while(m--) {
        scanf("%d%d%d%d", &k, &u, &v, &l);
        ad[u].push_back(ii(v, l));
        if(k == 2) ad[v].push_back(ii(u, l));
    }
    d[1] = 0, F[1] = 1;
    FOR(u, 2, n) d[u] = +oo;
}

void Dijkstra() {
    int u, v;
    ll du;
    Heap.push(ii(d[1], 1));
    while(Heap.size()) {
        du = Heap.top().ST, u = Heap.top().ND;
        Heap.pop();
        if(du != d[u]) continue;
        if(u == n) break;
        itr(ii) it;
        IT(it, ad[u]) {
            if(d[v = it->ST] == d[u] + it->ND) F[v] += F[u]; 
            if(d[v] > d[u] + it->ND) {
                d[v] = d[u] + it->ND, F[v] = F[u];
                Heap.push(ii(d[v], v));
            }
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
    printf("%lld %lld", d[n], F[n]);
}