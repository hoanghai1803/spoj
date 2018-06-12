#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "VDANGER"
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
 
const int MAX_N = 1e2 + 2;
const int MAX_M = 1e4 + 4;

int n, m;
int a[MAX_M];
int c[MAX_N][MAX_N];

void Init() {
	scanf("%d%d", &n, &m);
	FORU(i, 1, m) scanf("%d", &a[i]);
	FORU(u, 1, n)
		FORU(v, 1, n) scanf("%d", &c[u][v]);
}

void Floyd() {
	FORU(k, 1, n)
		FORU(u, 1, n)
			FORU(v, 1, n) c[u][v] = min(c[u][v], c[u][k] + c[k][v]);
}

void Solve() {
	ll res = 0;
	FORU(i, 1, m - 1) res += c[a[i]][a[i + 1]];
	printf("%lld", res);
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