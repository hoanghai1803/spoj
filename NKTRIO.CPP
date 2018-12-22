#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "NKTRIO"
#define input_file TASK".INP"
#define output_file TASK".OUT"
 
#define X first
#define Y second
#define itr(t) vector<t>::iterator
#define ritr(t) vector<t>::reverse_iterator
#define IT(i,v) for (i=v.begin();i!=v.end();++i)
#define RIT(i,v) for (i=v.rbegin();i!=v.rend();++i)
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

const int N = 1e3 + 3;

int n;
int win[N][N];
int deg_out[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FORU(i, 1, n)
    FORU(j, 1, n) {
        scanf("%d", &win[i][j]);
        if(win[i][j]) deg_out[i]++;
    }
    FORU(i, 1, n)
    FORU(j, 1, n) {
        if(!win[i][j]) continue;
        if(deg_out[i] > deg_out[j]) continue;
        FORU(k, 1, n) if(win[j][k] && win[k][i]) {
            printf("%d %d %d", i, j, k);
            return 0;
        }
    }
    printf("-1 -1 -1");
}