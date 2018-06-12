#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "QMAX2"
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
const int MAX_N = 5e4 + 4;

struct Nodes {
    int lazy;
    int val;
} Node[MAX_N * 4];

void Propagation(int id) {
    int t = Node[id].lazy;
    Node[id * 2].lazy += t, Node[id * 2].val += t;
    Node[id * 2 + 1].lazy += t, Node[id * 2 + 1].val += t;
    Node[id].lazy = 0;
}

void Update(int id, int L, int R, int u, int v, int val) {
    if(L > v || R < u) return;
    if(L >= u && R <= v) {
        Node[id].val += val;
        Node[id].lazy += val;
        return;
    }
    Propagation(id);
    int M = (L + R) >> 1;
    Update(id * 2, L, M, u, v, val);
    Update(id * 2 + 1, M + 1, R, u, v, val);
    Node[id].val = max(Node[id * 2].val, Node[id * 2 + 1].val);
}

int Get_max(int id, int L, int R, int u, int v) {
    if(L > v || R < u) return -oo;
    if(L >= u && R <= v) return Node[id].val;
    Propagation(id);
    int M = (L + R) >> 1;
    return max(Get_max(id * 2, L, M, u, v), Get_max(id * 2 + 1, M + 1, R, u, v));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    int n, m;
    scanf("%d%d", &n, &m);
    int id, x, y, v;
    while(m--) {
        scanf("%d", &id);
        if(!id) {
            scanf("%d%d%d", &x, &y, &v);
            Update(1, 1, n, x, y, v);
        }
        else {
            scanf("%d%d", &x, &y);
            printf("%d\n", Get_max(1, 1, n, x, y));
        }
    }
}