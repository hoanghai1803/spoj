#include <bits/stdc++.h>

using namespace std;

#define TASK "NKSGAME"
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

const int oo = INT_MAX;
const int N = 1e5 + 5;

int n;
int a[N], b[N];

void Init() {
    scanf("%d", &n);
    FORU(i, 1, n) scanf("%d", &a[i]);
    FORU(i, 1, n) {
        scanf("%d", &b[i]);
        b[i] *= -1;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
}

void Solve() {
    int res = +oo;
    int i = 1, j = 1;
    for(; i <= n && j <= n; i++) {
        for(; j <= n; j++) if(b[j] > a[i]) break;
        if(j == 1) res = min(res, abs(a[i] - b[j]));
        if(j > n) res = min(res, abs(a[i] - b[j - 1]));
        if(j > 1 && j <= n) res = min3(res, abs(a[i] - b[j]), abs(a[i] - b[j - 1]));
    }
    printf("%d", res);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Solve();
}