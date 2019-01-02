#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "QTREEX"
#define input_file TASK".INP"
#define output_file TASK".OUT"
 
#define X first
#define Y second
#define FORU(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define SET_ARR(F, v) memset(F, v, sizeof(F))
 
typedef pair<int,int> ii;
 
const int oo = 1e9;
const int N = 1e4 + 4;
const int LOG_N = 15;
 
int T, n;
int Par[N][LOG_N + 1], Children[N];
int c[N], D[N];
ii Edge[N];
 
vector<ii> adj[N];
 
/* HLD */
int nChain, nArr;
int HeadChain[N], InChain[N], PosInArr[N];
int IsVtx[N];
 
struct __Node {
	int Max, Min;
	bool lazy;
} Node[4 * N];
 
/* Initialization */
inline void Dfs(int u) {
    for(auto &Vtx: adj[u]) {
        int v = Vtx.X;
        if(v == Par[u][0]) continue;
        Par[v][0] = u;
        D[v] = D[u] + 1;
        c[v] = Vtx.Y;
        Dfs(v);
        Children[u] += Children[v] + 1;
    }
}
 
inline void Init() {
	scanf("%d", &n);
	int u, v, c, e = 0;
	FORU(u, 1, n) adj[u].clear();
	FORU(i, 1, n - 1) {
		scanf("%d%d%d", &u, &v, &c);
		adj[u].push_back(ii(v, c));
		adj[v].push_back(ii(u, c));
		Edge[++e] = ii(u, v);
	}
	SET_ARR(Par, 0);
	SET_ARR(Children, 0);
	FORU(id, 1, 4 * N - 1) Node[id].Min = +oo, Node[id].Max = -oo, Node[id].lazy = 0;
 
	nChain = 1, nArr = 0;
	SET_ARR(HeadChain, 0);
 
	D[1] = 1;
    Dfs(1);
    FORU(i, 1, LOG_N)
        FORU(u, 1, n) Par[u][i] = Par[Par[u][i - 1]][i - 1];
}
 
/* LCA */
inline int LCA(int u, int v) {
    if(D[u] < D[v]) swap(u, v);
    FORD(i, LOG_N, 0)
        if(D[Par[u][i]] >= D[v]) u = Par[u][i];
    if(u == v) return u;
    FORD(i, LOG_N, 0)
        if(Par[u][i] != Par[v][i]) u = Par[u][i], v = Par[v][i];
    return Par[u][0];
}
 
/* Init HLD */
inline void Hld(int u) {
	if(HeadChain[nChain] == 0) HeadChain[nChain] = u;
	InChain[u] = nChain;
 
	PosInArr[u] = ++nArr;
	IsVtx[nArr] = u; 
 
	int spVtx = 0;
	for(auto &Vtx: adj[u]) {
		int v = Vtx.X;
		if(v == Par[u][0]) continue;
		if(!spVtx || Children[v] > Children[spVtx]) spVtx = v;
	}
 
	if(spVtx) Hld(spVtx);
 
	for(auto &Vtx: adj[u]) {
		int v = Vtx.X;
		if(v == Par[u][0] || v == spVtx) continue;
		nChain++;
		Hld(v);
	}
}
 
/* Init IT */
inline void Init_IT(int id, int L, int R) {
	if(L == R) {
		Node[id].Max = Node[id].Min = c[IsVtx[L]];
		return;
	}
    int M = (L + R) >> 1;
    Init_IT(id * 2, L, M);
    Init_IT(id * 2 + 1, M + 1, R);
    Node[id].Max = max(Node[id * 2].Max, Node[id * 2 + 1].Max);
    Node[id].Min = min(Node[id * 2].Min, Node[id * 2 + 1].Min);
}
 
/* Update & Get IT */
inline void Propagation(int id) {
	int tmp = Node[id * 2].Max;
	Node[id * 2].Max = -Node[id * 2].Min, Node[id * 2].Min = -tmp;
	Node[id * 2].lazy = !Node[id * 2].lazy;
	tmp = Node[id * 2 + 1].Max;
	Node[id * 2 + 1].Max = -Node[id * 2 + 1].Min, Node[id * 2 + 1].Min = -tmp;
	Node[id * 2 + 1].lazy = !Node[id * 2 + 1].lazy;
}
 
