#include <bits/stdc++.h>

using namespace std;

#define TASK "BINLADEN"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define SC scanf
#define PR printf
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
const int N = 3e4;

int m, n;
int F[N];
int room;

vector<ii> ad[N];

MIN_HEAP(ii) Heap;

void INIT() {
    SC("%d%d", &m, &n);
    int t;
    FOR(u, 1, n) {
        SC("%d", &t);
        ad[0].push_back(ii(u, t));
    }
    FOR(u, 1, 2*m-1) {
        if(u & 1)
            FOR(v, 1, n-1) {
                SC("%d", &t);
                int tmp = (u-1)/2*n + v;
                ad[tmp].push_back(ii(tmp+1, t));
                ad[tmp+1].push_back(ii(tmp, t));
            }
        else 
            FOR(v, 1, n) {
                SC("%d", &t);
                int tmp = (u-2)/2*n + v; 
                ad[tmp].push_back(ii(tmp+n, t));
                ad[tmp+n].push_back(ii(tmp, t));
            }
        }
    F[0] = 0;
    room = n*m;
    FOR(u, 1, room) F[u] = +oo;
}

void DIJKSTRA() {
    int u, v;
    int Fu;
    Heap.push(ii(F[0], 0));
    while(Heap.size()) {
        Fu = Heap.top().ST, u = Heap.top().ND;
        Heap.pop();
        if(Fu != F[u]) continue;
        if(u == room) break;
        itr(ii) it; 
        IT(it, ad[u]) 
            if(F[v = it->ST] > F[u] + it->ND) {
                F[v] = F[u] + it->ND;
                Heap.push(ii(F[v], v));
            }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    INIT();
    itr(ii) it;
    DIJKSTRA();
    PR("%d", F[room]);
}