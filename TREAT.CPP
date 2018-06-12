#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "TREAT"
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
 
const int MAX_N = 1e5 + 5;

int n;
int Next[MAX_N];
int cnt = 0;
int Low[MAX_N], dfn[MAX_N];
bool Remove[MAX_N];
int Top = 0;
int Stack[10 * MAX_N];
int id = 0;
int Scc[MAX_N];
bool Visited[MAX_N];
int res[MAX_N];

vector<int> ad[MAX_N]; 

/* CREATE DAG */

inline void Dfs(int u) {
	Stack[++Top] = u;
	dfn[u] = Low[u] = ++cnt;
	int v;
	if(!Remove[v = Next[u]]) {
		if(dfn[v]) Low[u] = min(Low[u], dfn[v]);
		else {
			Dfs(v);
			Low[u] = min(Low[u], Low[v]);
		}
	}
	if(Low[u] == dfn[u]) {
		id++;
		for(; ; --Top) {
			Remove[v = Stack[Top]] = true;
			Scc[v] = id, res[id]++;
			if(u == v) {
				--Top;
				break;
			}
		}
	}
}	

/* CALC */

inline void Visit(int u) {
	Visited[u] = true;
	int v;
	itr(int) it;
	IT(it, ad[u]) {
		if(!Visited[v = *it]) Visit(v);
		res[u] += res[v];
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif 
    scanf("%d", &n);
    int v;
    FORU(u, 1, n) {
    	scanf("%d", &v);
    	Next[u] = v;
    }
    FORU(u, 1, n)
    	if(!dfn[u]) Dfs(u);
    FORU(u, 1, n)
    	if(Scc[u] != Scc[v = Next[u]]) ad[Scc[u]].push_back(Scc[v]);
    FORU(u, 1, id)
    	if(!Visited[u]) Visit(u);
    FORU(u, 1, n) printf("%d\n", res[Scc[u]]);
}