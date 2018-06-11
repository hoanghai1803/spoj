#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "HEAP1"
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

const int MAX_N = 5e4 + 4;

int T, n;
ll a[MAX_N];

MIN_HEAP(ll) Heap;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    scanf("%d", &T);
    while(T--) {
    	while(Heap.size()) Heap.pop();
    	scanf("%d", &n);
    	FORU(i, 1, n) {
    		scanf("%lld", &a[i]);
    		Heap.push(a[i]);
    	}
    	ll x, y;
    	ll res = 0;
    	while(Heap.size() > 1) {
    		x = Heap.top(); Heap.pop();
    		y = Heap.top(); Heap.pop();
    		res += x + y;
    		Heap.push(x + y);
    	}
    	printf("%lld\n", res);
    }
}