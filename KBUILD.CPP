#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "KBUILD"
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
 
const int MAX_N = 2e5 + 5;

int n, m;
int dfn[MAX_N], Low[MAX_N];
int Count[MAX_N];
int cnt = 0;
int Bridge = 0;

set<int> ad[MAX_N];

void Init() {
	scanf("%d", &n);
	int u, v;
	FORU(i, 1, n - 1) {
		scanf("%d%d", &u, &v);
		ad[u].insert(v);
		ad[v].insert(u);
	}
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &u, &v);
		if(ad[u].find(v) != ad[u].end()) continue;
		ad[u].insert(v);
		ad[v].insert(u);
	}
}	

inline void Dfs(int u, int Par) {
	dfn[u] = Low[u] = ++cnt;
	int v;
	set<int>::iterator it;
	IT(it, ad[u]) {
		if((v = *it) == Par) continue;
		if(dfn[v]) {
			Low[u] = min(Low[u], dfn[v]);
			continue;
		}
		Dfs(v, u);
		Low[u] = min(Low[u], Low[v]);
		Count[u] += (Low[v] >= dfn[v]);
	}
	Bridge += (Par && Low[u] == dfn[u]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Dfs(1, 0);
    printf("%d", Bridge);
}