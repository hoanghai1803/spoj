#include <bits/stdc++.h>

using namespace std;

#define TASK "QBGAME"
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

const ll oo = 8e12;
const int N = 1e4 + 4;
const int NN = 10;
const int M = (1 << 8) - 1;

int n;
ll a[NN][N];
int m;
int b[M];
ll F[N][M];
ll res;

inline bool Get_bit(int n, int i) {
	return (n >> (i - 1)) & 1;
}

void Init() {
	scanf("%d", &n);
	ll Max = -oo;
	FORU(i, 1, 8)
		FORU(j, 1, n) {
			scanf("%lld", &a[i][j]);
			Max = max(Max, a[i][j]);
		}
	if(Max < 0) {
		printf("%d", Max);
		exit(0);
	}
	m = 0;
	FORU(Stt, 0, M) {
		bool chk = true;
		FORU(i, 1, 7)
			if(Get_bit(Stt, i) && Get_bit(Stt, i+1)) chk = false;
		if(chk) b[++m] = Stt;
	}
}

void DP() {
	FORU(col, 1, n) {
		FORU(j, 1, m)
			FORU(k, 1, m) {
				if(b[j] & b[k]) continue;
				int PreStt = b[j], Stt = b[k];
				ll tmp = F[col-1][PreStt];
				FORU(i, 1, 8)
					if(Get_bit(Stt, i)) tmp += a[i][col]; 
				F[col][Stt] = max(F[col][Stt], tmp);
			}
	}
	res = -oo;
	FORU(i, 1, m) res = max(res, F[n][b[i]]);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    DP();
    printf("%lld", res);
}