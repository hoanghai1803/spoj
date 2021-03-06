#include <bits/stdc++.h>

using namespace std;

#define TASK "LCA"
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
#define FORU(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FOR(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
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

const int N = 1e3 + 3;
const int LOG_N = 20;

int T, Q;
int n;
int D[N];
int P[N][LOG_N + 1];
int L[N];

vector<int> ad[N];

inline void DFS(int u) {
    itr(int) it;
    int v;
    IT(it, ad[u]) {
        D[v = *it] = D[u] + 1;
        P[v][0] = u;
        DFS(v);
    }
}

inline void Init() {
    scanf("%d", &n);
    FORU(u, 1, n) ad[u].clear();
    int childs;
    int v;
    FORU(u, 1, n) {
        scanf("%d", &childs);
        while(childs--) {
            scanf("%d", &v);
            ad[u].push_back(v);
        }
    }
    D[1] = 1;
    DFS(1);
    FORU(i, 1, LOG_N)
        FORU(u, 1, n) P[u][i] = P[P[u][i - 1]][i - 1];
}

inline int LCA(int u, int v) {
    if(D[u] < D[v]) swap(u, v);
    FORD(i, LOG_N, 0)
        if(D[P[u][i]] >= D[v]) u = P[u][i];
    if(u == v) return u;
    FORD(i, LOG_N, 0)
        if(P[u][i] != P[v][i]) u = P[u][i], v = P[v][i];
    return P[u][0];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d", &T);
    FORU(id, 1, T) {
        Init();
        scanf("%d", &Q);
        printf("Case %d:\n", id);
        int u, v;
        while(Q--) {
            scanf("%d%d", &u, &v);
            printf("%d\n", LCA(u, v));
        }
    }
}
