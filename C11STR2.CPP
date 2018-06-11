#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "C11STR2"
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
 
const ll MOD = 1e9 + 7;
const int MAX_N = 1e5 + 5;

char a[MAX_N], b[MAX_N];
ll Pow[MAX_N + 1];
ll Hash[3][MAX_N];

inline ll GetHash(int id, int i, int j) {
	if(i > j) return 0;
	return (Hash[id][j] - Hash[id][i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    Pow[0] = 1;
    FORU(i, 1, MAX_N) Pow[i] = Pow[i - 1] * 26 % MOD;
    scanf("%s%s", a + 1, b + 1);
    int m = strlen(a + 1), n = strlen(b + 1);
    FORU(i, 1, m) Hash[1][i] = (Hash[1][i - 1] * 26 + a[i] - 'a') % MOD;
    FORU(i, 1, n) Hash[2][i] = (Hash[2][i - 1] * 26 + b[i] - 'a') % MOD;
    int i = min(m, n);
    for(; ; --i) 
    	if(GetHash(1, m - i + 1, m) == GetHash(2, 0, i)) break; 
    printf("%s%s", a + 1, b + i + 1);
}