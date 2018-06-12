#include <bits/stdc++.h>

using namespace std;

#define TASK "PBCSEQ"
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

const int oo = INT_MAX;
const int N = 1e5 + 5;

int n;
ii a[N];
int m;
int F[N];
int StartOf[N];

void Init() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d%d", &a[i].X, &a[i].Y);
		a[i].X *= -1;
	}
	sort(a + 1, a + n + 1);
	a[0].Y = -oo, a[n + 1].Y = +oo;
	m = 1;
	F[n + 1] = 1;
	StartOf[1] = n + 1;
}

inline int BS(int i, int L, int R) {
    if(L + 1 == R) return StartOf[L];
    int M = (L + R) >> 1;
    if(a[StartOf[M]].Y >= a[i].Y) return BS(i, M, R);
    return BS(i, L, M);
}

void DP() {
    int j, k;
    FORD(i, n, 0) {
        j = BS(i, 1, m + 1);
        k = F[j] + 1;
        if(k > m) m = k, StartOf[k] = i;
        else
            if(a[StartOf[k]].Y < a[i].Y) StartOf[k] = i;
        F[i] = k;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    DP();
    printf("%d", m - 2);
}