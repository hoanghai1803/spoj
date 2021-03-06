#include<bits/stdc++.h>

using namespace std;

#define TASK "QTREE3"
#define input_file TASK".INP"
#define output_file TASK".OUT"

const int oo = 1e9;
const int N = 1e5 + 5;

int n, q;
int Par[N], Children[N];
int Node[4 * N];

vector<int> adj[N];

/* HLD */
int nChain = 1, nArr;
int HeadChain[N], InChain[N], PosInArr[N];
int IsVtx[N];
bool Arr[N];

void Input() {
    scanf("%d%d", &n, &q);
    int u, v;
    for(int i = 1; i <= n - 1; i++) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Par[1] = 0;
    for(int i = 1; i <= 4 * N - 1; i++) Node[i] = +oo;
}

inline void Dfs(int u) {
    for(auto &v: adj[u]) {
        if(v == Par[u]) continue;
        Par[v] = u;
        Dfs(v);
        Children[u] += Children[v] + 1;
    }
}

/* Init HLD */
inline void Hld(int u) {
	if (HeadChain[nChain] == 0) HeadChain[nChain] = u;

 	InChain[u] = nChain;

	PosInArr[u] = ++nArr;
    IsVtx[nArr] = u;

	int spVtx = 0;
    for(auto &v: adj[u]) {
        if(v == Par[u]) continue;
        if(!spVtx || Children[v] > Children[spVtx]) spVtx = v;
	}

	if(spVtx) Hld(spVtx);

    for(auto &v: adj[u]) {
		if(v == Par[u] || v == spVtx) continue;
		nChain++;
		Hld(v);
	}
}

/* Update & Query IT */
inline void Update_IT(int id, int L, int R, int i) {
    if(R < i || L > i) return;
    if(L == R) {
        if(!Arr[i]) Arr[i] = 1, Node[id] = i;
        else Arr[i] = 0, Node[id] = +oo;
        return;
    }
    int M = (L + R) >> 1;
    Update_IT(id * 2, L, M, i);
    Update_IT(id * 2 + 1, M + 1, R, i);
    Node[id] = min(Node[id * 2], Node[id * 2 + 1]);
}

inline int Get_IT(int id, int L, int R, int u, int v) {
    if(R < u || L > v) return +oo;
    if(L >= u && R <= v) return Node[id];
    int M = (L + R) >> 1;
    return min(Get_IT(id * 2, L, M, u, v), Get_IT(id * 2 + 1, M + 1, R, u, v));
}

/*Query HLD */
inline void Query(int u) {
    int res = +oo;

    while(1) {
        int uChain = InChain[u];
        if(uChain == 1) {
            res = min(res, Get_IT(1, 1, n, 1, PosInArr[u]));
            break;
        }
        res = min(res, Get_IT(1, 1, n, PosInArr[HeadChain[uChain]], PosInArr[u]));
        u = Par[HeadChain[uChain]];
    }
    if(res == +oo) printf("-1\n");
    else printf("%d\n", IsVtx[res]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif

    /* Initialization */
    Input();
    Dfs(1);
    Hld(1);

    /* Query */
    int type, u;
    while(q--) {
        scanf("%d%d", &type, &u);
        if(!type) Update_IT(1, 1, n, PosInArr[u]);
        else Query(u);
    }
}               