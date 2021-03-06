#include <bits/stdc++.h>

using namespace std;

#define TASK "ADS"
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

const int N = 2e3+3;

int m, n;
int cnt = 0;
bool Free[N];

vector<int> ad[N];

void Init() {
    int u, v;
    scanf("%d%d", &n, &m);
    FORU(i, 1, m) {
        scanf("%d%d", &u, &v);
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    FORU(i, 1, n) Free[i] = true;
}

void Bfs(int s) {
    int u, v;
    itr(int) it;
    queue<int> Queue;
    Queue.push(s), Free[s] = false;
    while(Queue.size()) {
        u = Queue.front(), Queue.pop();
        IT(it, ad[u]){
            if(!Free[v = *it]) continue;
            Queue.push(v);
            Free[v] = false;
        }
    }
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    FORU(u, 1, n)
        if (Free[u]) cnt++, Bfs(u);
    printf("%d", m - n + cnt);
}