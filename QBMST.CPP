#include <bits/stdc++.h>

using namespace std;

#define TASK "QBMST"
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
#define FOR(i,a,b) for (int i=(a); i<=(b); i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define FORS(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
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

const int N = 1e4 + 4;
const int M = 15e3 + 3;

int n, m;
iii Edge[M];
int Par[N];
int res = 0;

void Init() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, m) scanf("%d%d%d", &Edge[i].Y.X, &Edge[i].Y.Y, &Edge[i].X);
	FOR(u, 1, n) Par[u] = -1;
	sort(Edge + 1, Edge + m + 1);
}

inline int Get_root(int u) {
	return (Par[u] < 0) ? u:(Par[u] = Get_root(Par[u]));
}

inline void Merge(int u, int v, int c) {
    if(Par[v] < Par[u]) swap(u, v);
    Par[u] += Par[v];
    Par[v] = u;
    res += c;
}

void Kruskal() {
	int u, v, c;
	FOR(i, 1, m) {
		u = Edge[i].Y.X;
		v = Edge[i].Y.Y;
		c = Edge[i].X;
		if((u = Get_root(u)) == (v = Get_root(v))) continue;
		Merge(u, v, c);
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Kruskal();
    printf("%d", res);
}