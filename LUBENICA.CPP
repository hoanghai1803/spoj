#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "LUBENICA"
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
 
const int oo = 1e9 + 9; 
const int MAX_N = 1e5 + 5;
const int LOG_N = 20;

int n;
int D[MAX_N];
int P[MAX_N][LOG_N + 1];
int Min[MAX_N][LOG_N + 1], Max[MAX_N][LOG_N + 1];

vector<ii> ad[MAX_N];

inline void Dfs(int u, int Par) {
	int v;
	itr(ii) it;
	IT(it, ad[u]) {
		if((v = it->X) == Par) continue;
		D[v = it->X] = D[u] + 1;
		P[v][0] = u;
		Min[v][0] = Max[v][0] = it->Y;
		Dfs(v, u);
	}
}

void Init() {
	scanf("%d", &n);
	int u, v, d;
	FORU(i, 1, n - 1) {
		scanf("%d%d%d", &u, &v, &d);
		ad[u].push_back(ii(v, d));
		ad[v].push_back(ii(u, d));
	}
	D[1] = 1;
	Dfs(1, 0);
	FORU(i, 1, LOG_N) 
		FORU(u, 1, n) {
			Min[u][i] = min(Min[u][i - 1], Min[P[u][i - 1]][i - 1]);
			Max[u][i] = max(Max[u][i - 1], Max[P[u][i - 1]][i - 1]);
			P[u][i] = P[P[u][i - 1]][i - 1];
		}
}

inline void Query(int u, int v) {
	if(D[u] < D[v]) swap(u, v);
	int d_min = +oo, d_max = 0;
	FORD(i, LOG_N, 0)
		if(D[P[u][i]] >= D[v]) {
			d_min = min(d_min, Min[u][i]);
			d_max = max(d_max, Max[u][i]);
			u = P[u][i];
		}
	if(u == v) {
		printf("%d %d\n", d_min, d_max);
		return;
	}
	FORD(i, LOG_N, 0)
		if(P[u][i] != P[v][i]) {
			d_min = min3(d_min, Min[u][i], Min[v][i]);
			d_max = max3(d_max, Max[u][i], Max[v][i]);
			u = P[u][i], v = P[v][i];
		}
	d_min = min3(d_min, Min[u][0], Min[v][0]);
	d_max = max3(d_max, Max[u][0], Max[v][0]);
	printf("%d %d\n", d_min, d_max);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
   	int u, v, q;
   	scanf("%d", &q);  
   	while(q--) {
   		scanf("%d%d", &u, &v);
   		Query(u, v);
   	}
}