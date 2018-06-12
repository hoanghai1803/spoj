#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "SPSEQ"
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
 
const int MAX_N = 1e5 + 5;

int n;
int a[MAX_N];
int Max = 0;
ii b[MAX_N];
int fen1[MAX_N], fen2[MAX_N];
int LIS[MAX_N], LDS[MAX_N];

void Init() {
	scanf("%d", &n);
	FORU(i, 1, n) {
		scanf("%d", &b[i].X);
		b[i].Y = i;
	}
	sort(b + 1, b + n + 1);
	int pre = 0;
	FORU(i, 1, n)
		if(b[i].X == pre) b[i].X = Max;
		else pre = b[i].X, b[i].X = ++Max;
	FORU(i, 1, n) a[b[i].Y] = b[i].X;
}

inline void Update(int p1, int val1, int p2, int val2) {
	for(int i = p1; i <= Max; i += i & -i) fen1[i] = max(fen1[i], val1);
	for(int i = p2; i <= Max; i += i & -i) fen2[i] = max(fen2[i], val2);
}

inline ii Get(int p1, int p2) {
	int ret1 = 0, ret2 = 0;
	for(int i = p1; i; i -= i & -i) ret1 = max(ret1, fen1[i]);
	for(int i = p2; i; i -= i & -i) ret2 = max(ret2, fen2[i]);
	return ii(ret1, ret2);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    int i = 1, j = n;
    while(i <= n) {
    	ii tmp = Get(a[i] - 1, a[j] - 1);
    	LIS[i] = fen1[a[i]] = tmp.X + 1; 
    	LDS[j] = fen2[a[j]] = tmp.Y + 1;
    	Update(a[i], fen1[a[i]], a[j], fen2[a[j]]);
    	i++, j--;
    }
    int res = 0;
    FORU(i, 1, n) res = max(res, 2 * min(LIS[i], LDS[i]) - 1);
    printf("%d", res);
}