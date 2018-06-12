#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKCITY"
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
const int M = 1e4 + 4;

int n, m;
iii E[M];
int Par[N];
int cnt = 0;

void Init() {
	scanf("%d%d", &n, &m);
	int u, v, t;
	FORU(i, 1, m) {
		scanf("%d%d%d", &u, &v, &t);
		E[i] = iii(t, ii(u, v));
	}
	sort(E + 1, E + m + 1);
	FORU(u, 1, n) Par[u] = u;
}

inline int Find_Root(int u) {
	return (Par[u] == u) ? u : (Par[u] = Find_Root(Par[u]));
}

inline void Union(int u, int v) {
	if((u = Find_Root(u)) == (v = Find_Root(v))) return;
	Par[u] = v, cnt++;
}

void Kruskal() {
	FORU(i, 1, m) {
		Union(E[i].Y.X, E[i].Y.Y);
		if(cnt == n - 1) {
			printf("%d", E[i].X);
			exit(0);
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Kruskal();
}