#include <bits/stdc++.h>

using namespace std;

#define TASK "QBBISHOP"
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

const int N = 2e3 + 2;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {-1, 1, 1, -1};

int n, m;
int p, q, s, t;
bool Obs[N][N];
bool Visited[N][N];
int F[N][N];

queue<ii> Queue;

void Init() {
    scanf("%d%d", &n, &m);
    scanf("%d%d%d%d", &p, &q, &s, &t);
    if(((p + q) & 1) != ((s + t) & 1)) {
        printf("-1");
        exit(0);
    }
    if(!m) {
        if((p - q == s - t) || (p + q == s + t)) printf("1"); else printf("2");
        exit(0);
    }
    Visited[p][q] = true;
    int u, v;
    while(m--) {
        scanf("%d%d", &u, &v);
        Obs[u][v] = true;
    }
}

inline bool Valid(int i, int j) {
    return (i && i <= n && j && j <= n);
}

inline void Sweep(int x, int y, int d) {
    int u = x, v = y;
    while(1) {
        u += dx[d], v += dy[d]; 
        if(!Valid(u, v) || Obs[u][v]) break;
        if(Visited[u][v]) continue;
        Visited[u][v] = true;
        F[u][v] = F[x][y] + 1;
        Queue.push(ii(u, v));
    }
}

void Bfs() {
    int u, v;
    Queue.push(ii(p, q));
    while(Queue.size()) {
        u = Queue.front().ST, v = Queue.front().ND;
        Queue.pop();
        FOR(d, 0, 3) Sweep(u, v, d);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Bfs();
    if(Visited[s][t]) printf("%d", F[s][t]); else printf("-1");
}