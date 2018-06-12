#include <bits/stdc++.h>

using namespace std;

#define TASK "QMAX"
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

const int N = 5e4 + 4;

int n, m, q;
int a[N];
int Node[4 * N];

int Init(int id, int L, int R) {
    if(L == R) {
        Node[id] = a[L];
        return Node[id];
    }
    int M = (L + R) >> 1;
    Node[id] = max(Init(2 * id, L, M), Init(2 * id + 1, M + 1, R));
    return Node[id];
}

int Get_max(int id, int L, int R, int u, int v) {
    if(L > v || R < u) return 0;
    if(L >= u && R <= v) return Node[id];
    int M = (L + R) >> 1;
    return max(Get_max(2 * id, L, M, u, v), Get_max(2 * id + 1, M + 1, R, u, v));
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &n, &m);
    int u, v, k;
    while(m--) {
        scanf("%d%d%d", &u, &v, &k);
        a[u] += k, a[v + 1] -= k;
    }
    FORU(i, 1, n) a[i] += a[i - 1];
    Init(1, 1, n);
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", Get_max(1, 1, n, u, v));
    }
}