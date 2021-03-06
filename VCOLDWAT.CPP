#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "VCOLDWAT"
#define input_file TASK".INP"
#define output_file TASK".OUT"
 
#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();++i)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();++i)
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

const int N = 1e5 + 5;

int n, c;
ii Children[N];
int F[N];

void Init() {
    scanf("%d%d", &n, &c);
    int e, u, v;
    while(c--) {
        scanf("%d%d%d", &e, &u, &v);
        Children[e] = ii(u, v);
    }
    F[1] = 1;
}

inline void Dfs(int u) {
    if(!Children[u].X) return;
    F[Children[u].X] = F[Children[u].Y] = F[u] + 1;
    Dfs(Children[u].X);
    Dfs(Children[u].Y);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Dfs(1);
    FORU(u, 1, n) printf("%d\n", F[u]);
}