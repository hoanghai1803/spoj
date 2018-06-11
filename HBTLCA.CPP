#include <bits/stdc++.h>

using namespace std;

#define TASK "HBTLCA"
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

const int N = 1e5 + 5;
const int LOG_N = 20;

int n, m;
int D[N];
int P[N][LOG_N + 1];

vector<int> ad[N];

void DFS(int u) {
	int v;
	itr(int) it;
	IT(it, ad[u]) {
		D[v = *it] = D[u] + 1;
		P[v][0] = u;
		DFS(v);
	}
}

void Init() {
    FORU(u, 1, n) ad[u].clear();
	int u, v;
	FORU(i, 1, n - 1) {
		scanf("%d%d", &u, &v);
		ad[u].push_back(v);
	}
    D[1] = 1;
    DFS(1);
    FORU(i, 1, LOG_N)
        FORU(u, 1, n) P[u][i] = P[P[u][i-1]][i-1];
}

int LCA(int u, int v) {
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
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    while(1) {
    	scanf("%d", &n);
    	if(!n) return 0;	    	
    	Init();
    	scanf("%d", &m);
    	string t;
    	int root = 1;
    	int u, v;
    	while(m--) {
	    	cin >> t;
	    	if(t == "!") {
	    		scanf("%d", &root);
	    		continue;
	    	}
	    	scanf("%d%d", &u, &v);
	    	if(D[LCA(u, root)] < D[LCA(v, root)]) swap(u, v);
	    	if(D[LCA(u, root)] > D[LCA(u, v)]) printf("%d\n", LCA(u, root));
	    	else printf("%d\n", LCA(u, v));
	    }
    }
}