#include <bits/stdc++.h> 

using namespace std;

#define TASK "NKONEARC"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define FORU(i,a,b) for (int i=(a); i<=(b); i++)

const int N = 2e3 + 3;

/* Pre_Graph */
int n, m;
int cnt;
int dfn[N], Low[N];
bool Remove[N];
int Top = 0;
int Stack[10 * N];
vector<int> adj[N];

/* DAG */
int nscc;
int scc[N];
int deg_in[N], deg_out[N];
int F[N];

/* Create DAG */
inline void Dfs(int u) {
	Stack[++Top] = u;
	dfn[u] = Low[u] = ++cnt;
	int v;
	for(auto &v: adj[u]) {
		if(Remove[v]) continue;
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

void Init() {
	scanf("%d%d", &n, &m);
	int u, v;
	while(m--) {
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	FORU(u, 1, n) 
		if(adj[u].size() && !Remove[u]) Dfs(u);
	FORU(u, 1, n) 
		for(auto &v: adj[u]) {
			if(scc[v] == scc[u]) continue;
			deg_in[scc[v]]++;
			deg_out[scc[u]]++;
		}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen(input_file, "r", stdin);
		freopen(output_file, "w", stdout);
	#endif
	Init();
	int Begin, End;
	int cnt = 0;
	FORU(u, 1, nscc) if(!deg_in[u]) Begin = u, cnt++;
	if(cnt > 1) {
		printf("NO");
		return 0;
	}
	cnt = 0;
	FORU(u, 1, nscc) if(!deg_out[u]) End = u, cnt++;
	if(cnt > 1) {
		printf("NO");
		return 0;
	}
	printf("YES\n");
	FORU(u, 1, n) if(scc[u] == End) {
		printf("%d ", u);
		break;
	}
	FORU(u, 1, n) if(scc[u] == Begin) {
		printf("%d", u);
		break;
	}
	
}		