#include <bits/stdc++.h>

using namespace std;

#define TASK "LINEGAME"
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

const int N = 1e6 + 6;

int n;
int a[N];
ll F[N][2][2];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i]);
    F[2][0][0] = 0, F[2][0][1] = a[1], F[2][1][0] = a[2], F[2][1][1] = a[1] - a[2];
    FOR(i, 3, n) {
    	F[i][0][0] = max(F[i - 1][0][0], F[i - 1][1][1]);
    	F[i][0][1] = max(F[i - 1][0][1], F[i - 1][1][0]);
    	F[i][1][0] = max(F[i - 1][0][0], F[i - 1][1][1]) + a[i];
    	F[i][1][1] = max(F[i - 1][0][1], F[i - 1][1][0]) - a[i];
    }  
    if(n == 1) printf("%d", max(a[1], 0));
    else {
    	ll res = F[n][0][0];
    	FOR(i, 0, 1)
    		FOR(j, 0, 1) res = max(res, F[n][i][j]);
    	printf("%lld", res);
    }
}