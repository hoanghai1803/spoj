#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "MESSAGE"
#define input_file TASK".INP"
#define output_file TASK".OUT"
 
#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();++i)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();++i)
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

const int N = 888;

/* Pre Graph */
int n, m;
int cnt = 0;
int dfn[N], Low[N];
int Remove[N];
int Top = 0;
int Stack[N * 10];
vector<int> adj[N];

/* DAG */
int nscc = 0;
int scc[N];
int deg_in[N];

void Init() {
    scanf("%d%d", &n, &m);
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }
}

/* Create DAG */
inline void Dfs(int u) {
    Stack[++Top] = u;
    dfn[u] = Low[u] = ++cnt;
    int v;
    itr(int) it;
    IT(it, adj[u]) {
        if(Remove[v = *it]) continue;
        if(dfn[v]) {
            Low[u] = min(Low[u], dfn[v]);
            continue;
        }
        Dfs(v);
        Low[u] = min(Low[u], Low[v]);
    } 
    if(Low[u] == dfn[u]) {
        ++nscc;
        for(; ; Top--) {
            scc[v = Stack[Top]] = nscc;
            Remove[v] = true;
            if(v == u) {
                Top--;
                break;
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
    for(int u = 1; u <= n; u++) if(!dfn[u]) Dfs(u);
    itr(int) it;
    for(int u = 1; u <= n; u++) 
        IT(it, adj[u]) {
            int v;
            if(scc[v = *it] == scc[u]) continue;
            deg_in[scc[v]]++;
        }
    int res = 0;
    for(int u = 1; u <= nscc; u++) res += (deg_in[u] == 0);
    printf("%d", res);
}