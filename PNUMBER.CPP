#include <bits/stdc++.h>

using namespace std;

#define TASK "PNUMBER"
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
#define FOR(i,a,b) for (long long i=(a); i<=(b); i++)
#define FORD(i,a,b) for (long long i=(a); i>=(b); i--)
#define abs(x) ((x)>0?(x):-(x))
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int a, b;

bool Check(int n) {
    if(n == 2 || n == 3) return true;
    if(n == 1 || !(n & 1) || !(n % 3)) return false;
    int i = -1, k = floor(sqrt(n));
    do {
        i += 6;
        if(!(n % i) || !(n % (i + 2))) break;
    } while(i <= k);
    if(i > k) return true;
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &a, &b);
    while(++a <= b)
        if(Check(a - 1)) printf("%d\n", a - 1);
}
