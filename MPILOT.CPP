#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "MPILOT"
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
 
const int N = 1e4 + 4;

int n;
int x[N], y[N];
int F[N][N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FORU(i, 1, n) scanf("%d%d", &x[i], &y[i]);
    F[1][1] = y[1];
    FORU(i, 2, n) {
        F[i][0] = F[i - 1][1] + x[i];
        F[i][i] = F[i - 1][i - 1] + y[i];
        FORU(j, 1, i - 1) F[i][j] = min(F[i - 1][j - 1] + y[i], F[i - 1][j + 1] + x[i]);
    }
    printf("%d", F[n][0]);
}