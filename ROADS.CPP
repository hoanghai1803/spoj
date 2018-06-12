#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "ROADS"
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
 
const int oo = INT_MAX;
const int MAX_N = 1e2 + 2;
const int MAX_K = 1e4 + 4;

int T;
int k, n, r;
int F[MAX_N][MAX_K];

vector<iii> ad[MAX_N];

MIN_HEAP(iii) Heap;

inline void Init() {
	scanf("%d%d", &k, &n);
	scanf("%d", &r);
	FORU(u, 1, n) ad[u].clear();
	int u, v, l, t;
	while(r--) {
		scanf("%d%d%d%d", &u, &v, &l, &t);
		ad[u].push_back(iii(v, ii(l, t)));
	}
	FORU(u, 1, n)
		FORU(t, 0, k) F[u][t] = +oo;
	F[1][k] = 0;
}

inline void Dijkstra() {
	int u, v, t;
	int Fu;
	while(Heap.size()) Heap.pop();
	Heap.push(iii(F[1][k], ii(1, k)));
	while(Heap.size()) {
		Fu = Heap.top().X, u = Heap.top().Y.X, t = Heap.top().Y.Y;
		Heap.pop();
		if(u == n) {
			printf("%d\n", F[u][t]);
			return;
		}
		if(Fu != F[u][t]) continue;
		itr(iii) it;
		IT(it, ad[u]) {
			if(t - it->Y.Y < 0) continue;
			if(F[v = it->X][t - it->Y.Y] > F[u][t] + it->Y.X) {
				F[v][t - it->Y.Y] = F[u][t] + it->Y.X;
				Heap.push(iii(F[v][t - it->Y.Y], ii(v, t - it->Y.Y)));
			}
		}
	}
	printf("-1\n");
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &T);
    while(T--) {
    	Init();
    	Dijkstra();
    }
}