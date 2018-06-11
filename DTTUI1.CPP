#include <bits/stdc++.h>

using namespace std;

#define TASK "DTTUI1"
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

const int N = 44;
const int NN = 1e7;

int n, M;
int w[N], v[N];
ii F[NN], x[NN];
int Max[NN];
bool stt[N];
int h = 0, k = 1;
int res = 0;

void Try1(int i) {
	if(i > n / 2) {
		int W = 0, V = 0;
		FORU(i, 1, n / 2) 
			if(stt[i]) W += w[i], V += v[i];
		if(W > M) return;
		F[++h] = ii(W, V);
		return;
	}
	FORU(j, 0, 1) {
		stt[i] = j;
		Try1(i + 1);
	}
}

void BS(int L, int R, int W, int V) {
	if(L + 1 == R) {
		if(x[R].X <= W) {
			res = max(res, V + Max[R]);
			return;
		}
		res = max(res, V + Max[L]);
		return;
	}
	int M = (L + R) / 2;
	if(x[M].X > W) BS(L, M, W, V);
	else BS(M, R, W, V);
}

void Try2(int i) {
	if(i > n) {
		int W = 0, V = 0;
		FORU(i, n / 2 + 1, n)
			if(stt[i]) W += w[i], V += v[i];
		if(W > M) return;
		BS(1, k, M - W, V);
		return;
	}
	FORU(j, 0, 1) {
		stt[i] = j;
		Try2(i + 1);
	}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &n, &M);
    FORU(i, 1, n) scanf("%d%d", &w[i], &v[i]);
    Try1(1);
    sort(F + 1, F + h + 1);
    x[1] = F[1];
    FORU(i, 2, h) {
    	k += (F[i].X > F[i-1].X);
    	x[k] = F[i];
    }
    FORU(i, 1, k) 
    	Max[i] = max(Max[i - 1], x[i].Y);
    Try2(n / 2 + 1);
    printf("%d", res);
}