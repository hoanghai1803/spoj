#include <bits/stdc++.h>

using namespace std;

#define TASK "QBROBOT"
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

const int N = 5e2 + 2;
const ll oo = N * (1e4);

int n, m;
int Ener[N];
int F[N];
int e[N];
int w;

vector<iii> ad[N];

MIN_HEAP(ii) Heap;

void Init() {
	scanf("%d", &n);
	FORU(i, 1, n) scanf("%d", &Ener[i]);
	scanf("%d", &m);
	int u, v, t, c;
	FORU(i, 1, m) {
		scanf("%d%d%d%d", &u, &v, &t, &c);
		ad[u].push_back(iii(v, ii(t, c)));
		ad[v].push_back(iii(u, ii(t, c)));
	}
}

inline void Reset() {
	while(Heap.size()) Heap.pop();
	F[1] = 0;
	FORU(u, 2, n) F[u] = +oo;
	e[1] = w;
	FORU(u, 2, n) e[u] = 0; 
}

int Dijkstra(int M) {
	w = M;
	Reset();
	int Fu;
	int u, v;
	Heap.push(ii(F[1], 1));
	while(Heap.size()) {
		Fu = Heap.top().X;
		u = Heap.top().Y;
		Heap.pop();
		if(Fu != F[u]) continue;
		if(u == n) return F[u];
		itr(iii) it;
		IT(it, ad[u]) {
			if(e[u] - it->Y.Y < 0) continue;
			if(F[v = it->X] == F[u] + it->Y.X) 
				if(Ener[v]) e[v] = w; 
				else e[v] = max(e[v], e[u] - it->Y.Y);
			if(F[v = it->X] > F[u] + it->Y.X) {
				F[v] = F[u] + it->Y.X;
				if(Ener[v]) e[v] = w; else e[v] = e[u] - it->Y.Y;
				Heap.push(ii(F[v], v));
			}
		}
	}
	return F[n];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    int Min = Dijkstra(+oo);
    int L = 1, R = +oo, M;
    while(1) {
    	if(L + 1 == R) {
    		if(Dijkstra(L) == Min) printf("%d", L);
    		else printf("%d", R);
    		return 0;
    	}
    	M = (L + R) >> 1;
    	if(Dijkstra(M) == Min) R = M; else L = M;
    }
}