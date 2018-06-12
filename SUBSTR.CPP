#include <bits/stdc++.h>

using namespace std;

#define TASK "SUBSTR"
#define input_file TASK".INP"
#define output_file TASK".OUT"

#define ST first
#define ND second
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

const ll M = 1e9 + 9;
const int N = 1e6 + 6;
const int Base = 26;

char A[N], B[N];
ll Pow[N];
ll HashA[N];

int GetHash(int i, int j) {
	return(HashA[j] - HashA[i - 1] * Pow[j - i + 1] + M * M) % M;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%s%s", A + 1, B + 1);
    int m = strlen(A + 1), n = strlen(B + 1);
    Pow[0] = 1;
    FOR(i, 1, m) Pow[i] = (Pow[i - 1] * Base) % M;
    FOR(i, 1, m) HashA[i] = (HashA[i - 1] * Base + A[i] - 'a') % M;
    ll HashB = 0;
    FOR(i, 1, n) HashB = (HashB * Base + B[i] - 'a') % M;
    FOR(i, 1, m - n + 1)
    	if(HashB == GetHash(i, i + n - 1)) printf("%d ", i);
}