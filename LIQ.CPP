#include <bits/stdc++.h>

using namespace std;

#define TASK "LIQ"
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

const int oo = INT_MAX;
const int N = 1e4 + 4;

int n;
int a[N], F[N];

void Init() {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    a[0] = -oo, a[n + 1] = +oo;
    F[0] = 1;
}

void DP() {
    FOR(i, 1, n + 1) {
        F[i] = 1;
        FORD(j, i - 1, 0)
            if (a[i] > a[j]) F[i] = max(F[i], F[j] + 1);
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Init();
    DP();
    printf("%d", F[n + 1] - 2);
}
