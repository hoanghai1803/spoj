#include <bits/stdc++.h>

using namespace std;

#define TASK "BINPACK"
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
const int M = 5e3 + 3;

int W, n;
int a[N];
ii F[N][M];
int cnt = 2, res = N;
int x = 0, y = 0;

inline void Try(int i) {
	if(i > n) {
		res = min(res, cnt);
		return;
	}
	FORU(j, 0, 1) {
		if(!j) {
			if(x + a[i] <= W) {
				x += a[i];
				Try(i + 1);
				x -= a[i];
			}
			else {
				int tmp = x;
				x = a[i], cnt++;
				Try(i + 1);
				x = tmp, cnt--;
			}
		}
		else {
			if(y + a[i] <= W) {
				y += a[i];
				Try(i + 1);
				y -= a[i];
			}
			else {
				int tmp = y;
				y = a[i], cnt++;
				Try(i + 1);
				y = tmp, cnt--;
			}
		}
	}
}

template <class T>
	void Get_min(T &a, T b) {
		a = min(a, b);
	}

int DP() {
    FORU(i, 1, n)
	FORU(j, 0, W) F[i][j] = ii(N, M);
    F[1][a[1]] = ii(2, 0);
    F[1][0] = ii(2, a[1]);
	FORU(i, 1, n - 1) 
	FORU(j, 0, W) {
		if(F[i][j] == ii(N, M)) continue;
		if(j + a[i + 1] <= W) Get_min(F[i + 1][j + a[i + 1]], F[i][j]);
		Get_min(F[i + 1][a[i + 1]], ii(F[i][j].X + 1, F[i][j].Y));
		if(F[i][j].Y + a[i + 1] <= W) Get_min(F[i + 1][j], ii(F[i][j].X, F[i][j].Y + a[i + 1]));
		Get_min(F[i + 1][j], ii(F[i][j].X + 1, a[i + 1]));
	}
	int ret = N;
	FORU(i, 1, W) Get_min(ret, F[n][i].X);
	return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d%d", &W, &n);
    if(W > M) {
    	FORU(i, 1, n) scanf("%d", &a[i]);
    	Try(1);
    	printf("%d", res);
    	return 0;
    }
    if(n > N) {
    	int tmp, S = 0;
    	FORU(i, 1, n) {
    		scanf("%d", &tmp);
    		S += tmp;
    	}
    	int res = S / W + (S % W != 0);
    	printf("%d", res);
    	return 0;
    }
    FORU(i, 1, n) scanf("%d", &a[i]);
    printf("%d", DP());
}