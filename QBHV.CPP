#include <bits/stdc++.h>

using namespace std;

#define TASK "QBHV"
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

const int N = 15;

char s[N];
int n;
int Fact[N];

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    Fact[0] = 1;
    FOR(i, 1, 9) Fact[i] = Fact[i - 1] * i;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    sort(s + 1, s + n + 1);
    int res = Fact[n], cnt = 0;
    FOR(i, 1, n + 1)
        if(s[i] != s[i - 1]) res /= Fact[cnt], cnt = 1;
        else cnt++;
    printf("%d\n", res);
    while(res--) {
        printf("%s\n", s+1);
        next_permutation(s + 1, s + n + 1);
    }
}
