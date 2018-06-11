#include <bits/stdc++.h>

using namespace std;

#define TASK "MTWALK"
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
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<double,double> dd;
typedef pair<double,dd> ddd;

const int N = 1e2 + 2;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int h[N][N];
bool a[N][N];
bool Visited[N][N];

inline bool Valid(int i, int j) {
    return(i && i <= n && j && j <=n);
}


inline bool Bfs() {
    SET_ARR(Visited, false);
    int i, j;
    queue<ii> Queue;
    Queue.push(ii(1, 1));
    while(Queue.size()) {
        i = Queue.front().ST, j = Queue.front().ND;
        Queue.pop();
        int u, v;
        FOR(d, 0, 3) {
            u = i + dx[d], v = j + dy[d];
            if(!Valid(u, v)) continue;
            if(Visited[u][v] || !a[u][v]) continue;
            if(u == n && v == n) return true;
            Queue.push(ii(u, v));
            Visited[u][v] = true;
        }
    }
    return false;
}

inline bool Check(int d) {
    FOR(k, 0, 110 - d) {
        if(h[1][1] < k || h[1][1] > k + d) continue;
        FOR(i, 1, n)
            FOR(j, 1, n) a[i][j] = (h[i][j] >= k && h[i][j] <= k + d);
        if(Bfs()) return true;
    }
    return false;
}

inline void BS(int L, int R) {
    if(L + 1 == R) {
        if(Check(L)) printf("%d", L); else printf("%d", R);
        exit(0);
    }
    int M = (L + R) >> 1;
    if(Check(M)) BS(L, M); else BS(M, R);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FOR(i, 1, n)
        FOR(j, 1, n) scanf("%d", &h[i][j]);
    BS(0, 110);
}