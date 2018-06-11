#include <bits/stdc++.h>

using namespace std;

#define TASK "LIS"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define SC scanf
#define PR printf
#define X first
#define Y second
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
typedef pair<ll, int> ii;
typedef pair<ll,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

/* BINARY SEARCH */

namespace SOL1 {
    const int oo = INT_MAX;
    const int N = 3e4+4;

    int n;
    int a[N];
    int F[N], StartOf[N];
    int m;

    void INIT() {
        SC("%d", &n);
        FOR(i, 1, n) SC("%d", &a[i]);
        a[0] = -oo, a[n+1] = +oo;
        m = 1;
        F[n+1] = 1;
        StartOf[1] = n+1;
    }

    int BS(int i) {
        int L = 1, R = m+1, M;
        int j;
        do {
            M = (L+R)/2;
            j = StartOf[M];
            if(a[j] > a[i]) L = M; else R = M;
        } while(L+1 != R);
        return StartOf[L];
    }

    void DP() {
        int j, k;
        FORD(i, n, 0) {
            j = BS(i);
            k = F[j]+1;
            if(k > m) m = k, StartOf[k] = i;
            else
                if(a[StartOf[k]] < a[i]) StartOf[k] = i;
            F[i] = k;
        }
    }

    void MAIN() {
        INIT();
        DP();
        PR("%d", m-2);
    }
}

/* SEGMENT TREE */

namespace SOL2 {
    const int oo = 3e4+4;
    const int N = 3e4+4;

    int n;
    ll a[N];
    ii x[N];
    int MAX = 0;
    int Node[4 * N];
    int F[N];

    void INIT() {
        SC("%d", &n);
        FOR(i, 1, n) {
            SC("%lld", &x[i].X);
            x[i].Y = i;
        }
        sort(x + 1, x + n + 1);
        int cur, pre;
        FOR(i, 1, n) {
            cur = x[i].X;
            if(cur != pre || i == 1) x[i].X = ++MAX, pre = cur;
            else x[i].X = MAX;
        }
        FOR(i, 1, n) a[x[i].Y] = x[i].X;
        SET_ARR(Node, 0);
    }

    void UPDATE(int id, int L, int R, int i, int val) {
        if(i < L || i > R) return;
        Node[id] = max(Node[id], val);
        if(L == R) return;
        int M = (L + R) / 2;
        UPDATE(2 * id, L, M, i, val);
        UPDATE(2 * id + 1, M + 1, R, i, val);
    }

    int GET_MAX(int id, int L, int R, int u, int v) {
        if(v < L || u > R) return 0;
        if(u <= L && v >= R) return Node[id];
        int M = (L + R) / 2;
        return max(GET_MAX(id * 2, L, M, u, v), GET_MAX(id * 2 + 1, M + 1, R, u, v));
    }

    void MAIN() {
        INIT();
        FOR(i, 1, n) {
            F[a[i]] = GET_MAX(1, 1, MAX, 1, a[i] - 1) + 1;
            UPDATE(1, 1, MAX, a[i], F[a[i]]);
        }
        PR("%d", Node[1]);
    }
}

/* FENWICK TREE */ 

namespace SOL3 {
    const int oo = 3e4 + 4;
    const int N = 3e4 + 4;

    int n;
    ll a[N];
    ii x[N];
    int MAX = 0;
    int F[N];

    void INIT() {
        SC("%d", &n);
        FOR(i, 1, n) {
            SC("%lld", &x[i].X);
            x[i].Y = i;
        }
        sort(x + 1, x + n + 1);
        int cur, pre;
        FOR(i, 1, n) {
            cur = x[i].X;
            if(cur != pre || i == 1) x[i].X = ++MAX, pre = cur;
            else x[i].X = MAX;
        }
        FOR(i, 1, n) a[x[i].Y] = x[i].X;
    }

    void UPDATE(int p, int val) {
        for(int i = p; i <= n; i += i & -i) F[i] = max(F[i], val);
    }

    int GET_MAX(int p) {
        int ret = 0;
        for(int i = p; i; i -= i & -i) ret = max(ret, F[i]);
        return ret;
    }

    void MAIN() {
        INIT();
        FOR(i, 1, n) {
            F[a[i]] = GET_MAX(a[i] - 1) + 1;
            UPDATE(a[i], F[a[i]]);
        }
        int res = 0;
        FOR(i, 1, n) res = max(res, F[a[i]]);
        PR("%d", res);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    // SOL1::MAIN();
    // SOL2::MAIN();
    SOL3::MAIN();
}
