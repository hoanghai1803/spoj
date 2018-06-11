#include <bits/stdc++.h>

using namespace std;

#define TASK "LEM3"
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

const int oo = 2e5;
const int N = 20;
const int M = 1 << 20;

int n, m;
int c[N][N];
int F[N][M];
int res;
int b[N];

void Init() {
	scanf("%d", &n);
	FORU(i, 1, n) 
		FORU(j, 1, n) scanf("%d", &c[i][j]);
	m = (1 << n) - 1;
}

bool Get_bit(int n, int i) {
	return (n >> (i - 1)) & 1;
}

int Turn_off(int n, int i) {
	return n & ~(1 << (i-1));
}

void DP() {
	FORU(u, 1, n)
		FORU(Stt, 0, m) F[u][Stt] = +oo;
	FORU(u, 1, n) F[u][1 << (u-1)] = 0;
	FORU(Stt, 1, m) {
		SET_ARR(b, 0);
		int k = 0;
		FORU(u, 1, n)
			if(Get_bit(Stt, u) && Stt != (1 << (u - 1))) b[++k] = u;
		FORU(i, 1, k) {
			int u = b[i];
			int PreStt = Turn_off(Stt, u);
			FORU(j, 1, k)
				if(i != j) F[u][Stt] = min(F[u][Stt], F[b[j]][PreStt] + c[b[j]][u]);
		}
	}
	res = +oo;
	FORU(u, 1, n) res = min(res, F[u][m]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    DP();
    printf("%d", res);
}