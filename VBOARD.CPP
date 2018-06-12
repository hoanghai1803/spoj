#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "VBOARD"
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
 
const int MAX_N = 5e2 + 2;

int n, q;
int a[MAX_N][MAX_N];
int S[MAX_N][MAX_N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FORU(i, 1, n)
    	FORU(j, 1, n) {
    		scanf("%d", &a[i][j]);
    		if((i + j) & 1) a[i][j] *= -1;
    		S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + a[i][j];
    	}
    scanf("%d", &q);
    int x, y, u, v;
    while(q--) {
    	scanf("%d%d%d%d", &x, &y, &u, &v);
        int res = S[u][v] - S[u][y - 1] - S[x - 1][v] + S[x - 1][y - 1];
        printf("%d\n", abs(res));
    }
}