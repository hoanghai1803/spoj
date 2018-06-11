#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "FWATER"
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
 
const int MAX_N = 1e3 + 3;
const int MAX_M = 2 * MAX_N * MAX_N;

int n, m = 0;
int Par[MAX_N];
int res = 0;

struct Edge {
	int u, v;
	int w;
	Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {};
    Edge() {};
} E[MAX_M];
    
inline bool operator < (const Edge &x, const Edge &y) {
    return(x.w < y.w);
}

void Init() {
	scanf("%d", &n);
    int w;
    FORU(u, 1, n) {
        scanf("%d", &w);
        E[++m] = Edge(0, u, w);
    }
    FORU(u, 1, n)
        FORU(v, 1, n) {
            scanf("%d", &w);
            if(u < v) E[++m] = Edge(u, v, w);
        }
    sort(E + 1, E + m + 1);
    FORU(u, 0, n) Par[u] = u;
}

inline int Find_Root(int u) {
    return(Par[u] == u) ? u : (Par[u] = Find_Root(Par[u]));
}

inline void Union(int u, int v, int w) {
    if((u = Find_Root(u)) == (v = Find_Root(v))) return;
    res += w, Par[u] = v;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    FORU(i, 1, m) Union(E[i].u, E[i].v, E[i].w);
    printf("%d", res);
}