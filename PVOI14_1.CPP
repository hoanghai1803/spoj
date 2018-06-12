#include <bits/stdc++.h>
 
using namespace std;
 
#define TASK "PVOI14_1"
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
#define FOR(i,a,b,d) for (int i=(a); i!=(b); i+=(d))
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
 
const ll oo = LLONG_MAX;

int main() {
    #ifndef ONLINE_JUDGE
        freopen(input_file, "r", stdin);
        freopen(output_file, "w", stdout);
    #endif
    int n;
	scanf("%d", &n);
	ll E1 = -oo, E2 = -oo, E3 = +oo, E4 = +oo;
	ll xA, yA, xB, yB, xC, yC, xD, yD;
	ll e1, e2, e3, e4;
	while(n--) {
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD);
		e1 = xA - yA * (xA - xB) / (yA - yB);
		e2 = xB - yB * (xB - xC) / (yB - yC);
		e3 = xC - yC * (xC - xD) / (yC - yD);
		e4 = xD - yD * (xD - xA) / (yD - yA);
		if((xA - xB) * (yA - yB) < 0) swap(e1, e2), swap(e3, e4);
		if(e1 > e3) swap(e1, e3);
		if(e2 > e4) swap(e2, e4);
		if(e3 - e1 == 1 || e4 - e2 == 1) {
			printf("0");
			return 0;
		}
		if(e1 >= E3 - 1 || e3 <= E1 + 1 || e2 >= E4 - 1 || e4 <= E2 + 1) {
			printf("0");
			return 0;
		}
		E1 = max(E1, e1), E2 = max(E2, e2), E3 = min(E3, e3), E4 = min(E4, e4);
	}
	ll d1 = E3 - E1 - 1, d2 = E4 - E2 - 1;
	if(!(d1 & 1) || !(d2 & 1)) printf("%lld", 1LL * d1 * d2 / 2);
	else {
		int a = d1 / 2, b = d1 - a;
		int c = d2 / 2, d = d2 - c;
		if(!(E1 & 1) && !(E2 & 1)) printf("%lld", 1LL * a * c + 1LL * b * d);
		if(!(E1 & 1) && (E2 & 1)) printf("%lld", 1LL * a * d + 1LL * b * c);
		if((E1 & 1) && !(E2 & 1)) printf("%lld", 1ll * a * d + 1LL * b * c);
		if((E1 & 1) && (E2 & 1)) printf("%lld", 1LL * a * c + 1LL * b * d);
	} 
}