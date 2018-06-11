#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "LITES"
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
 
const int MAX_N = 1e5 + 5;

int n, m;

struct Nodes {
	int val;
	int lazy;
} Node[MAX_N * 4];

void Propagation(int id, int L, int R) {
	if(!Node[id].lazy) return;
	int t = Node[id].lazy;
	int M = (L + R) / 2;
	Node[id * 2].val = M - L + 1 - Node[id * 2].val;
	Node[id * 2].lazy = (Node[id * 2].lazy + 1) % 2;
	Node[id * 2 + 1].val = R - M - Node[id * 2 + 1].val;
	Node[id * 2 + 1].lazy = (Node[id * 2 + 1].lazy + 1) % 2;
	Node[id].lazy = 0;
}

void Update(int id, int L, int R, int u, int v) {
	if(L > v || R < u) return;
	if(L >= u && R <= v) {
		Node[id].val = R - L + 1 - Node[id].val;
		Node[id].lazy = (Node[id].lazy + 1) % 2;
		return;
	}
	Propagation(id, L, R);
	int M = (L + R) / 2;
	Update(id * 2, L, M, u, v);
	Update(id * 2 + 1, M + 1, R, u, v);
	Node[id].val = Node[id * 2].val + Node[id * 2 + 1].val;
}

int Get_val(int id, int L, int R, int u, int v) {
	if(L > v || R < u) return 0;
	if(L >= u && R <= v) return Node[id].val;
	Propagation(id, L, R);
	int M = (L + R) / 2;
	return Get_val(id * 2, L, M, u, v) + Get_val(id * 2 + 1, M + 1, R, u, v);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    int id, u, v;
    while(m--) {
    	scanf("%d%d%d", &id, &u, &v);
    	if(!id) Update(1, 1, n, u, v);
    	else printf("%d\n", Get_val(1, 1, n, u, v));
    }
}