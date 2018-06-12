#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "QBBUILD"
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
 
const int oo = 1e8;
const int MAX_N = 1e2 + 2;

int n;
int s[5];
int c[MAX_N][MAX_N];

inline void Minimize(int &a, int b) {
	if(a > b) a = b;
}

void Init() {
	scanf("%d", &n);
	FORU(i, 1, 4) scanf("%d", &s[i]);
	FORU(u, 1, n)
		FORU(v, 1, n) c[u][v] = (u == v) ? 0 : +oo;
	int u, v, w;
	while(scanf("%d%d%d", &u, &v, &w) != EOF) {
		Minimize(c[u][v], w);
		Minimize(c[v][u], w);
	}
}

void Floyd() {
	FORU(k, 1, n)
		FORU(u, 1, n)
			FORU(v, 1, n) Minimize(c[u][v], c[u][k] + c[k][v]);
}

void Solve() {
	int res = +oo;
	FORU(u, 1, n)
		FORU(v, 1, n) {
			int tmp = c[u][s[1]] + c[u][s[2]] + c[v][s[3]] + c[v][s[4]];
			Minimize(tmp, c[u][s[1]] + c[u][s[3]] + c[v][s[2]] + c[v][s[4]]);
			Minimize(tmp, c[u][s[1]] + c[u][s[4]] + c[v][s[2]] + c[v][s[3]]);
			Minimize(res, tmp + c[u][v]);
		}
	printf("%d", res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Floyd();
    Solve();
}