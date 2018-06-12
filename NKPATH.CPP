#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKPATH"
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
 
const int MOD = 1e9;
const int MAX_N = 1e2 + 2;

int m, n;
int a[MAX_N][MAX_N];
int F[MAX_N][MAX_N];

inline int GCD(int a, int b) {
	return (!b) ? a : GCD(b, a % b);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &m, &n);
    FORU(i, 1, m)
    	FORU(j, 1, n) scanf("%d", &a[i][j]);
    FORU(i, 1, m) F[i][1] = 1;
    FORU(i, 1, m)
    	FORU(j, 1, n)
    		FORU(x, i, m)
    			FORU(y, j, n) 
    				if(j < n && i + j < x + y && GCD(a[i][j], a[x][y]) != 1)
    					F[x][y] = (F[x][y] + F[i][j]) % MOD;
    int res = 0;
    FORU(i, 1, m) res = (res + F[i][n]) % MOD;
    printf("%d", res);
}