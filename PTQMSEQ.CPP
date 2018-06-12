#include <bits/stdc++.h>

using namespace std;

#define TASK "PTQMSEQ"
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

const int N = 1094800;

int n;
int a[2 * N];
ll S[2 * N], F[2*N];

deque<int> Deque;

void Init() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    FOR(i, n + 1, 2 * n) a[i] = a[i - n];
    n *= 2;
}

void DP() {
    FOR(i, 1, n) S[i] = S[i - 1] + a[i];
    F[1] = S[1];
    Deque.push_back(1);
    FOR(i, 2, n) {
        F[i] = S[i] - S[Deque.front()];
        if((i - Deque.front()) == n / 2 - 1) Deque.pop_front();
        while(Deque.size() > 0 && S[Deque.back()] > S[i]) Deque.pop_back();
        Deque.push_back(i);
    }
}

void Output() {
    ll res = LLONG_MIN;
    FOR(i, 1, n) res = max(res, F[i]);
    printf("%lld", res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    DP();
    Output();
}
