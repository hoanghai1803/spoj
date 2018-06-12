#include <bits/stdc++.h>

using namespace std;

#define TASK "VECTOR"
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

const int N = 35;
const int M = 3e3 + 3;

int n;
ii Vt[N]; 
int U, V;
bool stt[N];
int F[2 * M][2 * M];
ll res = 0;

void Init() {
    scanf("%d", &n);
    FORU(i, 1, n) scanf("%d%d", &Vt[i].X, &Vt[i].Y);
    scanf("%d%d", &U, &V);
    if(U > M || V > M) {
    	printf("0");
    	exit(0);
    }
}

inline int Id(int x) {
	return x + M;
}

inline void Try1(int i, int f) {
	if(i > f) {
		int u = 0, v = 0;
		FORU(i, 1, f) 
			if(stt[i]) u += Vt[i].X, v += Vt[i].Y;
		F[Id(u)][Id(v)]++;
		return;
	}
	FORU(j, 0, 1) {
		stt[i] = j;
		Try1(i + 1, f);
	}
}

inline void Try2(int i, int f) {
	if(i > f) {
		int u = 0, v = 0;
		FORU(i, n / 2 + 1, n)
			if(stt[i]) u +=  Vt[i].X, v += Vt[i].Y;
		res += F[Id(U - u)][Id(V - v)];
		return;
	}
	FORU(j, 0, 1) {
		stt[i] = j;
		Try2(i + 1, f);
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Try1(1, n / 2);
    Try2(n / 2 + 1, n);
    printf("%lld", res);
}