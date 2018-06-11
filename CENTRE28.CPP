#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "CENTRE28"
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

const int oo = INT_MAX; 
const int MAX_N = 3e4 + 4;

int n, m;
int d[3][MAX_N];
ll F[3][MAX_N];

vector<ii> ad[MAX_N];

MIN_HEAP(ii) Heap;

void Init() {
	scanf("%d%d", &n, &m);
	int u, v, c;
	while(m--) {
		scanf("%d%d%d", &u, &v, &c);
		ad[u].push_back(ii(v, c));
		ad[v].push_back(ii(u, c));
	}
	FORU(u, 1, n) d[1][u] = +oo, d[2][u] = +oo;
	d[1][1] = 0, d[2][n] = 0;
	F[1][1] = 1, F[2][n] = 1;
}

void Dijkstra(int id, int s) {
	int u, v;
	int du;
	Heap.push(ii(d[id][s], s));
	while(Heap.size()) {
		du = Heap.top().X, u = Heap.top().Y;
		Heap.pop();
		if(du != d[id][u]) continue;
		itr(ii) it;
		IT(it, ad[u]) {
			if(d[id][v = it->X] == du + it->Y) {
				F[id][v] += F[id][u];
				continue;
			}
			if(d[id][v] > du + it->Y) {
				d[id][v] = du + it->Y;
				F[id][v] = F[id][u];
				Heap.push(ii(d[id][v], v));
			}
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Dijkstra(1, 1);
    Dijkstra(2, n);
    int res = 0;
    FORU(u, 2, n - 1) 
    	res += (d[1][u] + d[2][u] != d[1][n]) || (F[1][u] * F[2][u] != F[1][n]);
    printf("%d\n", res);
    FORU(u, 2, n - 1) 
    	if(d[1][u] + d[2][u] != d[1][n] || F[1][u] * F[2][u] != F[1][n]) printf("%d\n", u);
}	