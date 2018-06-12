#include <bits/stdc++.h>

using namespace std;

#define TASK "NKREZ"
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

const int MAX_T = 3e4 + 4;
const int MAX_N = 1e4 + 4;

int n;
ii a[MAX_N + 1];
int F[MAX_T + 1];

inline int Get_Max(int p) {
    int ret = 0;
    for(int i = p; i; i -= i & -i) ret = max(ret, F[i]);
    return ret;
}

inline void Update(int p, int val) {
    for(int i = p; i < MAX_T; i += i & -i) F[i] = max(F[i], val);
}

inline bool CMP(ii a, ii b) {
    return(a.Y < b.Y);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FORU(i, 1, n) scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a + 1, a + n + 1, CMP);
    FORU(i, 1, n) {
        F[a[i].Y] = max(F[a[i].Y], Get_Max(a[i].X) + (a[i].Y - a[i].X));
        Update(a[i].Y, F[a[i].Y]);
    }
    int res = 0;
    FORU(i, 1, n) res = max(res, F[a[i].Y]);
    printf("%d", res);
}