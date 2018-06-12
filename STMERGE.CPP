#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "STMERGE"
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

const ll oo = 1e15;
const int N = 1e3 + 3;

int Q;
int m, n;
int c[N][N];
ll F[N][N][3];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &Q);
    while(Q--) {
	    scanf("%d%d", &m, &n);
	    FORU(i, 1, m)
	    	FORU(j, 1, n) scanf("%d", &c[i][j]);
	    FORU(i, 0, m)
	    	FORU(j, 0, n) F[i][j][1] = F[i][j][2] = +oo;
	   	FORU(i, 1, m) F[i][0][1] = 0;
	   	FORU(j, 1, n) F[0][j][2] = 0;
	    FORU(i, 1, m)
	    	FORU(j, 1, n) {
	    		F[i][j][1] = min(F[i - 1][j][2] + c[i][j], F[i - 1][j][1]);
	    		F[i][j][2] = min(F[i][j - 1][1] + c[i][j], F[i][j - 1][2]);
	    	}
	    printf("%lld\n", min(F[m][n][1], F[m][n][2]));
	}
}