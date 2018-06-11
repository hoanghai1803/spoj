#include <bits/stdc++.h>

using namespace std;

#define TASK "DHSERV"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define ST first
#define ND second
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
typedef pair<int,ll> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

const ll oo = 1e12 + 2;
const int N = 5e2 + 2;

int n, m, k;
ll c[N][N];

void Init() {
    scanf("%d%d%d", &n, &m, &k);
    FOR(u, 1, n)
        FOR(v, 1, n)
            if(u == v) c[u][v] = 0;
            else c[u][v] = +oo;
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        scanf("%lld", &c[u][v]);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    int id;
    int x, y;
    while(k--) {
        scanf("%d", &id);
        if(id == 1) {
            scanf("%d", &x);
            itr(ii) it;
            FOR(u, 1, n)
                FOR(v, 1, n)
                    c[u][v] = min(c[u][v], c[u][x] + c[x][v]);
        }
        else {
            scanf("%d%d", &x, &y);
            if(c[x][y] == +oo) printf("-1\n"); 
            else printf("%lld\n", c[x][y]);
        }
    }
}