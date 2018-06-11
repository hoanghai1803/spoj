#include <bits/stdc++.h>

using namespace std;

#define TASK "MINK"
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
#define abs(x) ((x)>0?(x):-(x))
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 17e3 + 3;

int T, n, k;
int a[N];
int APM[N];

void Solve() {
    a[n + 1] = 0;
    deque<int> Deque;
    Deque.push_back(1);
    FOR(i, 2, n + 1) {
        APM[i - 1] = a[Deque.front()];
        if((i - k) == Deque.front()) Deque.pop_front();
        while(Deque.size() > 0 && a[Deque.back()] > a[i]) Deque.pop_back();
        Deque.push_back(i);
    }
    FOR(i, k, n) printf("%d ", APM[i]);
    printf("\n");
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        FOR(i, 1, n) scanf("%d", &a[i]);
        Solve();
    }
}
