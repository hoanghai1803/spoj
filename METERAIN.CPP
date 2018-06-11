#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "METERAIN"
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
 
const int MAX_N = 5e3 + 3;

int n, m;
ll S = 0;

struct Point {
	int x, y;
	Point(int _x, int _y): x(_x), y(_y) {}
	Point() {}
} a[MAX_N];

inline ll Area(Point a, Point b, Point c) {
	Point vt1 = {b.x - a.x, b.y - a.y};
	Point vt2 = {c.x - a.x, c.y - a.y};
	return abs(1LL * vt1.x * vt2.y - 1LL * vt1.y * vt2.x);
}

inline bool Check(Point P) {
	ll s = 0;
	FORU(i, 0, n - 1) {
		if(Area(P, a[i], a[i + 1]) == 0) return false;
		s += Area(P, a[i], a[i + 1]);
	}
	return(s == S);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
	scanf("%d", &n);
	FORU(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
	a[0] = a[n];
	S = 0;
	FORU(i, 0, n - 1) S += 1LL * (a[i].x - a[i + 1].x) * (a[i].y + a[i + 1].y);
	S = abs(S);
	scanf("%d", &m);
	Point P;
	while(m--) {
		scanf("%d%d", &P.x, &P.y);
		if(Check(P)) printf("YES\n"); else printf("NO\n");
	}
}
