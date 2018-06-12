#include <bits/stdc++.h>

using namespace std;

#define TASK "PWALK"
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
const int LOG_N = 15;

int n, q;
int D[N], L[N];
int P[N][LOG_N + 1];
bool Free[N];

vector<ii> ad[N];

inline void Dfs(int u) {
	Free[u] = false;
	int v;
	itr(ii) it;
	IT(it, ad[u]) {
		if(!Free[v = it->X]) continue;
		D[v] = D[u] + 1, L[v] = L[u] + it->Y;
		P[v][0] = u;
		Dfs(v);
	}
}

void Init() {
	scanf("%d%d", &n, &q);
	int u, v, l;
	FORU(i, 1, n-1) {
		scanf("%d%d%d", &u, &v, &l);
		ad[u].push_back(ii(v, l));
		ad[v].push_back(ii(u, l));
	}
	D[1] = 1, L[1] = 0;
	FORU(u, 1, n) Free[u] = true;
	Dfs(1);
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
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    int u, v;
    while(q--) {
    	scanf("%d%d", &u, &v);
    	printf("%d\n", L[u] + L[v] - 2 * L[LCA(u, v)]);
    }
}