#include <bits/stdc++.h>

using namespace std;

#define TASK "TJALG"
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

const int N = 1e4 + 4;

int n, m;
int Low[N], dfn[N];
bool Remove[N];
int Stack[10 * N];
int Top = 0;
int cnt = 0;
int res = 0;

vector<int> ad[N];

void Init() {
    scanf("%d%d", &n, &m);
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        ad[u].push_back(v);
    }
}
    
inline void Dfs(int u) {
    Stack[++Top] = u;
    dfn[u] = Low[u] = ++cnt;
    int v;
    itr(int) it;
    IT(it, ad[u]) {
        if(Remove[v = *it]) continue;
        if(dfn[v]) {
            Low[u] = min(Low[u], dfn[v]);
            continue;
        }
        Dfs(v);
        Low[u] = min(Low[u], Low[v]);
    }
    if(Low[u] == dfn[u]) {
        res++;
        for(; ; Top--) {
            Remove[v = Stack[Top]] = true;
            if(u == v) {
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
    FOR(u, 1, n)
        if(!dfn[u]) Dfs(u);
    printf("%d", res);
}