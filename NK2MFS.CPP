#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NK2MFS"
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

int n, h, k;
int a[N], b[N];
int x[N], y[N];

bool CMP1(int x, int y) {
	return(a[x] < a[y]);
}

bool CMP2(int x, int y) {
	return(b[x] > b[y]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FORU(i, 1, n) scanf("%d", &a[i]);
    FORU(i, 1, n) scanf("%d", &b[i]);
    h = k = 0;
    FORU(i, 1, n)
    	if(a[i] <= b[i]) x[++h] = i;
    	else y[++k] = i;
    sort(x + 1, x + h + 1, CMP1);
    sort(y + 1, y + k + 1, CMP2);
    copy(y + 1, y + k + 1, x + h + 1);
	int ta = 0, tb = 0;
	FORU(i, 1, n) {
		ta += a[x[i]];
		if(ta >= tb) tb = ta + b[x[i]];
		else tb += b[x[i]];
	}
	printf("%d\n", tb);
	FORU(i, 1, n) printf("%d ", x[i]);
}