inline void Change_IT(int id, int L, int R, int i, int val) {
	if(R < i || L > i) return;
	if(L == R) {
		if(L == i) Node[id].Max = Node[id].Min = val;
	    return;
    }
    if(Node[id].lazy) {
    	Node[id].lazy = 0;
    	Propagation(id);
    }
    int M = (L + R) >> 1;
    Change_IT(id * 2, L, M, i, val);
    Change_IT(id * 2 + 1, M + 1, R, i, val);
    Node[id].Max = max(Node[id * 2].Max, Node[id * 2 + 1].Max);
    Node[id].Min = min(Node[id * 2].Min, Node[id * 2 + 1].Min);
}
 
inline void Negative_IT(int id, int L, int R, int u, int v) {
	if(u > v || R < u || L > v) return;
    if(L >= u && R <= v) {
    	int tmp = Node[id].Max;
    	Node[id].Max = -Node[id].Min, Node[id].Min = -tmp;
    	Node[id].lazy = !Node[id].lazy;
    	return;
    }
    if(Node[id].lazy) {
    	Node[id].lazy = 0;
    	Propagation(id);
    }
    int M = (L + R) >> 1;
    Negative_IT(id * 2, L, M, u, v);
    Negative_IT(id * 2 + 1, M + 1, R, u, v);
    Node[id].Max = max(Node[id * 2].Max, Node[id * 2 + 1].Max);
    Node[id].Min = min(Node[id * 2].Min, Node[id * 2 + 1].Min);
}
 
inline int Get_IT(int id, int L, int R, int u, int v) {
	if(u > v || R < u || L > v) return -oo; 
    if(L >= u && R <= v) return Node[id].Max;
    if(Node[id].lazy) {
    	Node[id].lazy = 0;
    	Propagation(id);
    }
    int M = (L + R) >> 1;
    return max(Get_IT(id * 2, L, M, u, v), Get_IT(id * 2 + 1, M + 1, R, u, v));
}
 
/* Update & Query HLD */
inline void Negative(int u, int a) {
	while(1) {
		int uChain = InChain[u], aChain = InChain[a];
		if(uChain == aChain) {
			Negative_IT(1, 1, n, PosInArr[a] + 1, PosInArr[u]);
			break;
		}
		Negative_IT(1, 1, n, PosInArr[HeadChain[uChain]], PosInArr[u]);
		u = Par[HeadChain[uChain]][0];
	}
}

inline int Query(int u, int a) {
	int ret = -oo;
 
    while(1) {
    	int uChain = InChain[u], aChain = InChain[a];
        if(uChain == aChain) {
            ret = max(ret, Get_IT(1, 1, n, PosInArr[a] + 1, PosInArr[u]));
            break;
        }
        ret = max(ret, Get_IT(1, 1, n, PosInArr[HeadChain[uChain]], PosInArr[u]));
        u = Par[HeadChain[uChain]][0];
    }
 
    return ret;
}
 
int main() {
	#ifndef ONLINE_JUDGE
		freopen(input_file, "r", stdin);
		freopen(output_file, "w", stdout);
	#endif 
	scanf("%d", &T);
	while(T--) {
		/* Initialization */ 
		Init();
		Hld(1);
		Init_IT(1, 1, n);
 
		/* Query */
		char type[10];
		int a, b;
		while(1) {
			scanf("%s", type);
			if(type[0] == 'D') break;
			scanf("%d%d", &a, &b);
			if(type[0] == 'C') {
				if(Edge[a].X == Par[Edge[a].Y][0]) Change_IT(1, 1, n, PosInArr[Edge[a].Y], b);
				else Change_IT(1, 1, n, PosInArr[Edge[a].X], b);
			}
			if(type[0] == 'N') {
				int _lca = LCA(a, b);
				Negative(a, _lca); 
				Negative(b, _lca);
			}
			if(type[0] == 'Q') {
				if(a == b) {
					printf("0\n");
					continue;
				}
				int _lca = LCA(a, b);
				int res = max(Query(a, _lca), Query(b, _lca));
				printf("%d\n", res);
			}
		}
	}
}