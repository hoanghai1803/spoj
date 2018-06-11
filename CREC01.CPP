#include <bits/stdc++.h>

using namespace std;

#define TASK "CREC01"
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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 1e3 + 3;

int m, n;
char s[N][N];
int h[N], L[N];
ll F[N];
ll cnt = 0;

void Sweep(int i) {
    FOR(j, 1, n) h[j] = (h[j] + s[i][j] - '0') * (s[i][j] - '0');
    stack<int> Stack;
    Stack.push(0);
    FOR(j, 1, n) {
        while(Stack.size() > 1 && h[Stack.top()] >= h[j]) Stack.pop();
        L[j] = Stack.top();
        Stack.push(j);
    }
    FOR(j, 1, n) F[j] = h[j] * (j * 1LL - L[j]) + F[L[j]], cnt += F[j];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d%d", &m, &n);
    FOR(i, 1, m) scanf("%s", s[i] + 1);
    FOR(i, 1, m) Sweep(i); 
    printf("%lld", cnt);
}
