#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "KPLANK"
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
 
const int MAX_N = 1e6 + 6;

int n;
int h[MAX_N];
int L[MAX_N], R[MAX_N];

stack<int> Stack;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &n);
    FORU(i, 1, n) scanf("%d", &h[i]);
    Stack.push(0);
    FORU(i, 1, n) {
    	while(Stack.size() > 1 && h[Stack.top()] >= h[i]) Stack.pop();
    	L[i] = Stack.top();
    	Stack.push(i);
    }
    while(Stack.size()) Stack.pop();
    Stack.push(n + 1);
    FORD(i, n, 1) {
    	while(Stack.size() > 1 && h[Stack.top()] >= h[i]) Stack.pop();
    	R[i] = Stack.top();
    	Stack.push(i);
    }
    int res = 0;
    FORU(i, 1, n) 
    	if(h[i] <= R[i] - L[i] - 1) res = max(res, min(R[i] - L[i] - 1, h[i]));
    printf("%d", res);
}