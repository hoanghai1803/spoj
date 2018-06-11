#include <bits/stdc++.h>

using namespace std;

#define TASK "HELPPM"
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

const int N = 5e2 + 2;
const int oo = N * N;

int m, n, k;
int a[N][N];
int d[N][N];
int S[N];
int res = +oo;
int x, y, z, t;

void Init() {
    scanf("%d%d%d", &m, &n, &k);
    FORU(i, 1, m) 
        FORU(j, 1, n) {
            scanf("%d", &a[i][j]);
            d[i][j] = d[i][j - 1] + a[i][j];
        }
}

void Try(int L, int  R) {
    FORU(i, 1, m) S[i] = S[i - 1] + d[i][R] - d[i][L - 1];
    int j = 1;
    FORU(i, 1, m) {
        for(; j <= m; j++) 
            if(S[j] - S[i - 1] >= k) break;
        if(j > m) break;
        if((R - L + 1) * (j - i + 1) < res) {
            res = (R - L + 1) * (j - i + 1);
            x = i, y = L, z = j, t = R;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Init();
    FORU(L, 1, n)
        FORU(R, L, n) Try(L, R);
    if(res == +oo) printf("-1");
    else {
        printf("%d\n", res);
        printf("%d %d %d %d", x, y, z, t);
    }
}