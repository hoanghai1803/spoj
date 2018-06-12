#include <bits/stdc++.h>

using namespace std;

#define TASK "PBCGANGS"
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

int n, m;
int Par[N];

vector<int> E[N], F[N];
itr(int) it;

void Init() {
    scanf("%d%d", &n, &m);
    char stt;
    int u, v;
    while(m--) {
        scanf("%s", &stt);
        scanf("%d%d", &u, &v);
        if(stt == 'F') F[u].push_back(v);
        else {
            E[u].push_back(v);
            E[v].push_back(u);
        }
    }
    FORU(u, 1, n) Par[u] = u;
}

int Find_set(int u) {
    return (Par[u] == u) ? u:(Par[u] = Find_set(Par[u]));
}

void Union(int u, int v) {
    if(!u || !v) return;
    if((u = Find_set(u)) == (v = Find_set(v))) return;
    Par[u] = v;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w", stdout);
    #endif
    Init();
    FORU(u, 1, n) {
        IT(it, F[u]) Union(u, *it);
        int pre = 0;
        IT(it, E[u]) {
            Union(pre, *it);
            pre = *it;
        }
    }
    int res = 0;
    FORU(u, 1, n) 
        if(Find_set(u) == u) res++;
    printf("%d", res);
}