#include <bits/stdc++.h>

using namespace std;

#define TASK "C11GAME2"
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

const int oo = INT_MAX;
const int N = 2e2+2;

int n;
int a[N], b[N];
int h = 0, k = 0;
int F[N][N][N];

void Init() {
	scanf("%d", &n);
	int tmp;
	FORU(i, 1, n) {
		scanf("%d", &tmp);
		if(tmp) a[++h] = tmp;
	}
	FORU(i, 1, n) {
		scanf("%d", &tmp);
		if(tmp) b[++k] = tmp;
	}
}

template <class T>
	void Get_max(T &a, T b) {
		if(b > a) a = b;
	}

void Solve() {
	FORU(i, 0, h)
		FORU(j, 0, k)
			FORU(x, 0, n - h) {
				if(!i && !j && !x) continue; 
				F[i][j][x] = -oo;
				if(i && j) Get_max(F[i][j][x], F[i - 1][j - 1][x] + a[i] * b[j]);
				if(x && j) Get_max(F[i][j][x], F[i][j - 1][x - 1]);
				if(i && (i + x - j)) Get_max(F[i][j][x], F[i - 1][j][x]);
				if(x && (i + x - j)) Get_max(F[i][j][x], F[i][j][x - 1]);
			}
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    Solve();
    printf("%d", F[h][k][n - h]);
}