#include <bits/stdc++.h>

using namespace std;

#define TASK "KAGAIN"
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
#define abs(x) ((x)>0?(x):-(x))
#define max3(a,b,c) max((a),max((b),(c)))
#define min3(a,b,c) min((a),min((b),(c)))
#define SET_ARR(a,v) memset(a,v,sizeof(a))
#define ALL(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 3e4 + 4;

int T, n;
int a[N];
int L[N], R[N];  

void Solve() {
    stack<int> Stack;
    Stack.push(0);
    FOR(i, 1, n) {
        while(Stack.size() > 1 && a[Stack.top()] >= a[i]) Stack.pop();
        L[i] = Stack.top();
        Stack.push(i);
    }
    while(Stack.size()) Stack.pop();
    Stack.push(n + 1);
    FORD(i, n, 1) {
        while(Stack.size() > 1 && a[Stack.top()] >= a[i]) Stack.pop();
        R[i] = Stack.top();
        Stack.push(i);
    }
    int Max = 0, Lmax = n + 1, Rmax = 0;
    FOR(i, 1, n)
        if( (R[i] - L[i] - 1) * a[i] > Max || ( (R[i] - L[i] - 1) * a[i] == Max && L[i] < Lmax) ) {
            Max = (R[i]-L[i]-1) * a[i];
            Lmax = L[i], Rmax = R[i];
        }
    printf("%d %d %d \n", Max, Lmax + 1, Rmax - 1);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file,"r",stdin);
        freopen(output_file,"w",stdout);
    #endif
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        FOR(i, 1, n) scanf("%d", &a[i]);
        Solve();
    }
}
