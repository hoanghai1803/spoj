#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKBRACKE"
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
const int MAX_N = 1e5 + 5;

int n, m;
char s[MAX_N];
int a[MAX_N];

struct Nodes {
	int sum;
	int min;
	int lazy;
} Node[MAX_N * 4];

inline void Propagation(int id, int L, int R) {
	int t = Node[id].lazy;
	int M = (L + R) >> 1;
	if(L == M) Node[id * 2].sum += t;
    Node[id * 2].min += t, Node[id * 2].lazy += t; 
    if(M + 1 == R) Node[id * 2 + 1].sum += t; 
    Node[id * 2 + 1].min += t, Node[id * 2 + 1].lazy += t;
    Node[id].lazy = 0;
}

inline void Update(int id, int L, int R, int i, int val) {
    if(R < i) return;
    if(L == R) Node[id].sum += val;
    if(L >= i) {
        Node[id].min += val;
        Node[id].lazy += val;
        return;
    }
    Propagation(id, L, R);
    int M = (L + R) >> 1;
    Update(id * 2, L, M, i, val);
    Update(id * 2 + 1, M + 1, R, i, val);
    Node[id].min = min(Node[id * 2].min, Node[id * 2 + 1].min);
}

inline int Get_sum(int id, int L, int R, int i) {
	if(!i) return 0;
	if(L > i || R < i) return 0;
	if(L == R) return Node[id].sum;
	Propagation(id, L, R);
	int M = (L + R) >> 1;
	return(i <= M) ? Get_sum(id * 2, L, M, i) : Get_sum(id * 2 + 1, M + 1, R, i);
}

inline int Get_min(int id, int L, int R, int u, int v) {
	if(L > v || R < u) return +oo;
	if(L >= u && R <= v) return Node[id].min;
	Propagation(id, L, R);
	int M = (L + R) >> 1;
	return min(Get_min(id * 2, L, M, u, v), Get_min(id * 2 + 1, M + 1, R, u, v));
}

inline int Check(int i, int j) {
	if(Get_sum(1, 1, n, j) - Get_sum(1, 1, n, i - 1) != 0) return 0;
	if(Get_min(1, 1, n, i, j) - Get_sum(1, 1, n, i - 1) < 0) return 0;
	return 1;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    FORU(i, 1, n) {
        a[i] = (s[i] == '(') ? 1:-1;
        Update(1, 1, n, i, a[i]);
    }
    int id, i, j, x;
    string ch;
    while(m--) {
    	scanf("%d", &id);
    	if(!id) {
    		scanf("%d", &i);
    		cin >> ch;
    		x = (ch == "(") ? 1:-1;
    		Update(1, 1, n, i, x - a[i]);
    		a[i] = x;
    	}
    	else {
    		scanf("%d%d", &i, &j);
    		printf("%d", Check(i, j));
    	}
    }
}