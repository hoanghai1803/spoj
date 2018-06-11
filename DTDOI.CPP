#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "DTDOI"
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

const int oo = INT_MAX;
const int MAX_N = 1e2 + 2;
const int MAX_V = 1e5 + 5;

int n, S;
int v[MAX_N];
int F[MAX_N][MAX_V];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &n, &S);
    int Max = 0;
    FORU(i, 1, n) { 
    	scanf("%d", &v[i]);
    	Max = max(Max, v[i]);
    }
    int res = 0;
    if(S >= MAX_V) {
    	res = ceil((double)(S - MAX_V) / Max);
    	S -= res * Max;
    }
    FORU(j, 1, S) F[0][j] = +oo;
    FORU(i, 1, n)
    	FORU(j, 1, S) {
    		F[i][j] = F[i - 1][j];
    		if(j >= v[i]) F[i][j] = min(F[i][j], F[i][j - v[i]] + 1);
    	}
    printf("%d", res + F[n][S]);
}