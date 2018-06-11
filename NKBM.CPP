#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKBM"
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
 
const int MAX_N = 1e3 + 3;

int m, n, e;
int Left[MAX_N], Right[MAX_N];
int Trace[MAX_N];
bool ok;

vector<int> ad[MAX_N];

void Init() {
	scanf("%d%d%d", &m, &n, &e);
	int u, v;
	while(e--) {
		scanf("%d%d", &u, &v);
		ad[u].push_back(v);
	}
}

void Update(int v) {
	do {
		int u = Trace[v], vv = Left[u];
		Left[u] = v, Right[v] = u;
		v= vv;
	} while(v);
}

inline void Match(int u) {
	if(ok) return;
	int v;
	itr(int) it;
	IT(it, ad[u]) {
		if(Trace[v = *it]) continue;
		Trace[v] = u;
		if(!Right[v]) {
			Update(v);
			ok = true;
			return;
		}
		Match(Right[v]);
		if(ok) return;
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    FORU(u, 1, m) {
    	ok = false;
    	SET_ARR(Trace, 0);
    	Match(u);
    }
    int cnt = 0;
    FORU(u, 1, m) cnt += (Left[u] != 0);
    printf("%d\n", cnt);
}	