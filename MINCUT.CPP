#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "MINCUT"
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

int m, n, k;
int a[N][N];
ll h[N][N], l[N][N];
ll D[N], S[N];

void Init() {
	scanf("%d%d%d", &m, &n, &k);
	FORU(i, 1, m)
		FORU(j, 1, n) {
			scanf("%d", &a[i][j]);
			h[i][j] = h[i - 1][j] + a[i][j];
			l[i][j] = l[i][j - 1] + a[i][j];
		}            
}                   
                  
ll Calc(int x, int y, int u, int v) {
	ll ret = +oo;
	S[x - 1] = 0;  
	FORU(i, x, u) {
		D[i] = l[i][v] - l[i][y - 1];
		S[i] = S[i - 1] + D[i];
	}            
	FORU(i, x, u) ret = min(ret, abs(2 * S[i] - S[u]));
	S[y - 1] = 0;  
	FORU(j, y, v) {
		D[j] = h[u][j] - h[x - 1][j];
		S[j] = S[j - 1] + D[j];
	}               
	FORU(j, y, v) ret = min(ret, abs(2 * S[j] - S[v]));
	return ret;     
}                   
                    
int main() {        
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif       
    Init();     
    int x, y, u, v;
    while(k--) {
    	scanf("%d%d%d%d", &x, &y, &u, &v);
    	printf("%lld\n", Calc(x, y, u, v));
    }           
}               